#include <iostream>
#include <thread>
#include <mutex>

unsigned int count(0);
std::mutex countMutex;

//Without mutex
// void countIncrementor()
// {
//     for(int i=0; i<100000; i++)
//         count++;
// }


// With Mutex
void countIncrementor()
{
    // countMutex.lock();
    for(int i=0; i<5; i++)
    {
        std::cout<<"The thread:"<<std::this_thread::get_id()<<" is processing!!!\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        countMutex.lock();
        count++;
        countMutex.unlock();
    }
    // countMutex.unlock();
}
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::cout<<"count:"<<count<<std::endl;
    
    std::thread t1(countIncrementor);
    std::thread t2(countIncrementor);

    if(t1.joinable())
    {
        t1.join();
    }
    if(t2.joinable())
    {
        t2.join();
    }

    std::cout<<"count:"<<count<<std::endl;
    
    auto end=std::chrono::high_resolution_clock::now();
    auto duration=std::chrono::duration_cast<std::chrono::seconds>(end-start);
    std::cout<<"Time:"<<duration.count()<<std::endl;

    return 0;
}
