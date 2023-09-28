                    /*******************************************************
                    *   Author: Radwa Mahmoud                              *
                    *   Date  : 18/9/2023                                  *
                    *   Task  : create string class                        *
                    *******************************************************/





#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
#include <string>


class String{
    public:
        char str[100];
        int length = 0;
        String(const char str[])  
        {
            for (int i =0; str[i] != '\0'; i++)
            {
                this->str[i] = str[i];
                (this->length)++;
            }
        }
        void SetName(const char str[]);
        int GetLength(void);
        char* GetName(void);

};

void String::SetName(const char str[])
{

    strcpy(this->str, str);

    for (int i =0; str[i]!= '\0'; i++)
    {
        (this->length)++;
    }
}
int String::GetLength()
{
    return this->length;
}
char* String::GetName(void)
{
    return this->str;
}

int main()
{
    String str("Radwa");
    std::cout << str.GetName() << std::endl;
    std::cout << str.GetLength() << std::endl;
    str.SetName("Gehad");
    std::cout << str.GetName() << std::endl;
    return 0;
}



