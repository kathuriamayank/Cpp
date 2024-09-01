#include <iostream>
#include <vector>



int main()
{
    const std::vector<int> nums{2,2,4,14,3,8,3,8,7,7};
    int Xor=0;
    for(const auto &num:nums)
    {
        Xor=Xor^num;
    }
    int setBit= (Xor & (Xor-1)) ^ Xor;    
    int b1=0,b2=0;

    for(const auto&num: nums)
    {
        if(num & setBit)
        {
            b1=b1 ^ num;
        }
        else
        {
            b2=b2^num;
        }
    }


    
    return 0;
}
