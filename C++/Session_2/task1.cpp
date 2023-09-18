                    /****************************************
                    *   Author: Radwa Mahmoud               *
                    *   Date  : 17/9/2023                   *
                    *   Task  : Find max number in array    *
                    ****************************************/





#include <algorithm>
#include <iostream>
#include <array>

int ArraySize = 0;

int FindMaxNum(std::array<int,20> CopyArray)
{
    std::sort(CopyArray.begin(),CopyArray.end(),[](auto first, auto second) { return first > second; });
    return CopyArray[0];

}
int main()
{
    ArraySize = 5;
    std::array <int,20> array = {1,5,300,80,900};
    int MaxNUm = FindMaxNum(array);
    std::cout << MaxNUm << std::endl;
}