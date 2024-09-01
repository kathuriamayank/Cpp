#include <algorithm>
#include <vector>
#include <iostream>
#include "../utilities\utilities.h"

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents=50):m_cents(cents)
    {
        //
    }

    int getCents() const
    {
        return m_cents;
    }

    // add Cents + Cents using friend function
    friend Cents operator+(const Cents& c1, const Cents&c2)
    {
        return Cents{c1.m_cents+ c2.m_cents};
    }

    friend Cents operator+(const Cents&c1, int c2)
    {
        return Cents{c1.m_cents+c2};
    }

    friend Cents operator+(int c2, const Cents&c1)
    {
        return Cents{c2+c1.m_cents};
    }


    friend std::ostream& operator<<(std::ostream &out,const Cents&c)
    {
        out<<c.m_cents<<":";
        return out;
    }

    friend std::istream& operator>>(std::istream &input, Cents &cents)
    {
        int centsVal;
        input>>centsVal;
        Cents obj{centsVal};
        cents= obj;
        return input;
    }

    /*
        Prefix Operator ++, because int argument is not provided.
    */
    Cents& operator++();
    /*
        Postfix operator ++, because int argument is being used.
    */
    Cents operator++(int);

    void operator()(int increment);

    void show() const
    {
        std::cout<<"Val:"<<m_cents<<std::endl;
    }
};


Cents& Cents::operator++()
{
    this->m_cents++;
    return *this;
}


Cents Cents::operator++(int)
{
    Cents temp{*this};
    ++(*this);
    return temp;
}


void Cents::operator()(int increment)
{
    this->m_cents+=increment;
}


class Matrix
{
private:
    int m_arr[10][10]{};
public:
    int& operator()(int i,int j)
    {
        return m_arr[i][j];
    }

    // Clear the matrix
    void operator()()
    {
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                m_arr[i][j]=0;
            }
        }
    }
};

class Increment
{
private:
    int m_increment;
public:
    Increment(int increment=0):m_increment{increment}
    {
        //
        std::cout<<"Increment:"<<m_increment<<std::endl;
    }

    int operator()(int num)
    {
        std::cout<<"operator:"<<num<<std::endl;
        return m_increment+num;
    }
    
};


class MyArray
{
private:
    int m_arr[5];
public:
    MyArray():m_arr{1,2,3,4,5}
    {
        //
    }

    int& operator[](int index)
    {
        return m_arr[index];
    }

    friend std::ostream& operator<<(std::ostream& output, MyArray&arr)
    {
        for(int i=0; i<5; i++)
            output<<arr.m_arr[i]<<":";
        std::cout<<"\n";
        return output;
    }
};

int main()
{
    std::cout<<"Hello World\n";

    Cents c1{100}, c2{200};
    auto c3=c1+c2;
    c3.show();

    auto c4=c3+100;
    c4.show();

    auto c5=200+c4;
    c5.show();

    std::cout<<c1<<c2<<c3<<c4<<c5<<"\n";

    UTILITIES::disp(c1);

    std::cout<<"-----c6------\n";
    Cents c6;
    std::cin>>c6;
    UTILITIES::disp(c6);

    ++c6;
    UTILITIES::disp(c6);
    std::cout<<c6<<std::endl;

    std::cout<<"Post Incementing:"<<c6++<<std::endl;
    UTILITIES::disp(c6);


    c6(100);
    std::cout<<"Overloaded ()\n";
    UTILITIES::disp(c6);


    std::vector<int> nums{1,2,3,4,5};
    std::vector<int> result;
    result.resize(nums.size());


    std::transform(nums.begin(),nums.end(),result.begin(),Increment(100));
    // std::transform(nums.begin(),nums.end(),result.begin(),[](int inc){
    //     return inc+100;
    // });

    
    for(const auto &i:result)
    {
        std::cout<<"i:"<<i;
    }

    std::cout<<std::endl;

    Matrix matrix;
    matrix(1,2)=111;
    std::cout<<matrix(1,2)<<std::endl;

    std::cout<<"Clearing the Matrix!!\n";
    matrix();
    std::cout<<matrix(1,2)<<std::endl;


    std::cout<<"MY Array\n";
    MyArray array;
    std::cout<<array;
    array[4]=101;
    std::cout<<array[4]<<std::endl;
    std::cout<<array;

    return 0;
}
