#include <initializer_list> 
#include "../utilities\utilities.h"
#include <vector>


void func(std::initializer_list<int> list)
{
    for(const auto&it:list)
    {
        UTILITIES::disp(it);
    }   
}

int main()
{
    std::initializer_list<int> list{1,2,3,4,5};

    for(const auto&it:list)
    {
        UTILITIES::disp(it);
    }


    std::cout<<"\n\n Another List\n";
    func({88,2,-1,0});

    std::cout<<"\n\n Vector\n";
    std::vector<int> v{list};
    for(const auto&it:v)
    {
        UTILITIES::disp(it);
    }
    return 0;
}
