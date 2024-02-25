#include <list>
#include <vector>

#include "gtest/gtest.h"
#include "s21_vector/s21_vector.cc"

TEST(VectorConstructros, Constructor_Default) {
  s21::Vector<int> s21_vector;
  std::vector<int> std_vector;
  ASSERT_EQ(s21_vector.empty(), std_vector.empty());
  ASSERT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorConstructros, Constructor_Size) {
  s21::Vector<int> s21_vector(5);
  std::vector<int> std_vector(5);
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorConstructros, Constructor_Vector) {
  s21::Vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  EXPECT_EQ(s21_vector.front(), std_vector.front());
  EXPECT_EQ(s21_vector.back(), std_vector.back());
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorConstructros, Constructor_Copy) {
  s21::Vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  s21::Vector<int> s21_copy(s21_vector);
  std::vector<int> std_copy(std_vector);
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorConstructros, Operator_Copy) {
  s21::Vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  s21::Vector<int> s21_copy;
  s21_copy = s21_vector;
  std::vector<int> std_copy;
  std_copy = std_vector;
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
}

TEST(VectorConstructros, Constructor_Move) {
  s21::Vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  s21::Vector<int> s21_copy(std::move(s21_vector));
  std::vector<int> std_copy(std::move(std_vector));
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(VectorConstructros, Operator_Move) {
  s21::Vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  s21::Vector<int> s21_copy;
  s21_copy = std::move(s21_vector);
  std::vector<int> std_copy;
  std_copy = std::move(std_vector);
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
  EXPECT_EQ(s21_vector.empty(), std_vector.empty());
}

TEST(VectorMethods, Operator_At) {
  s21::Vector<int> s21_vector = {1, 2, 3};
  std::vector<int> std_vector = {1, 2, 3};
  ASSERT_EQ(s21_vector[0], std_vector[0]);
  ASSERT_EQ(s21_vector[1], std_vector[1]);
  ASSERT_EQ(s21_vector[2], std_vector[2]);
  ASSERT_EQ(s21_vector.at(0), std_vector.at(0));
  ASSERT_EQ(s21_vector.at(1), std_vector.at(1));
  ASSERT_EQ(s21_vector.at(2), std_vector.at(2));
}

TEST(VectorMethods, Push_Pop_Int) {
  s21::Vector<int> s21_vector;
  std::vector<int> std_copy;
  s21_vector.push_back(1);
  std_copy.push_back(1);
  ASSERT_EQ(s21_vector[0], std_copy[0]);
  s21_vector.push_back(2);
  std_copy.push_back(2);
  ASSERT_EQ(s21_vector[1], std_copy[1]);
  s21_vector.push_back(3);
  std_copy.push_back(3);
  s21_vector.pop_back();
  std_copy.pop_back();
  ASSERT_EQ(s21_vector[1], std_copy[1]);
  ASSERT_EQ(s21_vector.size(), std_copy.size());
}

TEST(VectorMethods, Push_Pop_Char) {
  s21::Vector<char> s21_vector;
  std::vector<char> std_copy;
  s21_vector.push_back('a');
  std_copy.push_back('a');
  ASSERT_EQ(s21_vector[0], std_copy[0]);
  s21_vector.push_back('b');
  std_copy.push_back('b');
  ASSERT_EQ(s21_vector[1], std_copy[1]);
  s21_vector.push_back('c');
  std_copy.push_back('c');
  s21_vector.pop_back();
  std_copy.pop_back();
  ASSERT_EQ(s21_vector[1], std_copy[1]);
  ASSERT_EQ(s21_vector.size(), std_copy.size());
}

TEST(VectorMethods, Swap) {
  s21::Vector<int> s21_vector({13377, 5335, 0, 83237, 11111});
  s21::Vector<int> s21_vector2({15, 31, 3});
  std::vector<int> std_copy({13377, 5335, 0, 83237, 11111});
  std::vector<int> std_copy2({15, 31, 3});
  s21_vector.swap(s21_vector2);
  std_copy.swap(std_copy2);
  ASSERT_EQ(s21_vector.size(), std_copy.size());
  ASSERT_EQ(s21_vector2.size(), std_copy2.size());
  for (size_t i = 0; i < s21_vector2.size(); i++) {
    ASSERT_EQ(s21_vector2[i], std_copy2[i]);
  }
}

TEST(VectorConstructros, DefaultConstructor_EmptyVector) {
  s21::Vector<int> s21_vector;
  std::vector<int> std_vector;
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  s21::Vector<int> s21_vector1 = {1, 2, 3};
  std::vector<int> std_vector1 = {1, 2, 3};
  EXPECT_EQ(s21_vector1.size(), std_vector1.size());
}

TEST(VectorIterators, Begin_End) {
  s21::Vector<int> s21_vector = {1, 2, 3, 4, 5};
  std::vector<int> std_vector = {1, 2, 3, 4, 5};
  s21::Vector<int>::iterator it = s21_vector.begin();
  EXPECT_EQ(*it, 1);
  *it = 10;
  EXPECT_EQ(s21_vector[0], 10);
}

TEST(VectorMethods, data) {
  s21::Vector<int> s21_vector{14, 2000, 33};
  std::vector<int> std_vector{14, 2000, 33};
  ASSERT_EQ(s21_vector.size(), std_vector.size());
  ASSERT_EQ(s21_vector.max_size(), std_vector.max_size());
  auto *s21_it = s21_vector.data();
  auto *std_it = std_vector.data();
  for (; s21_it != s21_vector.end(); s21_it++, std_it++) {
    ASSERT_EQ(*s21_it, *std_it);
  }
}

TEST(VectorMethods, Reserve_IncreaseCapacity) {
  s21::Vector<int> s21_vector;
  size_t initialCapacity = s21_vector.capacity();
  size_t newCapacity = initialCapacity + 10;
  s21_vector.reserve(newCapacity);
  EXPECT_GE(s21_vector.capacity(), newCapacity);
}

TEST(VectorMethods, Reserve_DecreaseCapacity) {
  s21::Vector<int> s21_vector = {1, 2, 3, 4, 5};
  size_t initialCapacity = s21_vector.capacity();
  size_t newCapacity = initialCapacity - 2;
  s21_vector.reserve(newCapacity);
  EXPECT_LE(s21_vector.capacity(), initialCapacity);
  EXPECT_GE(s21_vector.capacity(), newCapacity);
}

TEST(VectorMethods, Capacity) {
  s21::Vector<int> s21_vector = {1, 2, 3, 4, 5};
  s21::Vector<int> std_vector = {1, 2, 3, 4, 5};
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  s21_vector.push_back(6);
  std_vector.push_back(6);
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  s21_vector.push_back(6);
  s21_vector.push_back(6);
  s21_vector.push_back(6);
  std_vector.push_back(6);
  std_vector.push_back(6);
  std_vector.push_back(6);
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.size(), std_vector.size());
  s21_vector.shrink_to_fit();
  std_vector.shrink_to_fit();
  EXPECT_EQ(s21_vector.capacity(), std_vector.capacity());
  EXPECT_EQ(s21_vector.size(), std_vector.size());
}

TEST(VectorMethods, insert) {
  s21::Vector<int> s21vector{1, 4, 8, 16};
  std::vector<int> stdvector{1, 4, 8, 16};
  s21::Vector<int>::iterator s21a = s21vector.begin();
  std::vector<int>::iterator stda = stdvector.begin();
  s21vector.insert(s21a, 2);
  stdvector.insert(stda, 2);
  s21::Vector<int>::iterator s21it = s21vector.end();
  std::vector<int>::iterator stdit = stdvector.end();
  s21vector.insert(s21it, 100);
  stdvector.insert(stdit, 100);
  ASSERT_EQ(s21vector.size(), stdvector.size());
}

TEST(VectorMethods, erase) {
  s21::Vector<int> s21vector{717, 5335, 123, 187};
  std::vector<int> stdvector{717, 5335, 123, 187};
  s21::Vector<int>::iterator s21it = s21vector.begin();
  std::vector<int>::iterator stdit = stdvector.begin();
  s21vector.erase(s21it);
  stdvector.erase(stdit);
  ASSERT_EQ(s21vector.front(), stdvector.front());
  s21it = s21vector.begin();
  stdit = stdvector.begin();
  ++s21it;
  ++stdit;
  s21vector.erase(s21it);
  stdvector.erase(stdit);
  s21it = s21vector.begin();
  stdit = stdvector.begin();
  ASSERT_EQ(s21vector.size(), stdvector.size());
}