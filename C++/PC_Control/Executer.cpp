#include "Executer.hpp"


void Executer::ExecuteCommand(std::string command,std::string &responses)

{

    if (command == "firefox" || command == "calculator" || command == "gedit")
    {
            responses= "Command Executed";
            std::system((MapCommands[command]).c_str()) ;
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
                responses += buffer.data();
            }
            auto returnCode = pclose(pipe);

            std::cout << responses << std::endl;
            }



}