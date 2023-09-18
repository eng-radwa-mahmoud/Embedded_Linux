                    /****************************************
                    *   Author: Radwa Mahmoud               *
                    *   Date  : 17/9/2023                   *
                    *   Task  : Search number in array      *
                    ****************************************/



#include <algorithm>
#include <array>
#include <iostream>


int main()
{
    int num = 0;
    while (1) {
    
    
    std::cout << "Enter the number you want to search: " << std::endl;
    std::cin >> num;
    std::array<int, 20> array = {20,50,8,9,2};
    if (std::find(array.begin(),array.end(),num) == array.end())
    {
        std::cout << "..." << num << " is not in the array..." <<  std::endl;
    }
    else {
        std::cout << "..." << num << " is in the array..." << std::endl;
    }
    }
}