                    /*******************************************************
                    *   Author: Radwa Mahmoud                              *
                    *   Date  : 26/9/2023                                  *
                    *   Task  : Class to handle logs                       *
                    *******************************************************/


#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <regex>

class Log{
    private:
     std::vector<std::string> Logs = {};

    public:
        enum class LEVEL{
        INFO,
        WARNING,
        ERROR
        };


    
    void log(LEVEL level, std::string message);
    void dump(std::string filename) ;
    void clear(std::string filename) ;

};


void Log::log(LEVEL level, std::string message)
{
    switch (level) {
        case Log::LEVEL::INFO:
        {
            time_t t1 = std::time(0); 
            std::string now = ctime( &t1);
            now = std::regex_replace( now,
                                std::regex("\\r\\n|\\r|\\n"),
                                "");
            std::string total = now+": " + "INFO --> " + message+'\n';
            Logs.push_back(total);
            break;
        }
        case Log::LEVEL::WARNING:
        {
            std::chrono::system_clock::time_point p = std::chrono::system_clock::now();
            time_t t = std::chrono::system_clock::to_time_t(p);
            std::string now = ctime( &t);
            now = std::regex_replace( now,
                    std::regex("\\r\\n|\\r|\\n"),
                    "");
            std::string total = now+": " + "WARNING --> " + message+'\n';
            Logs.push_back(total);
            break;
        }
        case Log::LEVEL::ERROR:
        {
            std::chrono::system_clock::time_point p = std::chrono::system_clock::now();
            time_t t = std::chrono::system_clock::to_time_t(p);
            std::string now = ctime( &t);
            now = std::regex_replace( now,
                    std::regex("\\r\\n|\\r|\\n"),
                    "");
            std::string total = now+": " + "ERROR --> "+message+'\n';
           Logs.push_back(total);
            break;
        }
        default:
            break;
    }
}

void Log::dump(std::string filename)
{
     std::ofstream outputfile(filename, std::ios::app);
    for (auto i : Logs)
    {
            outputfile << i;
    }

    outputfile.close();
}

void Log::clear(std::string filename)
{
    Logs.clear();
    std::ofstream outputfile(filename);
    outputfile << "";
    outputfile.close();    

}

int main()
{
    Log logs;

    logs.log(Log::LEVEL::INFO, "Hello");
    logs.log(Log::LEVEL::ERROR, "World");
    logs.dump("file.txt");

    return 0;
}



