                    /****************************************
                    *   Author: Radwa Mahmoud               *
                    *   Date  : 17/9/2023                   *
                    *   Task  : Merge two arrays            *
                    ****************************************/



#include <algorithm>
#include <array>
#include <iostream>


int main()
{
    int num = 0;
    std::array<int, 20> array = {20,50,8,9,2};
    std::array<int, 20> array2 = {20,50,8,9,2};
    std::array<int, 40> array3;
    for(int i =0; i<array2.size()+array.size();i++)
    {
        if(i<array2.size())
        {
            array3[i] = array2[i];
        }
        else
        {
            array3[i] = array[i-array2.size()];
        }
    }

    for(int i : array3)
    {
        std::cout << i <<" ";
    }
    std::cout << std::endl;

}