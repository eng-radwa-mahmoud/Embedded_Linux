
#include "Server.hpp"
#include <iostream>
#include <unistd.h> 
#include <sstream>
#include <vector>

Server::Server(int Port)
{
    this->Port = Port;
}

void Server::Initialize( int Port)
{
    this->Port = Port;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        std::cout << "Failed to create socket. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }

    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = INADDR_ANY;
    sockaddr.sin_port = htons(this -> Port);
    if (bind(sockfd, (struct sockaddr*)&sockaddr, sizeof(sockaddr)) < 0) {
        std::cout << "Failed to bind to port:" << this->Port <<" errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }
    if (listen(sockfd, 3) < 0) {
        std::cout << "Failed to listen on socket. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Server::RadData(std::stringstream &buf)
{
    char* chr;  
    auto bytesRead = read(connection, chr, 100);
    buf << chr;
    bytesRead = read(connection, chr, 100);
    buf << chr;     

}

bool Server::AcceptConnection()
{
    auto addrlen = sizeof(sockaddr);
    this -> connection = accept(sockfd, (struct sockaddr*)&sockaddr, (socklen_t*)&addrlen);
    if (connection < 0) {
        std::cout << "Failed to grab connection. errno: " << errno << std::endl;
        exit(EXIT_FAILURE);

    }
    return true;
}

std::string Server::ParseHTTPPostRequest(std::stringstream & buffer)
{
    std::string line;
    // parsing the headers
    while (getline(buffer, line, '\n')) {
        if (line.empty() || line == "\r") {
        break; // end of headers reached
        }
        if (line.back() == '\r') {
            line.resize(line.size()-1);
        }
    }
    std::string const body(std::istreambuf_iterator<char>{buffer}, {});

    std::stringstream ss(body);
    std::vector<std::string> tokens;
    std::string token;
    while (std::getline(ss, token, '\n')) {
    tokens.push_back(token);
    }
    std::cout << tokens[0] << std::endl;
    return tokens[0];
}

void Server::CreateHTTPRespose(std::string response)
{
    std::stringstream make_response;
    make_response << "HTTP/1.1 200 OK\r\n";
    make_response << "Content-Type: text/plain\r\n";
    make_response << "Content-Length: " << response.length()+2 << "\r\n";
    make_response << "\r\n";
    make_response << "R" << response.c_str() << "\n";
    send(this ->connection, make_response.str().c_str(), make_response.str().size(), 0) ;
    shutdown(this -> connection, true);
    close(this ->connection);
}