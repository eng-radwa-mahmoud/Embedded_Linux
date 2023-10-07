                    /*******************************************************
                    *   Author: Radwa Mahmoud                              *
                    *   Date  : 28/9/2023                                  *
                    *   Task  : Control PC from mobile                     *
                    *******************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <signal.h>
#include <sys/wait.h>
#include "Executer.hpp"
#include "Server.hpp"

void proc_exit(int sig_num)
{
    waitpid(0, 0, WNOHANG);
}





std::string response;

int main()
{
    signal (SIGCHLD, proc_exit);
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
    
        executer.ExecuteCommand(cmd, response);

        server.CreateHTTPRespose(response);
    }
    

}