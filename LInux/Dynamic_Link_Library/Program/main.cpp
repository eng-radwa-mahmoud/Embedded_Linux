                    /*******************************************************
                    *   Author: Radwa Mahmoud                              *
                    *   Date  : 20/10/2023                                  *
                    *   Task  : Control PC through mobile                  *
                    *******************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <signal.h>
#include <sys/wait.h>
#include <Executer.hpp>
#include <Server.hpp>


int main()
{
    Executer executer;
    Server server(8008);
    server.Initialize(8008);
    while(1)
    {
        if(!server.AcceptConnection()){
            continue;;
            }
        std::stringstream buffer;

        std::string response;
        server.RadData(buffer);
        std::string cmd = server.ParseHTTPPostRequest(buffer);

        executer.ExecuteCommand(cmd, response);

        server.CreateHTTPRespose(response);
    }
    

}