                    /***********************************************
                    *   Author: Radwa Mahmoud                      *
                    *   Date  : 18/9/2023                          *
                    *   Task  : check if all the array is even     *
                    ***********************************************/





#include <algorithm>
#include <array>
#include <iostream>


int main()
{

    std::array<int, 7> array = {12,2,4};
    if (std::all_of(array.begin(), array.end(), [](int x) { return x % 2 == 0; }))
    {
        std::cout << "All the array is even" << std::endl;
    }
    else {
        std::cout << "Not all the array is even" << std::endl;
    }
   

    return 0;
}



