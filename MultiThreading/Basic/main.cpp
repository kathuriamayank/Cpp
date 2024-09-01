#include <string>
#include <iostream>
#include <thread>
#include <chrono>

bool cancount=true;

void doWork(std::string name)
{
    std::cout<<name<<": has started working!!!\n";
    std::this_thread::sleep_for(std::chrono::seconds(10));
    std::cout<<name<<": has completed its work!!!\n";
}


void doWorkForever(std::string name)
{
    std::cout<<name<<": has started working \n";
    while(true)
    {
        std::cout<<name<<": I am working\n";
    }
}

void incrementCount(const std::string& threadName)
{
    int counter=0;
    while(cancount)
    {
        counter++;
    }
    
    std::cout<<"The thread:"<<threadName<<"counter:"<<counter<<std::endl;
}

void basicWork(const std::string &threadName)
{
    std::cout<<"Child Thread:"<<threadName<<"has been created and has started working\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout<<"Child Thread:"<<threadName<<"has done its work!!!!!!!!!!\n";
}

int main()
{
    /*
        //##########  BASIC ############

    std::cout<<"Creating Counting Threads!!!!!\n";
    std::thread counterThread1(incrementCount,"Thread1");
    std::thread counterThread2(incrementCount,"Thread2");

    std::this_thread::sleep_for(std::chrono::seconds(2));
    cancount=false;

    counterThread1.join();
    counterThread2.join();
    
    */


   /*
        // Basic Join() and Joinable
    
    std::cout<<"I am the main thread\n";
    std::thread childThread1(basicWork,"ChildThread1");
    std::cout<<"The child thread:childThread1 has been created by main\n";
    
    //Returns true if the thread is active
    std::cout<<"Is joinable?:Child thread?"<<childThread1.joinable()<<std::endl;

    std::cout<<"Main thread is now sleeping\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout<<"Is joinable?:Child thread?"<<childThread1.joinable()<<std::endl;
 
    std::cout<<"Now mainl thread is waiting for the thread:ChildThread1 to join()\n";
    childThread1.join();
    std::cout<<"Is joinable?:Child thread?"<<childThread1.joinable()<<std::endl;

   */



 

    std::cout<<"Main Thread: Begins!!!\n";
    const std::string tName("Child1");
    const std::string tName2("Child2");
    std::thread thread1(doWork,tName);
    std::thread thread2(doWorkForever,tName2);
    // thread2.detach();

    std::cout<<"Main: Is"<<tName<<" joinable:"<<thread1.joinable()<<std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"Main: Waiting for thread:"<<tName<<" to complete and join \n";
    std::cout<<"Main: Is"<<tName<<" joinable:"<<thread1.joinable()<<std::endl;


    if(thread1.joinable())
    {
        
        /*
            Waiting for my child thread to complete its execution.
            Now I(main) will be in the blocked state until my child thread completes its
            execution.
            So the parent thread waits for the child thread to join. 
        */
        thread1.join();
    }



    // thread1.join();
    // thread1.detach();
    std::cout<<"Main thread:  is complete now!!!\n";
    std::cout<<"Main: Is"<<tName<<" joinable:"<<thread1.joinable()<<std::endl;




    return 0;
}

