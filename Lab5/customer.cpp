#include "customer.h"
#include <iostream>

/**
   Author: Ronan Brennan 
   Date: 17/10/2017
   Licence: GNU V3

   Objective: Producer and Consumer Demonsraration.
**/


//Safe Buffer
customer::customer() {
  mutex = std::make_shared<Semaphore>(1);
  items = std::make_shared<Semaphore>(0) ;
  spaces = std::make_shared<Semaphore>(100);
 
}

void customer::add(char p){ 
  spaces->Wait(); // adds to buffer , space is occupied in buffer
  mutex->Wait();
  bufferQueue.push(p);
  mutex->Signal();
  items->Signal();
}

char customer::remove(){ 
  char p;
  items->Wait();
  mutex->Wait();
  p = bufferQueue.front();
  bufferQueue.pop();
  mutex->Signal();
  spaces->Signal();
  return p; //deletes from buffer, opens space in buffer

}
