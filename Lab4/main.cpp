#include "Barrier.h"
#include <thread>
#include <vector>

/**
   Author: Ronan Brennan 
   Date: 17/10/2017
   Licence: GNU V3

  Objective:Demonstrating Barries using Semephores.
**/

void output(std::shared_ptr<Barrier> barrierNumber){

  std::cout << "one" << std::endl;
  barrierNumber->waitThreadsCheckTurnstile();
  std::cout << "two" << std::endl;
  barrierNumber->waitThreadsCheckTurnstile();
  std::cout << "three" << std::endl;
  barrierNumber->waitThreadsCheckTurnstile();
  std::cout << "four" << std::endl;
}

int main(void){

  
  std::vector<std::thread> array(5); //thread array
  std::shared_ptr<Barrier> barrierNumber( new Barrier);
  barrierNumber->setCount(array.size()); //set count for array size
for(int i=0; i < array.size(); i++){ //for loop for array size
    array[i]=std::thread(output,barrierNumber);
  }

  for(int i = 0; i < array.size(); i++){
    array[i].join();
  }
  
  return 0;
}