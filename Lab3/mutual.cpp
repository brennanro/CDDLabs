#include "Semaphore.h"
#include <iostream>
#include <thread>

/**
   Author: Ronan Brennan 
   Date: 15/10/2017
   Licence: GNU V3

  Objective:Demonstrating mutual exclusion.
**/

int count = 1; // initilize count
void threadCheck(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait(); // Semephore Wait
  std::cout << "Thread Number " << count << " Entered\n"; // Thread number output
  count++; // increment count
  theSemaphore->Signal(); // Semephore Signal
}

int main(void){ 
  std::thread thread1, thread2, thread3; // create threads
  std::shared_ptr<Semaphore> sem( new Semaphore(1));
 
  std::cout << "Launched from the main\n";
  thread1 = std::thread (threadCheck,sem);
  thread2 = std::thread (threadCheck,sem);
  thread3 = std::thread (threadCheck,sem);
  thread1.join();
  thread2.join();
  thread3.join();
  return 0;
}
