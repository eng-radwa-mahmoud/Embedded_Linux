                    /*******************************************************
                    *   Author: Radwa Mahmoud                              *
                    *   Date  : 25/9/2023                                  *
                    *   Task  : fill array with 10 to 10000                *
                    *******************************************************/


#include <algorithm>
#include <iostream>
#include <array>


int main(){
    int x= 10;
    std::array <int , 9991> array = {};
    std::generate(array.begin(),array.end(),[&x](){return x++;});
    
    for (auto i: array)
    {  
        std::cout << i << " ";
    }
    std::cout << std::endl;
}



