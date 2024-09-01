#include <iostream>
#include "Log.h"
#include <typeinfo>


class Animal
{
private:
    std::string m_speak;

public:
    Animal(std::string speak):m_speak(speak)
    {
        std::cout<<"PARAM CTOR Called\n";
    }

    Animal(const Animal& animal)
    {
        std::cout<<"COPY CTOR Called\n";
        m_speak=animal.m_speak;
    }

    void speak() const
    {
        std::cout<<this->m_speak<<std::endl;
    }
};


Animal getDog()
{
    Animal dog("barks");
    return dog;
}


template<typename T>
void disp(T var)
{
    std::cout<<"VAR:"<<var<<"\n";
}

int main()
{
    std::cout<<"Hello World\n";

    int x(3.2);
    disp(x);
    
    Log("main");

    std::cout<<"\n\n";
    // Animal dog{"barks"};
    // Animal dog2(dog);

    std::cout<<"\n\n";
    auto dog3(getDog());
    dog3.speak();


    return 0;
}
