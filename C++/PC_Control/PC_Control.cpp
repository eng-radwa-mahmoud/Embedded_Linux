                    /*******************************************************
                    *   Author: Radwa Mahmoud                              *
                    *   Date  : 28/9/2023                                  *
                    *   Task  : Control PC from mobile                     *
                    *******************************************************/

#include <iostream>
#include <map>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h> 
#include <syscall.h>
#include <sstream>
#include <vector>

class Executer {
    private:
        std::map<std::string, std::string> MapCommands = {{"firefox","firefox"},{"calculator","gnome-calculator"},{"IP","hostname -I"}};

    public:
        void ExecuteCommand(std::string command, std::string &response);

};

void Executer::ExecuteCommand(std::string command,std::string &response)

{

    if (command == "firefox" || command == "calculator")
    {
        system((MapCommands[command]).c_str());
        response = "Command Executed";
    }  

    else {
            
            std::array<char, 128> buffer;
            

            std::cout << "Opening reading pipe" << std::endl;
            FILE* pipe = popen(MapCommands[command].c_str(), "r");
            if (!pipe)
            {
                std::cerr << "Couldn't start command." << std::endl;

            }
            while (fgets(buffer.data(), 128, pipe) != NULL) {
                std::cout << "Reading..." << std::endl;
                response += buffer.data();
            }
            auto returnCode = pclose(pipe);

            std::cout << response << std::endl;
            }



}

class Server{

    private:
        int Port;
        sockaddr_in sockaddr;
        int sockfd; 
        int connection;

    public:
        Server(int Port)
        {
            this->Port = Port;
        }
        void Initialize( int Port)
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
        bool AcceptConnection()
        {
            auto addrlen = sizeof(sockaddr);
            this -> connection = accept(sockfd, (struct sockaddr*)&sockaddr, (socklen_t*)&addrlen);
            if (connection < 0) {
                std::cout << "Failed to grab connection. errno: " << errno << std::endl;
                exit(EXIT_FAILURE);

            }
            return true;
        }
        void RadData(std::stringstream &buf)
        {
           char* chr;  
          auto bytesRead = read(connection, chr, 100);
          buf << chr;
          bytesRead = read(connection, chr, 100);
          buf << chr;     

        }

        std::string ParseHTTPPostRequest(std::stringstream & buffer)
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
        void CreateHTTPRespose(std::string response)
        {
          std::stringstream make_response;
          make_response << "HTTP/1.1 200 OK\r\n";
          make_response << "Content-Type: text/plain\r\n";
          make_response << "Content-Length: " << response.length()+2 << "\r\n";
          make_response << "\r\n";
          make_response << "R" << response.c_str() << "\n";
          send(this ->connection, make_response.str().c_str(), make_response.str().size(), 0) ;
          close(this ->connection);
        }
};


void Initialize(std::string IP, int Port, std::string)
{

}
void RadData(std::string Data);
void CreateHTTPRespose();


int main()
{
    Executer executer;
    Server server(8008);
    server.Initialize(8008);
    while(1){
        if(!server.AcceptConnection()){
        continue;;
        }
        
        std::stringstream buffer;

        server.RadData(buffer);
        std::string cmd = server.ParseHTTPPostRequest(buffer);
        
        std::string response;
        executer.ExecuteCommand(cmd, response);
        server.CreateHTTPRespose(response);
    }
    

}