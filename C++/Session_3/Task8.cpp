                    /*******************************************************
                    *   Author: Radwa Mahmoud                              *
                    *   Date  : 25/9/2023                                  *
                    *   Task  : Backtrace program                          *
                    *******************************************************/


#include <iostream>
#include <string>
#include <vector>

class Backtrace {
    private:
        static std::vector<std::string> FuncEnter;
        static std::vector<std::string> FuncExit;
    public:
       static void EnterFunc(std::string FuncName);
       static void ExitFunc(std::string FuncName);
       static void ShowBackTRace();
    
};
std::vector<std::string> Backtrace::FuncEnter = {};
std::vector<std::string> Backtrace::FuncExit = {};

void Backtrace::EnterFunc(std::string FuncName)
{
    (Backtrace::FuncEnter).push_back(FuncName);
}

void Backtrace::ExitFunc(std::string FuncName)
{
    (Backtrace::FuncExit).push_back(FuncName);
}

void Backtrace::ShowBackTRace()
{
            for(auto i : Backtrace::FuncEnter)
        {
            std::cout<< "Enter: "<<i<<std::endl;
        } 
                    for(auto i : Backtrace::FuncExit)
        {
            std::cout<< "Exit: "<<i<<std::endl;
        } 
}


void func2 (){
   Backtrace::EnterFunc(__PRETTY_FUNCTION__);
   Backtrace::ExitFunc(__PRETTY_FUNCTION__);
}

void func (){
   Backtrace::EnterFunc(__PRETTY_FUNCTION__);
   func2();
   Backtrace::ExitFunc(__PRETTY_FUNCTION__);
}



int main(){
    Backtrace::EnterFunc(__PRETTY_FUNCTION__);
    func();
   Backtrace::ExitFunc(__PRETTY_FUNCTION__);
   Backtrace::ShowBackTRace();
}



