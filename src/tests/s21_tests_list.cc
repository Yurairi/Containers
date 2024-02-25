#include <list>
#include <vector>

#include "gtest/gtest.h"
#include "s21_list/s21_list.cc"

TEST(ListConstructors, Constructor_Default) {
  s21::List<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(ListConstructors, Constructor_Size) {
  s21::List<int> s21_list(5);

  std::list<int> std_list(5);
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListConstructors, Constructor_List) {
  s21::List<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListConstructors, Constructor_Copy) {
  s21::List<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::List<int> s21_copy(s21_list);
  std::list<int> std_copy(std_list);
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(ListConstructors, Operator_Copy) {
  s21::List<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::List<int> s21_copy;
  s21_copy = s21_list;
  std::list<int> std_copy;
  std_copy = std_list;
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
}

TEST(ListConstructors, Constructor_Move) {
  s21::List<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::List<int> s21_copy(std::move(s21_list));
  std::list<int> std_copy(std::move(std_list));
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(ListConstructors, Operator_Move) {
  s21::List<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::List<int> s21_copy;
  s21_copy = std::move(s21_list);
  std::list<int> std_copy;
  std_copy = std::move(std_list);
  EXPECT_EQ(s21_copy.front(), std_copy.front());
  EXPECT_EQ(s21_copy.back(), std_copy.back());
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(ListMethods, Push_Front) {
  s21::List<int> s21_list;
  std::list<int> std_list;
  s21_list.push_front(1);
  std_list.push_front(1);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_front(2);
  std_list.push_front(2);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_front(3);
  std_list.push_front(3);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(ListMethods, Push_Back) {
  s21::List<int> s21_list;
  std::list<int> std_list;
  s21_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(ListMethods, Pop_Front) {
  s21::List<int> s21_list;
  std::list<int> std_list;
  s21_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.pop_front();
  std_list.pop_front();
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(ListMethods, Pop_Back) {
  s21::List<int> s21_list;
  std::list<int> std_list;
  s21_list.push_back(1);
  std_list.push_back(1);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_back(2);
  std_list.push_back(2);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.push_back(3);
  std_list.push_back(3);
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21_list.pop_back();
  std_list.pop_back();
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(ListIterators, Iterator_Begin) {
  s21::List<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::List<int>::iterator s21_it;
  s21_it = s21_list.begin();
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(ListIterators, Iterator_BeginPlusAndMinus) {
  s21::List<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::List<int>::iterator s21_it;
  s21_it = s21_list.begin();
  ++s21_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(*s21_it, *std_it);
  s21_it--;
  std_it--;
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(ListIterators, Iterator_BeginPlusAndMinus1) {
  s21::List<int> s21_list = {1, 2, 3};
  std::list<int> std_list = {1, 2, 3};
  s21::List<int>::iterator s21_it;
  s21_it = s21_list.begin();
  ++s21_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(*s21_it, *std_it);
  --s21_it;
  --std_it;
  EXPECT_EQ(*s21_it, *std_it);
  --s21_it;
  --std_it;
  --s21_it;
  --std_it;
  --s21_it;
  --std_it;
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(ListIterators, Iterator_End_Last) {
  s21::List<int> s21_list = {1, 2, 12};
  std::list<int> std_list = {1, 2, 12};
  s21::List<int>::iterator s21_it;
  s21_it = s21_list.end();
  --s21_it;
  std::list<int>::iterator std_it;
  std_it = std_list.end();
  --std_it;
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(ListIterators, Iterator_Equals) {
  s21::List<int> first_list = {1, 2, 3};
  s21::List<int>::iterator s21_it_first;
  s21_it_first = first_list.begin();
  s21::List<int>::iterator s21_it_second;
  s21_it_second = first_list.begin();
  EXPECT_TRUE(s21_it_first == s21_it_second);
  EXPECT_TRUE(s21_it_first >= s21_it_second);
  EXPECT_TRUE(s21_it_first <= s21_it_second);
  ++s21_it_second;
  EXPECT_TRUE(s21_it_first != s21_it_second);
  EXPECT_TRUE(s21_it_second > s21_it_first);
  EXPECT_TRUE(s21_it_second >= s21_it_first);
  EXPECT_TRUE(s21_it_first < s21_it_second);
  EXPECT_TRUE(s21_it_first <= s21_it_second);
}

TEST(ListMethods, Insert) {
  s21::List<int> s21_list{727, 515, 230, 817, 411};
  std::list<int> std_list{727, 515, 230, 817, 411};
  s21::List<int>::iterator s21_it = s21_list.begin();
  std::list<int>::iterator std_it = std_list.begin();
  s21_list.insert(s21_it, 717);
  std_list.insert(std_it, 717);
  s21_it = s21_list.end();
  std_it = std_list.end();
  s21_list.insert(s21_it, 636);
  std_list.insert(std_it, 636);
  ASSERT_EQ(s21_list.front(), std_list.front());
  ++s21_it;
  ++std_it;
  s21_list.insert(s21_it, 23);
  std_list.insert(std_it, 23);
  ASSERT_EQ(s21_list.size(), std_list.size());
  for (size_t i = 0; i < s21_list.size(); i++) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListMethods, Erase) {
  s21::List<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  s21_list.erase(s21_list.begin());
  std_list.erase(std_list.begin());
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
  s21::List<int>::iterator s21_it;
  s21_it = s21_list.begin();
  ++s21_it;
  std::list<int>::iterator std_it;
  std_it = std_list.begin();
  ++std_it;
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(ListMethods, Erase1) {
  s21::List<int> s21_list{717, 5335, 123, 187};
  std::list<int> std_list{717, 5335, 123, 187};
  s21::List<int>::iterator s21_it = s21_list.begin();
  std::list<int>::iterator std_it = std_list.begin();
  s21_list.erase(s21_it);
  std_list.erase(std_it);
  ASSERT_EQ(s21_list.front(), std_list.front());
  s21_it = s21_list.begin();
  std_it = std_list.begin();
  ++s21_it;
  ++std_it;
  s21_list.erase(s21_it);
  std_list.erase(std_it);
  s21_it = s21_list.begin();
  std_it = std_list.begin();
  ASSERT_EQ(s21_list.size(), std_list.size());
  for (size_t i = 0; i < s21_list.size(); i++) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListMethods, Erase2) {
  s21::List<int> s21_list{717, 5335, 123, 187};
  std::list<int> std_list{717, 5335, 123, 187};
  s21::List<int>::iterator s21_it = s21_list.begin();
  std::list<int>::iterator std_it = std_list.begin();
  s21_list.erase(s21_it);
  std_list.erase(std_it);
  ASSERT_EQ(s21_list.front(), std_list.front());
  s21_it = s21_list.begin();
  std_it = std_list.begin();
  s21_it++;
  std_it++;
  s21_it++;
  std_it++;
  s21_list.erase(s21_it);
  std_list.erase(std_it);
  s21_it = s21_list.begin();
  std_it = std_list.begin();
  ASSERT_EQ(s21_list.size(), std_list.size());
  for (size_t i = 0; i < s21_list.size(); i++) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListMethods, Splice) {
  s21::List<int> s21_list_first = {1};
  s21::List<int> s21_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  s21::List<int>::iterator s21_it = s21_list_first.begin();
  std::list<int>::iterator std_it = std_list_first.begin();
  s21_list_first.splice(s21_it, s21_list_second);
  std_list_first.splice(std_it, std_list_second);
  EXPECT_EQ(s21_list_first.front(), std_list_first.front());
  EXPECT_EQ(s21_list_first.back(), std_list_first.back());
}

TEST(ListMethods, Merge) {
  s21::List<int> s21_list_first = {1};
  s21::List<int> s21_list_second = {2, 3, 4, 5};
  std::list<int> std_list_first = {1};
  std::list<int> std_list_second = {2, 3, 4, 5};
  s21_list_first.merge(s21_list_second);
  std_list_first.merge(std_list_second);
  EXPECT_EQ(s21_list_first.front(), std_list_first.front());
  EXPECT_EQ(s21_list_first.back(), std_list_first.back());
  EXPECT_EQ(s21_list_second.empty(), std_list_second.empty());
}

TEST(ListMethods, Reverse) {
  s21::List<int> s21_list = {1, 2, 3, 4, 5};
  std::list<int> std_list = {1, 2, 3, 4, 5};
  s21_list.reverse();
  std_list.reverse();
  EXPECT_EQ(s21_list.front(), std_list.front());
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(ListMethods, Reverse1) {
  s21::List<int> s21_list{737, 515, 5, 187, 31111};
  std::list<int> std_list{737, 515, 5, 187, 31111};
  s21_list.reverse();
  std_list.reverse();
  s21::List<int>::iterator s21_it = s21_list.begin();
  std::list<int>::iterator std_it = std_list.begin();
  ASSERT_EQ(s21_list.size(), std_list.size());
  for (size_t i = 0; i < s21_list.size(); i++) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListMethods, Reverse2) {
  s21::List<int> s21_list{737, 515, 5, 187, 31111};
  std::list<int> std_list{737, 515, 5, 187, 31111};

  s21_list.reverse();
  std_list.reverse();

  s21_list.reverse();
  std_list.reverse();

  s21::List<int>::iterator s21_it = s21_list.begin();
  std::list<int>::iterator std_it = std_list.begin();
  ASSERT_EQ(s21_list.size(), std_list.size());
  for (size_t i = 0; i <= s21_list.size() + 1; i++) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListMethods, Unique) {
  s21::List<int> s21_list = {1, 2, 2, 3, 3};
  std::list<int> std_list = {1, 2, 2, 3, 3};
  s21::List<int>::iterator s21_it;
  std::list<int>::iterator std_it;
  s21_list.unique();
  std_list.unique();
  s21_it = s21_list.begin();
  std_it = std_list.begin();
  EXPECT_EQ(*s21_it, *std_it);
  ++s21_it;
  ++std_it;
  EXPECT_EQ(*s21_it, *std_it);
  ++s21_it;
  ++std_it;
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(ListMethods, Unique1) {
  s21::List<int> s21_list{11, 1, 1, 1, 2322, 222, 23, 313, 3, 3};
  std::list<int> std_list{11, 1, 1, 1, 2322, 222, 23, 313, 3, 3};
  s21_list.unique();
  std_list.unique();
  s21::List<int>::iterator s21_it = s21_list.begin();
  std::list<int>::iterator std_it = std_list.begin();
  ASSERT_EQ(s21_list.size(), std_list.size());
  for (size_t i = 0; i < s21_list.size(); i++) {
    ASSERT_EQ(*s21_it, *std_it);
    ++s21_it;
    ++std_it;
  }
}

TEST(ListMethods, Sort) {
  s21::List<int> s21_list = {2, 4, 1, 3};
  std::list<int> std_list = {2, 4, 1, 3};
  s21::List<int>::iterator s21_it;
  std::list<int>::iterator std_it;
  s21_list.sort();
  std_list.sort();
  s21_it = s21_list.begin();
  std_it = std_list.begin();
  EXPECT_EQ(*s21_it, *std_it);
  ++s21_it;
  ++std_it;
  EXPECT_EQ(*s21_it, *std_it);
  ++s21_it;
  ++std_it;
  EXPECT_EQ(*s21_it, *std_it);
  ++s21_it;
  ++std_it;
  EXPECT_EQ(*s21_it, *std_it);
  ++s21_it;
  ++std_it;
  EXPECT_EQ(*s21_it, *std_it);
}