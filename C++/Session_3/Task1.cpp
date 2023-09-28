                    /***********************************************
                    *   Author: Radwa Mahmoud                      *
                    *   Date  : 18/9/2023                          *
                    *   Task  : check if the character is digit    *
                    ***********************************************/





#include <algorithm>
#include <iostream>


int main()
{
    char x = 0;
    std::cout << "Enter the character: " << std::endl;
    std::cin >> x;
    if (isdigit(x))
    {
        std::cout << x << " is a digit" << std::endl;
    }
    else {
        std::cout << x << " is not a digit" << std::endl;
    }

}