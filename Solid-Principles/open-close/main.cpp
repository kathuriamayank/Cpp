#include <iostream>


class PaymentMethod
{
public:
    virtual void process()=0;
    virtual ~PaymentMethod()=default;

};


class DebitCard:public PaymentMethod
{
public:
    void process() override
    {
        std::cout<<"Debit Card Payment Method\n";
    }

    virtual ~DebitCard()=default;

};


class CreditCard:public PaymentMethod
{
public:
    void process() override
    {
        std::cout<<"Credit Card Payment Method\n";
    }

    virtual ~CreditCard()=default;
};


class PaymentProcessor final
{
public:
    void process(PaymentMethod& paymentmethod)
    {
        paymentmethod.process();
    }

};


int main()
{
    PaymentProcessor processor;
    CreditCard creditcard;
    DebitCard debitcard;

    processor.process(creditcard);
    processor.process(debitcard);

    return 0;
}
