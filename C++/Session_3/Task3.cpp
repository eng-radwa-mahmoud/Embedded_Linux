                    /*******************************************************
                    *   Author: Radwa Mahmoud                              *
                    *   Date  : 18/9/2023                                  *
                    *   Task  : check if there is even number in array     *
                    *******************************************************/





#include <algorithm>
#include <array>
#include <iostream>


int main()
{

    int found = 0;
    std::array<int, 3> array = {5,11,9};
    for (auto i : array)
    {
        if (i%2 == 0)
        {
            found = 1;
            std::cout << "found an even number" << std::endl;
            break;
        }
    }
    if(found ==0)
    {
        std::cout << "no even number found" << std::endl;
    }

    return 0;
}



