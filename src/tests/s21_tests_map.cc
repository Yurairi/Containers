#include <map>

#include "gtest/gtest.h"
#include "s21_map/s21_map.cc"

TEST(MapDefaultConstructorTest, DefaultConstructor) {
  s21::map<int, int> myMap;

  ASSERT_TRUE(myMap.empty());  // Проверка, что контейнер создан пустым
  ASSERT_EQ(myMap.size(), 0);  // Проверка размера (должен быть 0)
}

TEST(MapInitializerListConstructorTest, InitializerListConstructor) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

  ASSERT_FALSE(myMap.empty());  // Проверка, что контейнер не пустой
  ASSERT_EQ(myMap.size(), 3);  // Проверка размера (должен быть 3)
  ASSERT_EQ(myMap.at(1), 10);  // Проверка значения элемента
  ASSERT_EQ(myMap.at(2), 20);
  ASSERT_EQ(myMap.at(3), 30);
}

TEST(MapCopyConstructorTest, CopyConstructor) {
  s21::map<int, int> sourceMap = {{1, 10}, {2, 20}, {3, 30}};
  s21::map<int, int> copiedMap(sourceMap);

  ASSERT_EQ(sourceMap.size(),
            copiedMap.size());  // Проверка, что размеры исходного и
                                // скопированного контейнера одинаковы
  ASSERT_EQ(copiedMap.at(2),
            20);  // Проверка, что значения скопированы правильно
}

TEST(MapMoveConstructorTest, MoveConstructor) {
  s21::map<int, int> sourceMap = {{1, 10}, {2, 20}, {3, 30}};
  s21::map<int, int> movedMap(std::move(sourceMap));

  ASSERT_TRUE(
      sourceMap
          .empty());  // Проверка, что исходный контейнер пуст после перемещения
  ASSERT_EQ(movedMap.size(), 3);  // Проверка размера перемещенного контейнера
  ASSERT_EQ(movedMap.at(1), 10);  // Проверка, что значения перемещены правильно
}

TEST(MapAtTest, AtExistingKey) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};
  ASSERT_EQ(myMap.at(1), 10);  // Проверка, что значение получено правильно
  ASSERT_EQ(myMap.at(2), 20);
  ASSERT_EQ(myMap.at(3), 30);
}

TEST(MapAtTest, AtNonExistentKey) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

  // Попытка доступа к несуществующему ключу
  ASSERT_THROW(myMap.at(4), const char*);
  ASSERT_THROW(myMap.at(0), const char*);
}

TEST(MapOperatorBracketTest, OperatorBracketExistingKey) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};
  ASSERT_EQ(myMap[1], 10);  // Проверка, что значение получено правильно
  ASSERT_EQ(myMap[2], 20);
  ASSERT_EQ(myMap[3], 30);
}

TEST(MapOperatorBracketTest, OperatorBracketNonExistentKey) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

  // Попытка доступа к несуществующему ключу
  ASSERT_NO_THROW(myMap[4]);  // operator[] не должен бросать исключение при
                              // несуществующем ключе
  ASSERT_EQ(myMap[4],
            0);  // Новая запись с нулевым значением должна быть создана

  // Попытка доступа к несуществующему ключу, но с установкой значения
  myMap[5] = 50;
  ASSERT_EQ(myMap[5], 50);  // Значение должно быть установлено правильно
}

TEST(MapIteratorTest, BeginAndEndWithEmptyMap) {
  s21::map<int, int> myMap;
  s21::map<int, int>::iterator it = myMap.begin();
  s21::map<int, int>::iterator endIt = myMap.end();

  ASSERT_EQ(it, endIt);  // Проверка, что begin и end указывают на одинаковое
                         // место (пустой контейнер)
}

TEST(MapIteratorTest, BeginAndEndWithNonEmptyMap) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

  s21::map<int, int>::iterator it = myMap.begin();
  s21::map<int, int>::iterator endIt = myMap.end();

  ASSERT_NE(it, endIt);  // Проверка, что begin и end указывают на разные места
                         // (непустой контейнер)
  ASSERT_EQ((*it).first,
            1);  // Проверка, что begin указывает на минимальный ключ
  ASSERT_EQ((*(--endIt)).first,
            3);  // Проверка, что end указывает на максимальный ключ
}

TEST(MapIteratorTest, IterateThroughMap) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};
  std::vector<std::pair<int, int>> elements;

  for (s21::map<int, int>::iterator it = myMap.begin(); it != myMap.end();
       ++it) {
    elements.push_back(*it);
  }

  std::vector<std::pair<int, int>> expected = {{1, 10}, {2, 20}, {3, 30}};
  ASSERT_EQ(elements, expected);  // Проверка, что проход по контейнеру
                                  // происходит в правильном порядке
}

TEST(MapEmptyTest, EmptyMap) {
  s21::map<int, int> myMap;

  ASSERT_TRUE(myMap.empty());  // Проверка, что контейнер создан пустым
  ASSERT_EQ(myMap.size(), 0);  // Проверка размера (должен быть 0)
}

TEST(MapEmptyTest, NonEmptyMap) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

  ASSERT_FALSE(myMap.empty());  // Проверка, что контейнер не пустой
  ASSERT_EQ(myMap.size(), 3);  // Проверка размера (должен быть 3)
}

TEST(MapSizeTest, SizeOfEmptyMap) {
  s21::map<int, int> myMap;

  ASSERT_EQ(myMap.size(), 0);  // Проверка размера пустого контейнера
}

TEST(MapSizeTest, SizeOfNonEmptyMap) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

  ASSERT_EQ(myMap.size(), 3);  // Проверка размера непустого контейнера
}

TEST(MapMaxSizeTest, MaxSize) {
  s21::map<int, int> myMap;

  ASSERT_LE(myMap.max_size(),
            std::numeric_limits<size_t>::max());  // Проверка, что max_size не
                                                  // превышает максимальное
                                                  // значение size_t
}

TEST(MapClearTest, ClearNonEmptyMap) {
  s21::map<int, int> myMap = {{1, 10}, {2, 20}, {3, 30}};

  myMap.clear();

  ASSERT_TRUE(myMap.empty());  // Проверка, что контейнер стал пустым
  ASSERT_EQ(myMap.size(), 0);  // Проверка размера (должен быть 0)
}

TEST(MapInsertValueTest, InsertNewElement) {
  s21::map<int, int> myMap;
  auto result = myMap.insert(std::make_pair(1, 10));

  ASSERT_TRUE(result.second);  // Проверка, что элемент был успешно вставлен
  ASSERT_EQ((*(result.first)).first, 1);  // Проверка, что возвращенный итератор
                                          // указывает на вставленный элемент
  ASSERT_EQ((*(result.first)).second, 10);
  ASSERT_EQ(myMap.size(), 1);  // Проверка размера (должен быть 1)
}

TEST(MapInsertValueTest, InsertExistingElement) {
  s21::map<int, int> myMap = {{1, 10}};
  auto result = myMap.insert(
      std::make_pair(1, 20));  // Попытка вставить существующий элемент

  ASSERT_FALSE(result.second);  // Проверка, что элемент не был вставлен
  ASSERT_EQ((*(result.first)).second,
            10);  // Проверка, что возвращенный итератор
                  // указывает на существующий элемент
  ASSERT_EQ(myMap.size(), 1);  // Проверка размера (должен остаться прежним)
}

TEST(MapInsertKeyObjTest, InsertNewElement) {
  s21::map<int, int> myMap;
  std::pair<s21::map<int, int>::iterator, bool> result = myMap.insert(1, 10);

  ASSERT_TRUE(result.second);  // Проверка, что элемент был успешно вставлен
  ASSERT_EQ((*(result.first)).first, 1);  // Проверка, что возвращенный итератор
                                          // указывает на вставленный элемент
  ASSERT_EQ(myMap.size(), 1);  // Проверка размера (должен быть 1)
}

TEST(MapInsertKeyObjTest, InsertExistingElement) {
  s21::map<int, int> myMap = {{1, 10}};
  std::pair<s21::map<int, int>::iterator, bool> result =
      myMap.insert(1, 20);  // Попытка вставить существующий элемент

  ASSERT_FALSE(result.second);  // Проверка, что элемент не был вставлен
  ASSERT_EQ((*(result.first)).second,
            10);  // Проверка, что возвращенный итератор
                  // указывает на существующий элемент
  ASSERT_EQ(myMap.size(), 1);  // Проверка размера (должен остаться прежним)
}

TEST(MapInsertOrAssignTest, InsertOrAssignNewElement) {
  s21::map<int, int> myMap;
  auto result = myMap.insert_or_assign(1, 10);

  ASSERT_EQ((*(result.first)).first, 1);  // Проверка, что возвращенный итератор
                                          // указывает на вставленный элемент
  ASSERT_EQ(myMap.size(), 1);  // Проверка размера (должен быть 1)
}

TEST(MapInsertOrAssignTest, InsertOrAssignExistingElement) {
  s21::map<int, int> myMap = {{1, 10}};
  auto result =
      myMap.insert_or_assign(1, 20);  // Попытка вставить существующий элемент

  ASSERT_EQ((*(result.first)).first, 1);  // Проверка, что возвращенный итератор
                                          // указывает на существующий элемент
  ASSERT_EQ((*(result.first)).second,
            20);  // Проверка, что значение элемента обновлено
  ASSERT_EQ(myMap.size(), 1);  // Проверка размера (должен остаться прежним)
}