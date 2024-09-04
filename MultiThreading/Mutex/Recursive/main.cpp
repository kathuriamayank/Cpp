#include <iostream>
#include <thread>
#include <string>
#include <mutex>


std::recursive_mutex countMutex;
int globalBuffer(0);

std::mutex numberMutex;

void recursiveCount(const std::string &threadName,int count)
{
    if(count<0)
        return;

    countMutex.lock();
    globalBuffer++;
    std::cout<<"Thread:"<<threadName<<":"<<globalBuffer<<std::endl;
    recursiveCount(threadName,--count);
    countMutex.unlock();
}


/*
// DeadLock in case of using mutex
void Func(const std::string&threadName, int num)
{
    if(num<0)
        return;
    
    numberMutex.lock();
    std::cout<<"Thread:"<<threadName<<":"<<num<<std::endl;
    Func(threadName,--num);
    numberMutex.unlock();
}

*/

int main()
{
    std::thread t1(recursiveCount,"T1",10);
    std::thread t2(recursiveCount,"T2",10);

    // std::thread t3(Func,"T3",10);
    // std::thread t4(Func,"T4",10);

    if(t1.joinable())
    {
        t1.join();
    }

    if(t2.joinable())
    {
        t2.join();
    }

    // if(t3.joinable())
    // {
    //     t3.join();
    // }

    // if(t4.joinable())
    // {
    //     t4.join();
    // }

    return 0;
}


