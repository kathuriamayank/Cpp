#include <iostream>



class Array
{
private:
    int my_len;
    int *my_data;

public:

    Array(int len=10):my_len(len), my_data(new int[len])
    {
        //
    }
    int getLen() const
    {
        return this->my_len;
    }

    int& operator[](int i)
    {
        return dataCheck(i);
    }

    int& dataCheck(int i)
    {
        if(i>=0 or i<my_len)
        {
            return  this->my_data[i];
        }

    }
};

int main()
{
    int arr[5]{10,20,30,40,50};

    Array myArr()
    return 0;
}

