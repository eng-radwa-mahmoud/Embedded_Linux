                    /*******************************************************
                    *   Author: Radwa Mahmoud                              *
                    *   Date  : 25/9/2023                                  *
                    *   Task  : create string class                        *
                    *******************************************************/





#include <algorithm>
#include <array>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>


class String{
    public:
        char* ptr = nullptr;
        int length = 0;
        /* copy constructor */
        String(const String& str )  
        {
            this -> length = str.length; 

            this -> ptr = new char [this -> length+1];

            for (int i =0; str.ptr[i] != '\0'; i++)
            {
               this -> ptr[i] = str.ptr[i];
            }
            this -> ptr[this -> length] = '\0';
        }
        /* copy assignment */
        String& operator=(const String& str)
        {
            if (this != &str)
            {
                if (this -> ptr ) {delete [] this -> ptr;}
                this -> length = str.length; 
                this -> ptr = new char [this -> length];

                for (int i =0; str.ptr[i]!= '\0'; i++)
                {
                   this -> ptr[i] = str.ptr[i];
                }
                this -> ptr[this -> length] = '\0';
            }
            return *this;
        }
        /* parameter constructor */
        String(const char (str)[])  
        {
            if (this->ptr)
            {
                delete[] this->ptr;
            }
            int size = 0;
            for (int i =0; str[i] != '\0'; i++)
            {
               size++;
            }
            ptr = new char [size+1];
            this -> length = size;

            for (int i =0; str[i] != '\0'; i++)
            {
               ptr[i] = str[i];
            }
            this -> ptr[this -> length] = '\0';
        }
        /* move constructor */
        String(String&& str)
        {
            if(this != &str)
            {
                this -> length = str.length; 
                this -> ptr = new char [this -> length];

                for (int i =0; str.ptr[i]!= '\0'; i++)
                {
                   this -> ptr[i] = str.ptr[i];
                }
                this -> ptr[this -> length] = '\0';
                str.ptr = nullptr;
                str.length = 0;
            }
        }
        /* move assignment */
        String& operator=(String&& str)
        {
            if (this!= &str)
            {
                if (this -> ptr ) {delete [] this -> ptr;}
                this -> length = str.length; 
                this -> ptr = new char [this -> length];

                for (int i =0; str.ptr[i]!= '\0'; i++)
                {
                   this -> ptr[i] = str.ptr[i];
                }
                this -> ptr[this -> length] = '\0';
                str.ptr = nullptr;
                str.length = 0;
            }
            return *this;
        }
        /* destructor */
        ~String()
        {
            if (this -> ptr ) {delete [] this -> ptr;}
        }
        
        char* data    (void);
        char* find    (char chr);
        int   size    (void);
        void  insert  (char chr);
        void  insert  ( char chr, int indx);
        void  clear   ();
        void  erase   (char chr);

};

int String::size()
{
    return this->length;
}

char* String::data(void)
{
    return this->ptr;
}

char* String::find(char chr)
{
    for (int i =0; this -> ptr[i]!= '\0'; i++)
    {
        if (this -> ptr[i] == chr)
        {
            return &this -> ptr[i];
        }
    }
    return nullptr;
}

void String::insert(char chr)
{
    if(this -> ptr)
    {
        char* new_ptr = new char [this -> length + 1];
        for (int i =0; this -> ptr[i]!= '\0'; i++)
        {
            new_ptr[i] = this -> ptr[i];
        }
        new_ptr[this -> length] = chr;
        new_ptr[this -> length + 1] = '\0';
        delete [] this -> ptr;
        this -> ptr = new_ptr;
        this -> length++;
    }
    else 
    {
        this -> ptr = new char[2];
        ptr[0] = chr;
        ptr[1] = '\0';
        this -> length = 1;
    }
}

void String::insert(char chr, int indx)
{
    if (indx <= this->length)
        {
        if(this -> ptr)
        {
            char* new_ptr = new char [this -> length + 1];
            for (int i =0; this -> ptr[i]!= '\0'; i++)
            {
                if (i == indx)
                {
                    new_ptr[i] = chr;
                }
                new_ptr[i] = this -> ptr[i];
            }
            new_ptr[this -> length] = chr;
            new_ptr[this -> length + 1] = '\0';
            delete [] this -> ptr;
            this -> ptr = new_ptr;
            this -> length++;
        }
        else 
        {
            this -> ptr = new char[2];
            ptr[0] = chr;
            ptr[1] = '\0';
            this -> length = 1;
        }
    }
    
}

void String::erase(char chr)
{
    int first = 0;
    char* new_ptr = new char [this -> length ];
    for (int i =0; this -> ptr[i]!= '\0'; i++)
    {
        if(first !=1 && this -> ptr[i] != chr)
        {
            new_ptr[i] = this -> ptr[i];
        }
        else {
            if (first == 0 )
            {
                new_ptr[i] = this -> ptr[i+1];
                first = 1;
            }
            else {
            new_ptr[i] = this -> ptr[i+1];
            }
        }
    }
    new_ptr[this -> length] = '\0';
    delete [] this -> ptr;
    this -> ptr = new_ptr;
    this -> length--;
}

void String::clear()
{
    this -> length = 0;
    if(this -> ptr)
    {
        delete [] this -> ptr;
        this -> ptr = nullptr;
    }
}

int main()
{
    String str("radwa");
    std::cout << str.size() << std::endl;
    std::cout << str.data() << std::endl;
    std::cout << str.find('a')[0] << std::endl;
    str.insert('a');
    std::cout << str.data() << std::endl;
    String str2(str);
    std::cout << str2.data() << std::endl;
    str2.insert('M');
    std::cout << str2.data() << std::endl;
    str2.erase('a');
    std::cout << str2.data() << std::endl;
    str2 = str;
    std::cout << str2.data() << std::endl;
    str2 = "radwa";
    std::cout << str2.data() << std::endl;

    return 0;
}



