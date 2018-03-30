#include "Semaphore.h"
#include <iostream>
#include <thread>

/**
   Author: Ronan Brennan 
   Date: 15/10/2017
   Licence: GNU V3

  Objective:Demonstrating mutual exclusion.
**/

int count = 1; 
void threadCheck(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout << "Thread Number " << count << " Entered\n";
  count++;
  theSemaphore->Signal();
}

int main(void){ 
  std::thread thread1, thread2, thread3;
  std::shared_ptr<Semaphore> sem( new Semaphore(1));
  /** Launch the threads  */
  std::cout << "Launched from the main\n";
  thread1 = std::thread (threadCheck,sem);
  thread2 = std::thread (threadCheck,sem);
  thread3 = std::thread (threadCheck,sem);
  thread1.join();
  thread2.join();
  thread3.join();
  return 0;
}
