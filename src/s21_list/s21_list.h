#ifndef CPP2_S21_CONTAINERS_S21_LIST_S21_LIST_H
#define CPP2_S21_CONTAINERS_S21_LIST_S21_LIST_H

#include <limits>
#include <stdexcept>

namespace s21 {

template <typename T>
class List {
 public:
  class ListIterator;
  class ListConstIterator;

  // Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

  // Functions
  List();
  explicit List(size_type n);
  List(std::initializer_list<value_type> const &items);
  List(const List &l);
  List(List &&l) noexcept;
  ~List();
  List &operator=(const List &l);
  List &operator=(List &&l) noexcept;

  // Element access
  const_reference front() const;
  const_reference back() const;

  // Iterators
  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;

  // Capacity
  bool empty() const noexcept;
  size_type size() const;
  size_type max_size() const;

  // Modifiers
  void sort();
  void clear();
  void unique();
  void reverse();
  void pop_back();
  void pop_front();
  void swap(List &other);
  void merge(List &other);
  void erase(iterator pos);
  void push_back(const_reference value);
  void push_front(const_reference value);
  iterator insert(iterator pos, const_reference value);
  void splice(const_iterator pos, List &other);
  void splice(const_iterator pos, List &other, const_iterator first,
              const_iterator last);

 private:
  class Node {
   public:
    value_type data;
    Node *prev, *next;

    Node(value_type data);
  };

  Node *head_, *tail_, *end_;
  size_type count_node_;

  void relate_end();
};

template <typename T>
class List<T>::ListIterator {
 public:
  friend class List;

  ListIterator();
  ListIterator(Node *node);
  // ListIterator(Node *node, Node *last_node);

  reference operator*();
  value_type *operator->() const;
  ListIterator &operator++();
  ListIterator operator++(int);
  ListIterator &operator--();
  ListIterator operator--(int);
  void advance(int n);
  bool operator==(const ListIterator &other) const;
  bool operator!=(const ListIterator &other) const;
  bool operator<(const ListIterator &other) const;
  bool operator<=(const ListIterator &other) const;
  bool operator>(const ListIterator &other) const;
  bool operator>=(const ListIterator &other) const;

 private:
  Node *node_;
};

template <typename T>
class List<T>::ListConstIterator : public List<T>::ListIterator {
 public:
  ListConstIterator();
  ListConstIterator(const ListIterator &node);
  const_reference operator*() const;
  ListConstIterator &operator++();
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_LIST_S21_LIST_H