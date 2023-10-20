#include <iostream>
#include <string>
#include <netinet/in.h>

class Server{

    private:
        int Port;
        sockaddr_in sockaddr;
        int sockfd; 
        int connection;

    public:
        Server(int Port);
        void Initialize( int Port);
        bool AcceptConnection();
        void RadData(std::stringstream &buf);
        std::string ParseHTTPPostRequest(std::stringstream & buffer);
        void CreateHTTPRespose(std::string response);

};