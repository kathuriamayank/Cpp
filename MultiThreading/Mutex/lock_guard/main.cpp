#include <iostream>
#include <thread>
#include <mutex>


int count=0;

std::mutex countMutex;

void countIncrementor(const std::string &threadName)
{
    // std::lock_guard<std::mutex> lock(countMutex);
    for(int i=0; i<5; i++)
    {
        // std::cout<<"Thread:"<<threadName<<" is now sleeping\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lock(countMutex);
        count++;
    }

}


int main()
{
    auto start=std::chrono::high_resolution_clock::now();

    std::thread t1(countIncrementor,"T1");
    std::thread t2(countIncrementor,"T2");


    if(t1.joinable())
        t1.join();


    if(t2.joinable())
        t2.join();

    std::cout<<"Count:"<<count<<std::endl;
    
    auto end=std::chrono::high_resolution_clock::now();
    auto time=std::chrono::duration_cast<std::chrono::milliseconds>(end-start);

    std::cout<<"Time:"<<time.count()<<std::endl;

    return 0;    
}
