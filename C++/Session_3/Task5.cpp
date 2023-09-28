                    /*******************************************************
                    *   Author: Radwa Mahmoud                              *
                    *   Date  : 18/9/2023                                  *
                    *   Task  : Handle interruot signle like (ctrl+c)      *
                    *******************************************************/



#include <unistd.h>
#include <iostream>
#include <signal.h>


// Define the function to be called when ctrl-c (SIGINT) is sent to process
void signal_callback_handler(int signum) {
   std::cout << "Caught signal --> interrupt signal --> " << signum << std::endl;
   // Terminate program
   exit(signum);
}
int main(){
   // Register signal and signal handler
   signal(SIGINT, signal_callback_handler);
   while(true){
      std::cout << "Program processing..." << std::endl;
      sleep(1);
   }
   return EXIT_SUCCESS;
}



