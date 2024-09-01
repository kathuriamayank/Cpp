#include <iostream>
#include <string>



std::string getBinary(int num)
{
    std::string binary{""};
    while(num!=1)
    {
        int r=num%2;
        if(r==1)
            binary+='1';
        else
            binary+='0';
        
        num=num/2;
    }
    binary +='1';

    return std::string(binary.rbegin(),binary.rend());

}

int getDecimal(const std::string& binary)
{
    int decimal=0;
    int powTwo=1;

    std::string revBinary(binary.rbegin(),binary.rend());

    for(const auto &it:revBinary)
    {
        if(it=='1')
        {
            decimal+=powTwo;
        }

        powTwo*=2;
    }

    return decimal;
}

int main()
{
    int num=13;
    auto binary=getBinary(num);
    std::cout<<"Binary:"<<binary<<"\n";

    auto decimal=getDecimal(binary);
    std::cout<<"Decimal:"<<decimal<<"\n";



    std::cin.get();
    return 0;
}

