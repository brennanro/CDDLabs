#include "Semaphore.h"
#include <iostream>
#include <thread>

/**
   Author: Ronan Brennan 
   Date: 15/10/2017

  Demonstrating how rendezvous works in semaphores
**/

void taskOneA(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "A1"<<std::endl;
  theSemaphore->Signal();
}
void taskOneB(std::shared_ptr<Semaphore> theSemaphore){
  std::cout << "B1"<<std::endl;
  theSemaphore->Signal();

}

void taskTwoA(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout << "A2"<<std::endl;
  

}

void taskTwoB(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"B2"<<std::endl;
  
}

int main(void){
  std::thread threadOne, threadTwo, threadThree, threadFour;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskOneA,sem);
  threadTwo=std::thread(taskOneB,sem);
  threadThree=std::thread(taskTwoA,sem);
  threadFour=std::thread(taskTwoB,sem);
  threadOne.join();
  threadTwo.join();
  threadThree.join();    
  threadFour.join();
  return 0;
}
