#include <iostream>

class Shape
{
    public:
        virtual void color()const =0;
};


class Circle:public Shape
{
public:
    Circle()=default;
    void color() const override
    {
        std::cout<<"Color is Red\n";
    }

};


class A
{

public:
    A(int var):m_var(var)
    {
        std::cout<<"A Ctor\n";
    }

public:
    int m_var;

};


class B:public A
{

public:
    B(int var):A(var)
    {
        std::cout<<"B Ctor\n";
    }
};

class C:public A(var)
{

public:
    C(int var):B(var)
    {
        std::cout<<"C Ctor\n";
    }
};


int main()
{
    // Circle obj;
    const Shape &obj=Circle();
    // shape.color();
    obj.color();

    C cObj{10};
    std::cin.get();
    return 0;

}