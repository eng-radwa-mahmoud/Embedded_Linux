                    /************************************************************
                    *   Author: Radwa Mahmoud                                   *
                    *   Date  : 17/9/2023                                       *
                    *   Task  : lambda function to calculate number suare       *
                    ************************************************************/



#include <algorithm>
#include <array>
#include <iostream>


int main()
{
    int num = 0;
    std::cout << "Enter the number to calculate its square: " << std::endl;
    std::cin >> num;
    auto fun = [] (int num) {return num * num;};
    int square = fun(num);
    std::cout << "The square of " << num << " is " << square << std::endl;
    return 0;
}