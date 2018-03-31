#include "Barrier.h"
#include <iostream>
#include <thread>

/**
   Author: Ronan Brennan 
   Date: 17/10/2017
   Licence: GNU V3

  Objective:Demonstrating Barries using Semephores.
**/


Barrier::Barrier(){
  numOfThreads = 0;
  turn = 0;
  count = 0;
  mutex=std::make_shared<Semaphore>(1);
  barrierOne=std::make_shared<Semaphore>(0);
  barrierTwo=std::make_shared<Semaphore>(1);

}

Barrier::Barrier(int count){ //Barrier Constructor

  this->count = count;
  turn = 0;
  numOfThreads = 0;
  mutex=std::make_shared<Semaphore>(1);
  barrierOne=std::make_shared<Semaphore>(0);
  barrierTwo=std::make_shared<Semaphore>(1);
}

Barrier::~Barrier(){ //Barrier Deconstructor

}

void Barrier::setCount(int i){

  this->count = i; //count value is set
}

int Barrier::returnCount(){

  return this->count; //count value is returned
}


void Barrier::waitThreadsCheckTurnstile(){

  if(turn== 0){ //waits for threads and checks turnstile
    One();
  }
  else{
    Two();
  }

}

void Barrier::One(){ //Turnstile 1 for Barrier

  mutex->Wait();
  numOfThreads++;
  if(numOfThreads == count){
    barrierTwo->Wait();
    barrierOne->Signal();
    turn = 1;
  }
  mutex->Signal();
  barrierOne->Wait();
  barrierOne->Signal();
}

void Barrier::Two(){ //Turnstile 2 for Barrier

  mutex->Wait();
  numOfThreads--;
  if(numOfThreads == 0){
    barrierOne->Wait();
    barrierTwo->Signal();
    turn = 0;
  }
  mutex->Signal();
  barrierTwo->Wait();
  barrierTwo->Signal();
}
