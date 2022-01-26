#pragma once

#include "QueueInterface.h"

class DataHolder {
public:
	DataHolder(QueueInterface* queue);
	void addData(int data);
	int getData();
private:
	QueueInterface* queue_;
};