#pragma once

#include "QueueInterface.h"
#include <queue>

class MyQueue : public QueueInterface {
public:
	virtual void enqueue(int data);
	virtual int dequeue();
private:
	std::queue<int> q_;
};