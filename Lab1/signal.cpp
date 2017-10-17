#include "Semaphore.h"
#include <iostream>
#include <thread>

/**
   Author: Ronan Brennan 
   Date: 14/10/2017

   Objective:Using Semaphore signal and wait to output values.
**/
void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  std::cout<<"Task One Entered"<<std::endl; /**Check that Task one is entered**/
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl; 
  theSemaphore->Signal();/**Send Signal**/
  std::cout<<"Task One Finished"<<std::endl;/**Check Task one is finished**/
}
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  std::cout<<"Task Two Entered"<<std::endl;
  theSemaphore->Wait();/**Won't continue until signal is received**/
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
  std::cout<<"Task Two Finished"<<std::endl;
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  std:: cout<<"Join Successful"<<std::endl;/**Outputs when works correctly**/
  return 0;
}
