#ifndef CPP2_S21_CONTAINERS_S21_STACK_S21_STACK_H_
#define CPP2_S21_CONTAINERS_S21_STACK_S21_STACK_H_

#include "s21_deque/s21_deque.cc"

namespace s21 {

template <class T, class Container = Deque<T>>
class Stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  Stack();
  Stack(std::initializer_list<value_type> const &items);
  Stack(const Stack &other);
  Stack(Stack &&other);
  ~Stack();

  const_reference top() const;
  size_type size() const;

  void push(const_reference value);
  void pop();

  bool empty() const;
  void swap(Stack &other);

  Stack &operator=(const Stack &other);
  Stack &operator=(Stack &&other) noexcept;

 private:
  Container stk_;
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_STACK_S21_STACK_H_
