                    /***************************************************
                    *   Author: Radwa Mahmoud                          *
                    *   Date  : 17/9/2023                              *
                    *   Task  : find odd and even numbers in array     *
                    ***************************************************/



#include <algorithm>
#include <array>
#include <iostream>


int main()
{
    int num = 0;
    std::array<int, 5> array = {20,50,8,9,2};
    for (int i : array)
    {
        if (i%2 == 0)
        {
            std::cout << i << " is even" << std::endl;
        }
        else {
            std::cout << i << " is odd" << std::endl;
     
        }
    }

}