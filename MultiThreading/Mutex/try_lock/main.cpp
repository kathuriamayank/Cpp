/*
The program shows adding till 100000 by making use of threads.
Look how making use of try_lock speeds by the process, because in the mean time
the other thread is not blocked and it can do something.
*/


#include <iostream>
#include <thread>
#include <mutex>
#include <string>

int totalSum{0};
std::mutex sumMutex;


//try_lock
void summation(const std::string& threadName)
{
    int toAdd{0};

    while(totalSum<=100000)
    {
        std::cout<<"totalSum:"<<totalSum<<"\n";
        if(toAdd && sumMutex.try_lock())
        {
            std::cout<<"Addition via thread:"<<threadName<<std::endl;
            totalSum+=toAdd;
            sumMutex.unlock();
        }
        else
        {
            // std::this_thread::sleep_for(std::chrono::seconds(2));
            toAdd++;
        }
    }
}

//using mutex
// void summation(const std::string &threadName)
// {
//     int toAdd{0};

//     while (totalSum<=100000)
//     {
//         if(toAdd)
//         {
//             sumMutex.lock();
//             std::cout<<"Addition via thread:"<<threadName<<std::endl;
//             totalSum+=toAdd;
//             sumMutex.unlock();
//         }
//         else
//         {
//             toAdd++;
//         }
//     }
    
// }



int main()
{
    
    auto start = std::chrono::high_resolution_clock::now();
    std::thread t1(summation,"T1");
    std::thread t2(summation,"T2");

    if(t1.joinable())
    {
        t1.join();
    }

    if(t2.joinable())
    {
        t2.join();
    }

    auto end=std::chrono::high_resolution_clock::now();
    auto duration=std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout<<"Time:"<<duration.count()<<std::endl;

    return 0;
}

