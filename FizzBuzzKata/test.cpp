#include <gtest/gtest.h>

bool isMultiple(int value, int base) {
  return value % base == 0;
}

std::string fizzBuzz(int value) {
  if (isMultiple(value, 3) && isMultiple(value, 5)) {
    return "FizzBuzz";
  }
  if (isMultiple(value, 3)) {
    return "Fizz";
  }
  if (isMultiple(value, 5)) {
    return "Buzz";
  }
  return std::to_string(value);
}

void checkFizzBuzz(int value, std::string expectedResult) {
  std::string result = fizzBuzz(value);
  ASSERT_STREQ(expectedResult.c_str(), result.c_str());
}

TEST(FizzBuzzTest, returns1With1PassedIn) {
  checkFizzBuzz(1, "1");
}
TEST(FizzBuzzTest, returns2With2PassedIn) {
  checkFizzBuzz(2, "2");
}

TEST(FizzBuzzTest, returnsFizzWith3PassedIn) {
  checkFizzBuzz(3, "Fizz");
}

TEST(FizzBuzzTest, returnsBuzzWith5PassedIn) {
  checkFizzBuzz(5, "Buzz");
}

TEST(FizzBuzzTest, returnsFizzWhenMultipleOf3PassedIn) {
  checkFizzBuzz(6, "Fizz");
}

TEST(FizzBuzzTest, returnsBuzzWhenMultipleOf5PassedIn) {
  checkFizzBuzz(10, "Buzz");
}

TEST(FizzBuzzTest, returnsFizzBuzzWhenMultipleOf3And5Passed) {
  checkFizzBuzz(15, "FizzBuzz");
}