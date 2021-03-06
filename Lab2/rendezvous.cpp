#include "Semaphore.h"
#include <iostream>
#include <thread>

/**
   Author: Ronan Brennan 
   Date: 15/10/2017
   Licence: GNU V3

  Objective:Demonstrating how rendezvous works in semaphores.
**/

void taskOneA(std::shared_ptr<Semaphore> theSemaphoreA){
  std::cout << "A1"<<std::endl;
  theSemaphoreA->Signal();
}
void taskOneB(std::shared_ptr<Semaphore> theSemaphoreB){
  std::cout << "B1"<<std::endl;
  theSemaphoreB->Signal();

}

void taskTwoA(std::shared_ptr<Semaphore> theSemaphoreA){
  theSemaphoreA->Wait();
  std::cout << "A2"<<std::endl;
  

}

void taskTwoB(std::shared_ptr<Semaphore> theSemaphoreB){
  theSemaphoreB->Wait();
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
