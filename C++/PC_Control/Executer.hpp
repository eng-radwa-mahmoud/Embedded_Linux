#include <iostream>
#include <map>

class Executer {
    private:
        std::map<std::string, std::string> MapCommands = {{"firefox","firefox &"},{"calculator","gnome-calculator &"},{"IP","hostname -I"},{"gedit","gedit &"}};

    public:
        void ExecuteCommand(std::string command, std::string &response);

};
