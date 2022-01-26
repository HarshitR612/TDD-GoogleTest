#include "MyQueue.h"
#include <queue>

void MyQueue::enqueue(int data) {
	q_.push(data);
}

int MyQueue::dequeue() {
	int data = q_.front();
	q_.pop();
	return data;
}