#include <map>
#include <iostream>
#include <vector>
#include<unordered_map>
#include <functional>

/*
TODO:
lower_bound() and upper_bound()

https://stackoverflow.com/questions/33236038/when-i-should-use-stdmapat-to-retrieve-map-element
[] vs .at()

*if the key is not found for the []:, then that key gets inserted in the map
* where as if key is not found then it does not gets inserted and raise an exception.
* Hence we cannot use [] with the const map, and we should use .at() for it.


**Map vs Unordered Map:
https://stackoverflow.com/questions/13799593/how-to-choose-between-map-and-unordered-map

find() returns an iterator to the element if it exists or an iterator to map::end() if it does not
*/

struct CityRecord
{
    std::string name;
    int pop;
    double latitude,longitude;

    CityRecord()=default;

    CityRecord(std::string name,float pop,double latitude, double longitude):name(name),pop(pop),latitude(latitude),longitude(longitude)
    {
        //
    }
};


void disp(const std::map<std::string,CityRecord> &cityMap)
{
    for(const auto &it:cityMap)
    {
        std::cout<<it.second.name<<":"<<it.second.pop<<std::endl;
    }
}


int main()
{
    std::cout<<"Hello World\n";

    std::vector<CityRecord> cities;
    cities.emplace_back("Delhi",1000,1.4,2.6);
    cities.emplace_back("Agra",2000,1.4,2.6);
    cities.emplace_back("Bangalore",3000,1.4,2.6);
    cities.emplace_back("Mumbai",4000,1.4,2.6);
    

    for(const auto&city:cities)
    {
        std::cout<<city.name<<" "<<city.pop<<std::endl;
    }
    std::cout<<"\n\n";

    /*
        Map
        Note: the key for map(or unordered map) should be such that elements could be sorted.
        that is they can be comparated less than or greater than.
        If its a custom type, then overload the "<" or comparison operator.

        Internally Implemented as self balancing BST.
    */
    std::map<std::string,CityRecord> cityMap;
    cityMap["Delhi"]=CityRecord{"Delhi",1000,1.4,2.6};
    cityMap["Agra"]=CityRecord{"Agra",2000,1.4,2.6};    
    cityMap["Bangalore"]=CityRecord{"Bangalore",3000,1.4,2.6};    
    cityMap["Mumbai"]=CityRecord{"Mumbai",4000,1.4,2.6};


    //Sorted Based on the key "City"
    for(const auto&it:cityMap)
    {
        std::cout<<it.first<<":"<<it.second.pop<<std::endl;
    }

    // This will add Amiritsar to the map because it will not find Amritar and hence add it in the end.
    //use .at("Amritsar") if we don't want to add.
    const auto&cityRecord1=cityMap["Amritsar"];


    //**find()
    auto citydata=cityMap.find("Pune");
    if(citydata!=cityMap.end())
    {
        std::cout<<"City Found";
    }
    else
    {
        std::cout<<"City Not Found\n\n";
    }


    //Const map cityMap2
    const auto cityMap2=cityMap;

    // We can access const map only via .at() and not []
    auto val=cityMap2.at("Delhi");
    std::cout<<val.name<<val.pop<<std::endl;
    std::cout<<"\n\n\n";




    /*
        Unordered_Map

        Internally Implemented as hash maps. Every Key is hashed and associated value is stored.
        Use Unordered map whenever you can. 

        Ordered map only when you want the data to be sorted.
        
        Rest everything is same as map.
    */

   //Note: They key should be hashable. Here string is hashable. If its a custom obj,
   // then we need to write our own hash().
    std::unordered_map<std::string,CityRecord> cityMapUn;
    cityMapUn["Chandigarh"]=CityRecord{"Chandigarh",1000,1.4,2.6};
    cityMapUn["Kasmir"]=CityRecord{"Kasmir",4000,1.4,2.6};
    cityMapUn["Hyderabad"]=CityRecord{"Hyderabad",1000,1.4,2.6};


    //Not sorted.
    for(const auto&it:cityMapUn)
    {
        std::cout<<it.second.name<<it.second.pop<<std::endl;
    }

    /*
        Capacity:
        size():Total No of emenets in the container
        empty(): Check if map is empty
        max_size(): Max possible size that the container can hold.

    */
   std::cout<<"Total Elements:"<<cityMap.size()<<std::endl;
   std::cout<<"Max_size:"<<cityMap.max_size()<<std::endl;

   /*
        Iterators: All the Iterators
   */

    /*
        Access:
        [] and at()
    
    */

   /*
        Modifiers:
        *insert() and emplace
        or you could use [] as well

        *erase(key), erase(iter)
        *clear()

   */


    /*
            Operations:
            *find(key)
            *count()Count elements with a specific key
            Searches the container for elements with a key equivalent to k and 
            returns the number of matches.

            Because all elements in a map container are unique, 
            the function can only return 1 (if the element is found) or zero (otherwise).
            
            *
    
    */


    cityMap.insert(std::make_pair("Punjab",CityRecord{"Punjab",1000,1.4,2.6}));
    disp(cityMap);

    cityMap.emplace(std::make_pair("Patna",CityRecord{"Patna",1000,1.4,2.6}));
    disp(cityMap);

    cityMap.erase("Patna");
    disp(cityMap);

    auto iter=cityMap.find("Punjab");
    if(iter!=cityMap.end())
    {
        cityMap.erase(iter);
    }

    disp(cityMap);

    return 0;
}