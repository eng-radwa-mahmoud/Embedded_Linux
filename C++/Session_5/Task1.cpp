                    /*******************************************************
                    *   Author: Radwa Mahmoud                              *
                    *   Date  : 28/9/2023                                  *
                    *   Task  : create class draw and derived classes      *
                    *******************************************************/

#include <iostream>

class Drawing
{
    public:
        virtual void Draw() = 0;
};

class Square : public Drawing
{
    public:
        void Draw()
        {
            std::cout << "Drawing Square" << std::endl;
        }
};

class Circle : public Drawing
{
    public:
        void Draw()
        {
            std::cout << "Drawing Circle" << std::endl;
        }
};

class Triangle : public Drawing
{
    public:
        void Draw()
        {
            std::cout << "Drawing Triangle"<< std::endl;
        }
};


int main ()
{
    Square square;
    Circle circle;
    Triangle triangle;

    Drawing* VirtualPointer = &square;
    VirtualPointer -> Draw();
    VirtualPointer = &circle;
    VirtualPointer -> Draw();
    VirtualPointer = &triangle;
    VirtualPointer -> Draw();


}