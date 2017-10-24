#include "Semaphore.h"
#include <iostream>
#include <thread>

/**
   Author: Ronan Brennan 
   Date: 14/10/2017

   Objective:Using Semaphore signal and wait to output values.
**/
int taskOne(std::shared_ptr<Semaphore> theSemaphore){
  int count=0;
  for(int i=0; i<10;i++)
    {
  std::cout<<"Task One Entered"<<std::endl; /**Check that Task one is entered**/
  theSemaphore->Signal();/**Send Signal**/
  count++;/**Signal increments count to 1**/
  if (count==0)
    {
  theSemaphore->Wait();/**Won't continue until signal is received**/
  count--;
  std::cout<<"Signal recieved"<<std::endl;/** Recieved as nothing else running**/
    }
  else
    {
      std::cout<<"Awaiting signal"<<std::endl;/**Cannot recieve signal as already in use >0**/
  theSemaphore->Wait();/**Won't continue until signal is received**/
  while(count!=-1){
  count--;
  }
    }
    }
}

int main(void){
  std::thread threadOne;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskOne,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  return 0;
}
