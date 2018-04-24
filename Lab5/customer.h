#pragma once
#include "Semaphore.h"
#include <queue>

class customer{
public:

	std::shared_ptr<Semaphore> mutex;
	std::shared_ptr<Semaphore> items;
	std::shared_ptr<Semaphore> spaces;
	
	std::queue<char> bufferQueue;
	customer(); 
	void add(char);
	char remove();

};