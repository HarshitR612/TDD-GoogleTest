#include "DataHolder.h"

DataHolder::DataHolder(QueueInterface* queue): queue_(queue) {}

void DataHolder::addData(int data) {
	queue_->enqueue(data);
}

int DataHolder::getData() {
	return queue_->dequeue();
}