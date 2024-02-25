#ifndef CPP2_S21_CONTAINERS_S21_VECTOR_S21_VECTOR_H
#define CPP2_S21_CONTAINERS_S21_VECTOR_S21_VECTOR_H

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <utility>

namespace s21 {
template <typename T>
class Vector {
 public:
  // Member type
  using value_type = T;
  using reference = T&;
  using iterator = T*;
  using const_reference = const T&;
  using const_iterator = const T*;
  using size_type = size_t;

  // Functions
  Vector();
  explicit Vector(size_type n);
  Vector(std::initializer_list<value_type> const& items);
  Vector(const Vector& v);
  Vector(Vector&& v);
  ~Vector();
  Vector& operator=(Vector&& v);
  Vector& operator=(const Vector& v);

  // Element access
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  T* data();

  // Iterators
  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  // Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  size_type capacity() const;
  void reserve(size_type size);
  void shrink_to_fit();

  // Modifiers
  void clear();
  void swap(Vector& other);
  void pop_back();
  void push_back(const_reference value);
  void erase(iterator pos);
  iterator insert(iterator pos, const_reference value);

 private:
  value_type* data_;
  size_type size_;
  size_type capacity_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_VECTOR_S21_VECTOR_H