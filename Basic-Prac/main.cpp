#include <vector>
#include <iostream>

const int& getNextId()
{
    static int s_x{ 0 }; // note: variable is non-const
    ++s_x; // generate the next id
    return s_x; // and return a reference to it
}

class Example
{
public:
    int m_number;
    public:
        Example()
        {
            std::cout<<"Default Ctor Example\n";
        }

        Example(int number):m_number(number)
        {
            std::cout<<"Param Ctor Example\n";
        }

};


class Entity
{
public:
    Example m_example;
    const int m_n;
    Entity():m_n(1),m_example(2)
    {
        std::cout<<"Default Ctor Entity\n";

    }

    
};

class Student
{
private:
    int m_roll;
public:
    Student() =default;
    explicit Student(int roll):m_roll(roll)
    {
        //
    }
    Student(const Student &s)=default;

};


class Temp
{
public:
    int m_a;
    int m_b;
    Temp(int a, int b):m_a(a),m_b(b)
    {
        std::cout<<"Param Ctor\n";
    }

    // Temp(int a):m_a(a)
    // {
    //     std::cout<<"Param Ctor\n";
    // }

    Temp(const Temp& t):m_a(t.m_a), m_b(t.m_b)
    {
        std::cout<<"Copy Ctor\n";
    }

    void disp()
    {
        std::cout<<"a:"<<m_a<<"b:"<<m_b<<std::endl;
    }

};

void func(Temp T)
{
    T.disp();
}


class MyVector
{
public:
    std::vector<int> m_vec;

public:
    MyVector()=default;
    MyVector(const std::vector<int>& vec):m_vec(vec)
    {
        std::cout<<"Vector Created\n";
    }

    int &operator[](const int index)
    {
        return this->m_vec[index];
    }

    MyVector& operator=(const MyVector & vec)
    {
        std::cout<<"Assingement Called\n";
        this->m_vec=vec.m_vec;
        return *this;
    }

    int getLen() const
    {
        return this->m_vec.size();
    }
    void disp()
    {
        for(const auto &it:m_vec)
        {
            std::cout<<"val:"<<it;
        }
    }

};




class Animal
{
public:
    virtual void speak()
    {
        std::cout<<"???"<<std::endl;
    }
};


class Cat: public Animal 
{
public:
    void speak() override
    {
        std::cout<<"Meows"<<std::endl;
    }
};


class Dog: public Animal 
{
public:
    virtual void speak()
    {
        std::cout<<"Barks"<<std::endl;
    }
};

void funcAnimal(Animal* animal)
{
    Animal *ptr=dynamic_cast<Dog*>(animal);
    if(ptr)
    {
        ptr->speak();

    }
}


struct data
{
int x;
int y;
};


int main()
{
    // Entity en;
    // // en.m_n=100;

    // // func(1);

    // Temp t1(10,20);
    // t1.disp();
    // Temp t2(t1);
    // t2.disp();


    std::vector<int> v{1,2,3,4,5};

    MyVector vec(v);

    std::cout<<"\n\n";

    MyVector vec2=vec;  //copy ctor
    vec2=vec; //copy assignment

    Dog d;
    Cat c;
    Animal *dog=&d;
    Animal *cat=&c;

    funcAnimal(cat);

    int *ptr=new int[2];
    ptr[0]=1;
    ptr[1]=200;

    data *myData=reinterpret_cast<data*>(ptr);

    if(myData)
    {
        std::cout<<"x"<<myData->x<<"y:"<<myData->y<<std::endl;
    }

    int abc=1;
    const int *abcptr=&abc;

    *const_cast<int*>(abcptr)=2;
    std::cout<<"abc="<<abc<<std::endl;


    return 0;
}
