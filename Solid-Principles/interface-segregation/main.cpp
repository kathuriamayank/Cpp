#include <iostream>


class IPrinter
{
public:
    virtual void print()=0;

};

class IScanner
{
public:
    virtual void scan()=0;    
};

class IFax
{
public:
    virtual void fax()=0;
};

class SimplePrinter: public IPrinter
{
public:
    void print() override
    {
        std::cout<<" I am a very basic printer!!!\n";
    }
};

class MultiFunctionPrinter: public IPrinter, public IScanner, public IFax
{
public:
    void print() override
    {
        std::cout<<"I am a complex printer!!!\n";
    }
    void scan() override
    {
        std::cout<<"I can scan for you!!!\n";
    }
    void fax() override
    {
        std::cout<<"I can fax for you!!!\n";

    }
};

int main()
{
    IScanner *scanner=new MultiFunctionPrinter();
    scanner->scan();
    return 0;
}


