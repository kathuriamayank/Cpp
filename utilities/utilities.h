#pragma once

#include <iostream>

namespace UTILITIES{
    template<typename T>
    void disp(const T&value){
        std::cout<<value<<"\n";
    }
};