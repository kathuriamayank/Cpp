#include <iostream>
#include <string>

class Bird
{
public:
    virtual void eat()=0;
    virtual ~Bird()=default;
};


class FlyingBird :public Bird
{
public:
    virtual void fly()=0;
    virtual ~FlyingBird()=default;
};


class Penguin :public Bird
{
public:
    void eat() override
    {
        std::cout<<"A Penguin can eat!!! \n";
    }
    virtual ~Penguin()=default;
};

class Sparrow: public FlyingBird
{
public:
    void eat() override
    {
        std::cout<<"Sparrow is eating\n";
    }

    void fly() override
    {
        std::cout<<"Sparrow is flying\n";
    }
};


void makeBirdEat(Bird *bird)
{
    bird->eat();
}

void makeBirdFly(FlyingBird* bird)
{
    bird->fly();
}



int main()
{
    Bird * penguin= new Penguin();
    FlyingBird *sparrow= new Sparrow();

    penguin->eat();
    sparrow->eat();
    sparrow->fly();

    return 0;
}

