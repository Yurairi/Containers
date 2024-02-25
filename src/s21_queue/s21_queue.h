#ifndef CPP2_S21_CONTAINERS_S21_QUEUE_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_S21_QUEUE_S21_QUEUE_H_

#include "s21_deque/s21_deque.cc"

namespace s21 {

template <class T, class Container = Deque<T>>
class Queue {
 public:
  using value_type = T;
  using size_type = std::size_t;
  using reference = T &;
  using const_reference = const T &;

  Queue();
  Queue(std::initializer_list<value_type> const &items);
  Queue(const Queue &other);
  Queue(Queue &&other);
  ~Queue();

  const_reference front() const;
  const_reference back() const;
  size_type size() const;

  void push(const_reference value);
  void pop();

  bool empty() const;
  void swap(Queue &other);

  Queue &operator=(const Queue &other);
  Queue &operator=(Queue &&other) noexcept;

 private:
  Container que_;
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_QUEUE_S21_QUEUE_H_
