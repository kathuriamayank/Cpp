#include <vector>
#include <iostream>
#include <tuple>

/*
https://cplusplus.com/reference/vector/vector/
*/


struct City
{
    std::string name;
    int population;

    City(std::string name,int pop):name(name),population(pop)
    {
        std::cout <<" Ctor\n";
    }

    City(const City& city)
    {
        std::cout <<" Copy Ctor\n";
        name=city.name;
        population= city.population;
    }

    friend std::ostream& operator<<(std::ostream& os, const City& city)
    {
        os <<city.name<<" "<<city.population;
        return os;    
    }
};

template<typename T>
void dispVector(const std::vector<T> &vec)
{
    for(const auto &it:vec)
    {
        std::cout<<it<<" ";
    }
    std::cout<<"\n";
}


int main()
{
    std::cout<<" Vector Class\n";
    std::vector<City> cities;
    cities.reserve(10);
    std::cout<<"cities.size():"<<cities.size()<<std::endl;

    // cities.push_back({"Delhi",999});
    // cities.push_back({"Jaipur",99});


    cities.emplace_back("Delhi",999);
    cities.emplace_back("Jaipur",99);

    std::cout<<"cities.size()"<<cities.size()<<std::endl;
    std::cout<<"cities.capacity()"<<cities.capacity()<<std::endl;


    // 1. Creating the vector

    std::vector<int> V;
    std::cout<<V.capacity()<<std::endl;     // capacity will be zero


    std::vector<int> v1{1,2,3,4};
    std::vector<int>v2(10); //(Creats the vector with 10 elements and default value 0)
    std::vector<int> v3(10,3);// Creates the vector with 10 elements and default value 3

    //Creating the vector v4 using other vector
    std::vector<int> v4(v3);
    
    dispVector(v1);
    dispVector(v2);
    dispVector(v3);
    dispVector(v4);
    std::cout<<"\n";


    /* 2. Capacity
    *size()---> No of elements in the vector
    *capacity()---> Storage space of the vector in terms of the number of elements.
    *max_size()----> Max no of elemenets vector can hold, but not a guarantee. It can still fail.
    *resize()---> Resizes the vectore(ie no of elements and sets the default value to 0) 
    *empty()----> returns if vector is empty
    *reserve(n)---> (Will only affect memory and not the size(i.e.: no of elemenets))
                Request to reserve the storage space for n elements.

    */

    std::cout<<v3.size()<<std::endl;
    std::cout<<v3.capacity()<<std::endl;
    std::cout<<v3.max_size()<<std::endl;
    std::cout<<"V3:\n";
    dispVector(v3);

    v3.resize(15);
    dispVector(v3);


    /*3. Accessing
    *[]---> will return ref to the value at that index
    *front()---> will return reference to the first element. Its the vector is empty, then the undefined behaviour. 
    *back()---> will return reference to the last  element, then the undefined behaviour.
    *at----> Same as [], but will show out of bounds exception if its out of bounds.
    *data()---> will return to the poiter to first element of the dynamic array
    */


    int &ele= v3[2];
    ele=999;
    dispVector(v3);

    int *ptr= v3.data();
    std::cout<<ptr[2]<<std::endl;


    /*4. Iterators:
    *begin() ----> Returns the iterator pointing to the first element of the vector.
    *end()
    *cbegin()
    *cend()-----> Returns the const iterator, pointing to the first element of the vector. const iterator cannot change the content of the vector.
    *rbegin()---> Returns the reverse iterator pointing to the last element of the vector.
    *rend()
    *crbegin()----> Return the const reverse iterator, pointing to the last of the vector. 
    *crend()
    */

   std::vector<int>::iterator it=v3.begin();
   std::vector<int>::const_iterator it2=v3.begin();

    *it=11;
//    *it2=11;   //Cannot change value of the const iterator
    dispVector(v3);

    std::vector<int>:: reverse_iterator itr3=v3.rbegin();
    std::cout<<*itr3<<std::endl;

    std::vector<int>::const_reverse_iterator itr4=v4.crbegin();
    // *itr4=0; //Cannot change value of the const iterator



    /* 5. Modifiers:
    *push_back(): Inserts the new element at the end of the vector.
    *emplace_back(): Constructs the elements using the arguments passed in place.
    We use emplace_back during the objects while we are creating, and push_back for the already created elements.
    *pop_back(): Deletes the last element from the vector.
    *clear(): Removes all the elements from the vector. Thus size becomes zero. However, the capacity will not change.
    *insert(iterator pos, ele): Inserts the element at the specified position
    *emplace(iterator pos, args): Constructs the object in place via tha arguments and then inserts this object at the end without any temp copies.
    *erase(iterator): removes the element at the specified iterator.
    * a.swap(b): as the name suggests, the contents of a and b gets swapped.
    */


   // Insert and Emplace
   dispVector(v3);
   v3.insert(v3.begin()+2,777);
   std::cout<<"Inserted\n";
   dispVector(v3);
   

   cities.emplace_back("Amritsar",100);
   dispVector<City>(cities);

    std::cout<<"Emplacing the City\n";
    cities.emplace(cities.begin(),"Mumbai",111);
    std::cout<<"Done\n";


    std::cout<<"Inserting the City\n";
    cities.insert(cities.begin(),City("Mumbai",111));
    std::cout<<"Done\n";
    

    dispVector(cities);
   


   // Erase
    cities.erase(cities.begin()+3);
    dispVector(cities);


    // Swapping
    std::cout<<"Before Swap:\n";
    std::cout<<"v3:\n";
    dispVector(v3);
    std::cout<<"v4:\n";
    dispVector(v4);

    v3.swap(v4);
    std::cout<<"After Swap:\n";
    std::cout<<"v3:\n";
    dispVector(v3);
    std::cout<<"v4:\n";
    dispVector(v4);
    


    //Clear
    std::cout<<"V3 Size\n";
   std::cout<<v3.size()<<std::endl;
   std::cout<<"V3 Capacity\n";
   std::cout<<v3.capacity()<<std::endl;

   v3.clear();
    
    std::cout<<"V3 Size\n";
   std::cout<<v3.size()<<std::endl;
   std::cout<<"V3 Capacity\n";
   std::cout<<v3.capacity()<<std::endl;


    std::tuple<bool,bool,int> myTuple(std::make_tuple(true,true,111));
    int valX= std::get<2>(myTuple);
    std::cout<<"valX:"<<valX<<std::endl;
    return 0;
}