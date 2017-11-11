
/**
   Author: Ronan Brennan 
   Date: 04/10/2017
   Licence: GNU V3

   Objective:Demonstrating how Resuable Barriers function. This is the .cpp file
**/

#include "Semaphore.h"
#include <iostream>
#include <thread>
int threadCounter = 0;
int nThreads = 2;

void reusablebarrier(std::shared_ptr<Semaphore> B1, std::shared_ptr<Semaphore> B2, std::shared_ptr<Semaphore> Mutex, int threadCounter, int nThreads)
{
  Mutex->Wait();/** Mutex implemented and waiting**/
  std::cout<<"The counter value is currently "<<threadCounter<<std::endl;/*Outputs Counter value which should be 0*/
  threadCounter++;/**Increment counter value by 1**/
 
  if(threadCounter == nThreads)/**  if the number of counters is equal to the number of threads (should not entered)**/
    {
     
      std::cout<<"Counter is equal to "<< nThreads<<" threads"<<std::endl;
      B2->Wait();
      B1->Signal();/** Creates a turnstile. A turnstile is when a wait and a signal are called in rapid succession**/
    }
  Mutex->Signal();/**Mutex is called**/
  B1->Wait();
  B1->Signal();
  std::cout<< "Allow through second barrier "<<nThreads<<" threads"<<std::endl;/** Output no. of threads allowed through second barrier **/
  Mutex->Wait();

  std::cout << "Counter value after the first barrier is "<< threadCounter<< std::endl;
  threadCounter--;/**Decrement counter value, should be 0**/

  if(threadCounter == 0){
    B1->Wait();
    B2->Signal();
    std::cout<<"No. of Threads is "<<nThreads<<std::endl;
}
  Mutex->Signal();
  B2->Wait();
  B2->Signal();
  std::cout<<"After the second barrier "<< std::endl;
}

int main(void){
  
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> Mutex( new Semaphore(1));
  std::shared_ptr<Semaphore> B1( new Semaphore);
  std::shared_ptr<Semaphore> B2( new Semaphore(1));
  threadOne=std::thread(reusablebarrier, Mutex, B1, B2, nThreads,threadCounter);
  threadTwo=std::thread(reusablebarrier, Mutex, B1, B2, nThreads,threadCounter);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
