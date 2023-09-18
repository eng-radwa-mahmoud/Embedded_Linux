                    /****************************************
                    *   Author: Radwa Mahmoud               *
                    *   Date  : 17/9/2023                   *
                    *   Task  : delete number from array    *
                    ****************************************/



#include <algorithm>
#include <array>
#include <iostream>


int main()
{
    int num = 0;
    int found = 0;
    std::cout << "Enter the number you want to delete: " << std::endl;
    std::cin >> num;
    std::array<int, 20> array = {20,50,8,9,2};
    for(int i =0;i<20;i++)
    {
        if (array[i] == num)
        {
            found = 1;
            for(int x=i;x<=20;x++)
            {
                array[x] = array[x+1];
            }
        }
    }
    if(found == 1)
    {
        std::cout << "The number " << num << " is deleted from the array" << std::endl;
    }
    else {
       std::cout << "The number " << num << " is not in the array" << std::endl;
    }

    for(int i : array)
    {
        std::cout << i <<" ";
    }
    std::cout << std::endl;


}