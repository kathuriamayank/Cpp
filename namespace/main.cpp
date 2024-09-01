#include "func.h"
#include <typeinfo>

namespace HelperFunc
{
    void printHello()
    {
        std::cout<<"Hello\n";
    }
}

enum Cricketers{
    SACHIN=0,
    KOHLI,
    MSD,
    PONTING
};

int main()
{
    HelperFunc::print("Yo");
    HelperFunc::printHello();

    int num=2;
    float num2=3.0f;
    int num3=static_cast<int>(num2);

    if(static_cast<int>(HelperFunc::Animal::COW)==num)
    {
        std::cout<<"Cow\n";
    }

    int temp=5;

    Cricketers val=KOHLI;

    std::cout<<"Cricketer is:"<<val<<std::endl;

}