#include <set>

#include "gtest/gtest.h"
#include "s21_set/s21_set.cc"

class SetTest : public testing::Test {
 protected:
  void SetUp() {
    for (int i = 0; i < 20; ++i) {
      my_set.insert(i);
      origin_set.insert(i);
    }
  }
  s21::set<int> my_set;
  std::set<int> origin_set;
};

TEST(SetConstructorTest, DefaultConstructor) {
  s21::set<int> mySet;
  ASSERT_TRUE(mySet.empty());  // Проверка, что контейнер создан пустым
  ASSERT_EQ(mySet.size(), 0);  // Проверка размера
}

TEST(SetConstructorTest, InitializerListConstructor) {
  s21::set<int> mySet = {1, 2, 3, 4, 5};
  ASSERT_EQ(mySet.size(), 5);  // Проверка размера
  ASSERT_TRUE(mySet.find(3) != mySet.end());  // Проверка наличия элемента 3
}

TEST(SetConstructorTest, CopyConstructor) {
  s21::set<int> sourceSet = {1, 2, 3};
  s21::set<int> copiedSet(sourceSet);

  ASSERT_EQ(sourceSet.size(), copiedSet.size());  // Проверка размеров
  ASSERT_TRUE(
      copiedSet.find(2) !=
      copiedSet
          .end());  // Проверка наличия элемента 2 в скопированном контейнере
  ASSERT_EQ(*sourceSet.find(3),
            *copiedSet.find(3));  // Проверка, что значения совпадают
}

TEST(SetConstructorTest, MoveConstructor) {
  s21::set<int> sourceSet = {1, 2, 3};
  s21::set<int> movedSet(std::move(sourceSet));

  ASSERT_EQ(sourceSet.size(),
            0);  // Проверка, что исходный контейнер пуст после перемещения
  ASSERT_EQ(movedSet.size(), 3);  // Проверка размера перемещенного контейнера
  ASSERT_TRUE(movedSet.find(1) !=
              movedSet.end());  // Проверка наличия элемента 1
}

TEST(SetConstructorTest, EmptyInitializerList) {
  s21::set<int> emptySet = {};
  ASSERT_TRUE(
      emptySet.empty());  // Проверка, что пустой контейнер создан правильно
  ASSERT_EQ(emptySet.size(), 0);  // Проверка размера
}

TEST(SetConstructorTest, CopyConstructorEmptySet) {
  s21::set<int> sourceSet;
  s21::set<int> copiedSet(sourceSet);
  ASSERT_TRUE(
      copiedSet
          .empty());  // Проверка, что копирование пустого контейнера работает
}

TEST(SetConstructorTest, CopyConstructorSingleElementSet) {
  s21::set<int> sourceSet = {42};
  s21::set<int> copiedSet(sourceSet);

  ASSERT_EQ(sourceSet.size(), copiedSet.size());  // Проверка размеров
  ASSERT_EQ(*sourceSet.find(42),
            *copiedSet.find(42));  // Проверка, что значения совпадают
}

TEST(SetConstructorTest, CopyConstructorWithDuplicates) {
  s21::set<int> sourceSet = {1, 2, 2, 3, 3, 3};
  s21::set<int> copiedSet(sourceSet);

  ASSERT_EQ(sourceSet.size(), 3);  // Проверка размера исходного контейнера
  ASSERT_EQ(copiedSet.size(),
            3);  // Проверка размера скопированного контейнера
  ASSERT_TRUE(
      copiedSet.find(2) !=
      copiedSet
          .end());  // Проверка наличия элемента 2 в скопированном контейнере
}

TEST(SetConstructorTest, MoveConstructorWithDuplicates) {
  s21::set<int> sourceSet = {1, 2, 2, 3, 3, 3};
  s21::set<int> movedSet(std::move(sourceSet));

  ASSERT_EQ(sourceSet.size(),
            0);  // Проверка, что исходный контейнер пуст после перемещения
  ASSERT_EQ(movedSet.size(), 3);  // Проверка размера перемещенного контейнера
  ASSERT_TRUE(movedSet.find(2) !=
              movedSet.end());  // Проверка наличия элемента 2
}

TEST(SetMoveOperatorTest, MoveAssignment) {
  s21::set<int> sourceSet = {1, 2, 3};
  s21::set<int> movedSet;
  movedSet = std::move(sourceSet);

  ASSERT_EQ(sourceSet.size(),
            0);  // Проверка, что исходный контейнер пуст после перемещения
  ASSERT_EQ(movedSet.size(), 3);  // Проверка размера перемещенного контейнера
  ASSERT_TRUE(movedSet.find(1) !=
              movedSet.end());  // Проверка наличия элемента 1
}

TEST(SetMoveOperatorTest, MoveAssignmentToSelf) {
  s21::set<int> mySet = {1, 2, 3};
  mySet = std::move(mySet);  // Попытка переместить контейнер в самого себя

  ASSERT_EQ(mySet.size(), 3);  // Проверка размера (должен остаться прежним)
  ASSERT_TRUE(mySet.find(1) != mySet.end());  // Проверка наличия элемента 1
}

TEST(SetMoveOperatorTest, MoveAssignmentFromEmptySet) {
  s21::set<int> sourceSet;
  s21::set<int> movedSet = {1, 2, 3};
  movedSet = std::move(sourceSet);  // Попытка переместить из пустого контейнера

  ASSERT_TRUE(
      sourceSet.empty());  // Проверка, что исходный контейнер остается пустым
  ASSERT_EQ(
      movedSet.size(),
      0);  // Проверка размера перемещенного контейнера (должен быть пустым)
}

TEST(SetMoveOperatorTest, MoveAssignmentWithDuplicates) {
  s21::set<int> sourceSet = {1, 2, 2, 3, 3, 3};
  s21::set<int> movedSet = {10, 20, 30};
  movedSet = std::move(sourceSet);

  ASSERT_EQ(sourceSet.size(),
            0);  // Проверка, что исходный контейнер пуст после перемещения
  ASSERT_EQ(movedSet.size(), 3);  // Проверка размера перемещенного контейнера
  ASSERT_TRUE(movedSet.find(2) !=
              movedSet.end());  // Проверка наличия элемента 2
}

TEST(SetSizeAndEmptyTest, EmptyAndSizeWithEmptySet) {
  s21::set<int> mySet;
  ASSERT_TRUE(mySet.empty());  // Проверка, что контейнер создан пустым
  ASSERT_EQ(mySet.size(), 0);  // Проверка размера (должен быть 0)
}

TEST(SetSizeAndEmptyTest, EmptyAndSizeWithNonEmptySet) {
  s21::set<int> mySet = {1, 2, 3, 4, 5};
  ASSERT_FALSE(mySet.empty());  // Проверка, что контейнер не пустой
  ASSERT_EQ(mySet.size(), 5);  // Проверка размера (должен быть 5)
}

TEST(SetMaxSizeTest, MaxSize) {
  s21::set<int> mySet;
  size_t max_size = mySet.max_size();

  // Ваша реализация может иметь ограничение на максимальное количество
  // элементов В данном тесте просто проверяем, что max_size не вызывает
  // ошибки или исключения
  ASSERT_TRUE(max_size > 0);
}

TEST(SetBeginEndTest, BeginAndEndWithEmptySet) {
  s21::set<int> mySet;
  ASSERT_EQ(mySet.begin(),
            mySet.end());  // Проверка, что begin и end указывают на
                           // одинаковое место (пустой контейнер)
}

TEST(SetBeginEndTest, BeginAndEndWithNonEmptySet) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};

  s21::set<int>::iterator it = mySet.begin();
  s21::set<int>::iterator endIt = mySet.end();

  ASSERT_EQ(*it, 1);  // Проверка, что begin указывает на минимальный элемент
  ASSERT_EQ(*(--endIt),
            5);  // Проверка, что end указывает за конец контейнера
}

TEST(SetBeginEndTest, IterateThroughSet) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};
  std::vector<int> elements;

  for (s21::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it) {
    elements.push_back(*it);
  }

  std::vector<int> expected = {1, 2, 3, 4, 5};
  ASSERT_EQ(elements, expected);  // Проверка, что проход по контейнеру
                                  // происходит в правильном порядке
}

TEST(SetFindTest, FindElement) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};

  s21::set<int>::iterator it = mySet.find(3);
  ASSERT_NE(it, mySet.end());  // Проверка, что элемент найден
  ASSERT_EQ(*it, 3);  // Проверка, что найден правильный элемент
}

TEST(SetFindTest, FindNonExistentElement) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};

  s21::set<int>::iterator it = mySet.find(6);
  ASSERT_EQ(it, mySet.end());  // Проверка, что элемент не найден
}

TEST(SetContainsTest, ContainsElement) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};

  ASSERT_TRUE(mySet.contains(1));  // Проверка, что элемент найден
}

TEST(SetContainsTest, ContainsNonExistentElement) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};

  ASSERT_FALSE(mySet.contains(6));  // Проверка, что элемент не найден
}

TEST(SetClearTest, ClearEmptySet) {
  s21::set<int> mySet;
  mySet.clear();

  ASSERT_TRUE(
      mySet.empty());  // Проверка, что контейнер остается пустым после clear
  ASSERT_EQ(mySet.size(), 0);  // Проверка размера (должен быть 0)
}

TEST(SetClearTest, ClearNonEmptySet) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};
  mySet.clear();

  ASSERT_TRUE(
      mySet.empty());  // Проверка, что контейнер становится пустым после clear
  ASSERT_EQ(mySet.size(), 0);  // Проверка размера (должен быть 0)
}

TEST(SetClearTest, ClearMultipleTimes) {
  s21::set<int> mySet = {3, 1, 2, 5, 4};
  mySet.clear();
  mySet.clear();
  mySet.clear();

  ASSERT_TRUE(mySet.empty());  // Проверка, что clear можно вызывать
                               // многократно без ошибок
  ASSERT_EQ(mySet.size(), 0);  // Проверка размера (должен быть 0)
}

TEST(SetInsertTest, InsertNewElement) {
  s21::set<int> mySet;
  auto result = mySet.insert(42);

  ASSERT_TRUE(result.second);  // Проверка, что элемент был успешно вставлен
  ASSERT_EQ(*result.first, 42);  // Проверка, что возвращенный итератор
                                 // указывает на вставленный элемент
  ASSERT_EQ(mySet.size(), 1);  // Проверка размера (должен быть 1)
  ASSERT_TRUE(
      mySet.contains(42));  // Проверка, что элемент содержится в контейнере
}

TEST(SetInsertTest, InsertExistingElement) {
  s21::set<int> mySet = {1, 2, 3};
  auto result = mySet.insert(2);  // Попытка вставить существующий элемент

  ASSERT_FALSE(result.second);  // Проверка, что элемент не был вставлен
  ASSERT_EQ(*result.first, 2);  // Проверка, что возвращенный итератор
                                // указывает на существующий элемент
  ASSERT_EQ(mySet.size(), 3);  // Проверка размера (должен остаться прежним)
}

TEST(SetEraseTest, EraseExistingElement) {
  s21::set<int> mySet = {1, 2, 3};
  size_t initialSize = mySet.size();
  s21::set<int>::iterator it = mySet.find(2);
  mySet.erase(it);

  ASSERT_EQ(mySet.size(),
            initialSize - 1);  // Проверка размера (должен уменьшиться на 1)
  ASSERT_FALSE(mySet.contains(
      2));  // Проверка, что элемент больше не содержится в контейнере
}

TEST(SetEraseTest, EraseNonExistentElement) {
  s21::set<int> mySet = {1, 2, 3};
  size_t initialSize = mySet.size();
  s21::set<int>::iterator it =
      mySet.find(42);  // Попытка удалить несуществующий элемент
  mySet.erase(it);

  ASSERT_EQ(mySet.size(),
            initialSize);  // Проверка размера (должен остаться прежним)
  // Поскольку элемент не существует, удаление не должно вызвать ошибку
}

TEST(SetEraseTest, EraseExistingElementMultipleTimes) {
  s21::set<int> mySet = {1, 2, 2, 3, 3, 3};
  size_t initialSize = mySet.size();
  s21::set<int>::iterator it = mySet.find(2);
  mySet.erase(it);  // Удаляем элемент, который есть несколько раз

  ASSERT_EQ(mySet.size(),
            initialSize - 1);  // Проверка размера (должен уменьшиться на 1)
  ASSERT_FALSE(mySet.contains(
      2));  // Проверка, что только один элемент с данным значением был удален
}

TEST(SetSwapTest, SwapTwoNonEmptySets) {
  s21::set<int> set1 = {1, 2, 3};
  s21::set<int> set2 = {4, 5, 6};

  set1.swap(set2);

  ASSERT_EQ(set1.size(), 3);  // Проверка размера set1 после обмена
  ASSERT_EQ(set2.size(), 3);  // Проверка размера set2 после обмена
  ASSERT_TRUE(set1.contains(
      4));  // Проверка, что элементы set1 и set2 были успешно обменены
  ASSERT_TRUE(set2.contains(1));
}

TEST(SetSwapTest, SwapEmptySetWithNonEmptySet) {
  s21::set<int> set1;
  s21::set<int> set2 = {1, 2, 3};

  set1.swap(set2);

  ASSERT_EQ(set1.size(), 3);  // Проверка размера set1 после обмена
  ASSERT_EQ(set2.size(), 0);  // Проверка размера set2 после обмена
  ASSERT_TRUE(set1.contains(
      1));  // Проверка, что элементы set1 и set2 были успешно обменены
  ASSERT_FALSE(set2.contains(1));  // Проверка, что set2 стал пустым
}

TEST(SetMergeTest, MergeTwoNonEmptySets) {
  s21::set<int> set1 = {1, 2, 3};
  s21::set<int> set2 = {3, 4, 5};

  set1.merge(set2);

  ASSERT_EQ(set1.size(), 5);  // Проверка размера set1 после слияния
  ASSERT_EQ(set2.size(), 0);  // Проверка размера set2 после слияния
  ASSERT_TRUE(set1.contains(
      4));  // Проверка, что элементы set2 были успешно объединены с set1
  ASSERT_TRUE(set1.contains(1));
}

TEST(SetMergeTest, MergeEmptySetWithNonEmptySet) {
  s21::set<int> set1;
  s21::set<int> set2 = {1, 2, 3};

  set1.merge(set2);

  ASSERT_EQ(set1.size(), 3);  // Проверка размера set1 после слияния
  ASSERT_EQ(set2.size(), 0);  // Проверка размера set2 после слияния
  ASSERT_TRUE(set1.contains(
      1));  // Проверка, что элементы set2 были успешно объединены с set1
  ASSERT_FALSE(set2.contains(1));  // Проверка, что set2 стал пустым
}

TEST(SetMergeTest, MergeTwoEmptySets) {
  s21::set<int> set1;
  s21::set<int> set2;

  set1.merge(set2);

  ASSERT_EQ(set1.size(), 0);  // Проверка размера set1 после слияния
  ASSERT_EQ(set2.size(), 0);  // Проверка размера set2 после слияния
}