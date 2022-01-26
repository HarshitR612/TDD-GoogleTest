#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "QueueInterface.h"
#include "DataHolder.h"

using ::testing::_;
using ::testing::Return;

class MyMockQueue : public QueueInterface {
public:
	MOCK_METHOD0(dequeue, int(void));
	MOCK_METHOD1(enqueue, void(int data));
};

class MockQueueTests : public ::testing::Test {
public:
	MockQueueTests() {
		myMockObj = new MyMockQueue();
		dh = new DataHolder(myMockObj);
	}
	~MockQueueTests() {
		delete dh;
		delete myMockObj;
	}
protected:
	DataHolder* dh;
	MyMockQueue* myMockObj;
};

TEST_F(MockQueueTests, CanAddData) {
	EXPECT_CALL(*myMockObj, enqueue(_));
	dh->addData(1);
}

TEST_F(MockQueueTests, CanAddAndTestData) {
	EXPECT_CALL(*myMockObj, enqueue(_));
	EXPECT_CALL(*myMockObj, dequeue()).WillOnce(Return(1));

	dh->addData(1);
	int data = dh->getData();
	ASSERT_EQ(1, data);
}