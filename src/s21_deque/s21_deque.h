#ifndef CPP2_S21_CONTAINERS_S21_DEQUE_S21_DEQUE_H_
#define CPP2_S21_CONTAINERS_S21_DEQUE_S21_DEQUE_H_

#include <memory>

namespace s21 {

template <typename T>
class Deque {
 public:
  using value_type = T;
  using size_type = std::size_t;
  using reference = T &;
  using const_reference = const T &;

  Deque();
  Deque(std::initializer_list<value_type> const &items);
  Deque(const Deque &other);
  Deque(Deque &&other);
  ~Deque();

  size_type size() const;
  const_reference front() const;
  const_reference back() const;

  void push_back(const_reference data);
  void push_front(const_reference data);
  void pop_back();
  void pop_front();

  bool empty() const;
  void swap(Deque &other);

  Deque &operator=(const Deque &other);
  Deque &operator=(Deque &&other) noexcept;

 private:
  struct Node {
    value_type val;
    Node *prev;
    Node *next;
  };
  struct List {
    size_type size = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
  };

  List dq_;
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_S21_DEQUE_S21_DEQUE_H_
