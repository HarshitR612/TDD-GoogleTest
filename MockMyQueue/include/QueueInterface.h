#pragma once

class QueueInterface {
public:
	virtual void enqueue(int data) = 0;
	virtual int dequeue() = 0;
	virtual ~QueueInterface() {}
};
