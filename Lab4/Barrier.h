#include "Semaphore.h"
#include <iostream>
#include <stdio.h>


/**
   Author: Ronan Brennan 
   Date: 17/10/2017
   Licence: GNU V3

  Objective:Demonstrating Barries using Semephores.
**/

class Barrier
{
private:
  
  int count; 
  int numOfThreads;
  int turn; //turnstile
  std::shared_ptr<Semaphore> barrierOne; //turnstile One
  std::shared_ptr<Semaphore> barrierTwo; //turnstile Two
  std::shared_ptr<Semaphore> mutex; //mutex for one thread execution at a time
  void One(); //turnstile One
  void Two();//turnstile Two

public:

  Barrier();
  ~Barrier();
  Barrier(int count);
  void setCount(int count); //Set Barrier Count
  int returnCount(); // Return Barrier Count
  void waitThreadsCheckTurnstile(); //wait for threads and check Turnstiles
};