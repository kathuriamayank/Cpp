#include <array>
#include <iostream>

/*
https://cplusplus.com/reference/array/array/

std::array is a container that wraps around fixed size arrays. 
It also doesn't loose the information of its length when decayed to a pointer.

You know that when we pass an array (also known as C-style array) to a function, the address of the array gets passed to the function i.e. the pointer to the array gets passed to the function. Thus, the information about the size of the array gets lost.
To deal with such situations, we use std::array and std::vector.

Also could be retunred from the function.
Moreover the performance is similar,as it just a wrapper around the array.
Should be used for the cases, where there are less copies.

*/

template<typename T,std::size_t N>
void dispArray(const std::array<T,N>& arr)
{
    for(const auto& i: arr)
    {
        std::cout<<i<<" ";
    }
    std::cout<<"\n";
}



int main()
{
    std::cout<<"Array\n";

    // Creating the array
    std::array<int,10> arr1{33,2,1,99,2};
    dispArray(arr1);

    /*Capacity

    size and max_size of an array object always match
    std::priority_queue*size(): No of elements in an array
    *max_size(): Max no elements an array container can store.(size() and max_size() are same for an array.)
    *empty(): returns true if an array is empty otherwise false.
    */

    std::cout<<"The no of elementst are:"<<arr1.size()<<std::endl;
    std::cout<<"max_size:"<<arr1.max_size()<<std::endl;
    if(!arr1.empty())
    {
        std::cout<<"Array is not empty\n";
    }


    /*Accessing
    *front()
    *back()
    *[]
    *at()
    *data()
    */


    const int& first=arr1.front();
    const int& last=arr1.back();
    arr1[2]=-22;
    arr1.at(6)=77;
    int* ptr=arr1.data();
    ptr[1]=-99;
    dispArray(arr1);

    /*
    Iterators---> Same as Vectors
    */


    /*Member functions:
    *fill(Val): Sets the value as val for all the N elements of array.


    */

    std::array<int,10> arr2(arr1);
    dispArray(arr2);

    arr2.fill(11);
    dispArray(arr2);

    


    return 0;
}