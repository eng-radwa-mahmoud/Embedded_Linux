                    /*******************************************************
                    *   Author: Radwa Mahmoud                              *
                    *   Date  : 25/9/2023                                  *
                    *   Task  : find accumlated sum of array elements      *
                    *******************************************************/


#include <algorithm>
#include <iostream>
#include <array>
#include <numeric>


int main(){
    int sum = 0;
    std::array <int , 9> array = {1,2,3,4,5,6,7,8,9};
    sum = std::accumulate(array.begin(), array.end(),sum);
    std::cout << "the accumlated sum is: " << sum << std::endl;
}



