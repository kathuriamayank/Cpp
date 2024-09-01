#include <iostream>


void func(int &x)
{
    std::cout<<"LValue:X"<<x<<std::endl;
}

void func(int &&x)
{
    std::cout<<"RValue:X"<<std::endl;
}

int& getVal()
{
    static int x=10;
    std::cout<<"X:"<<x<<std::endl;
    return x;
}


int main()
{
    const int &x=10;    
    func(5);

    const int &y=x;

    getVal()=121;
    getVal();
    std::cin.get();

    // int &a=x+1  (x+1 is rvalue);

    return 0;
}
