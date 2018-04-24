#include "customer.h"
#include <iostream>
#include <thread>
#include <chrono>

/**
   Author: Ronan Brennan 
   Date: 17/10/2017
   Licence: GNU V3

   Objective: Producer and Consumer Demonstration.
**/

int cCount[26] ={};
const int lowerA = 97; //ascii value
const int lowerZ = 126; //ascii value




void producer(std::shared_ptr<customer> customer, int numOfC){ // producer
       char p;
       for (int count=0;count<numOfC;++count){
	      p = std::rand()%26 + lowerA; //produce random lower case character
	      customer->add(p); //customer cpp add
	      std::cout<<p<<" Produced "<<std::endl;
	      cCount[p]++; 
       }
       p='F'; //producer finished 
       customer->add(p);//customer cpp add
}

void consumer(std::shared_ptr<customer> customer){ //consumer
      char p;
      while(p != 'F'){
            p = customer->remove(); // producer still running customer cpp remove
	    if(p != 'F'){
	         std::cout<<p<<" has been consumed " <<std::endl; //producer still running consume p
	    }
          
       }
}

void printCharacterCounts(){
       for(char p = lowerA; p<lowerZ; p++){
             if(cCount[p] != 0){ // if character count is not euqal 0 print p
                   std::cout<<p<<" appears "<<cCount[p]<<std::endl;
	     }
       }
}

int main(void){
       int numOfC;    //The number of characters produced in each producer
       const int numOfT = 10;
       std::thread producerT[numOfT]; //thread for producer
       std::thread consumerT[numOfT]; //thread for consumer
       std::shared_ptr<customer> customer(new class customer);

       std::cout<<"How many characters in each producer "<< std::endl;
       std::cin>>numOfC; // cout and cin to recieve number of characters from user
  
       for(int i=0; i<numOfT; i++){ // run producer and consumer
           producerT[i] = std::thread(producer,customer, numOfC); 
	         consumerT[i] = std::thread(consumer,customer);
       }
       for(int i=0;i<numOfT;i++){
           producerT[i].join();
	         consumerT[i].join();
       }
       printCharacterCounts();  //Print the occurrences of each character
}