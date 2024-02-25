#include "s21_deque.h"

namespace s21 {

template <typename T>
Deque<T>::Deque() {
  dq_.head = nullptr;
  dq_.tail = nullptr;
  dq_.size = 0;
}

template <typename T>
Deque<T>::Deque(
    std::initializer_list<typename Deque<T>::value_type> const &items) {
  for (auto i = items.begin(); i != items.end(); i++) {
    push_back(*i);
  }
}

template <typename T>
Deque<T>::Deque(const Deque &other) {
  typename Deque<T>::Node *current = other.dq_.head;
  while (current) {
    push_back(current->val);
    current = current->next;
  }
}

template <typename T>
Deque<T>::Deque(Deque &&other) {
  swap(other);
}

template <typename T>
Deque<T>::~Deque() {
  while (!empty()) {
    pop_front();
  }
  dq_.size = 0;
}

template <typename T>
typename Deque<T>::size_type Deque<T>::size() const {
  return dq_.size;
}

template <typename T>
const typename Deque<T>::value_type &Deque<T>::front() const {
  return dq_.head->val;
}

template <typename T>
const typename Deque<T>::value_type &Deque<T>::back() const {
  return dq_.tail->val;
}

template <typename T>
void Deque<T>::swap(Deque &other) {
  std::swap(dq_.head, other.dq_.head);
  std::swap(dq_.tail, other.dq_.tail);
  std::swap(dq_.size, other.dq_.size);
}

template <typename T>
bool Deque<T>::empty() const {
  return dq_.size == 0;
}

template <typename T>
void Deque<T>::push_back(const_reference data) {
  std::unique_ptr<typename Deque<T>::Node> ptr(new typename Deque<T>::Node());
  ptr.get()->val = data;
  if (empty()) {
    dq_.head = dq_.tail = ptr.get();
  } else {
    dq_.tail->next = ptr.get();
    ptr->prev = dq_.tail;
    dq_.tail = ptr.get();
  }
  ptr.release();
  dq_.size++;
}

template <typename T>
void Deque<T>::push_front(const_reference data) {
  std::unique_ptr<typename Deque<T>::Node> ptr(new typename Deque<T>::Node());
  ptr.get()->val = data;
  if (empty()) {
    dq_.head = dq_.tail = ptr.get();
  } else {
    dq_.head->prev = ptr.get();
    ptr->next = dq_.head;
    dq_.head = ptr.get();
  }
  ptr.release();
  dq_.size++;
}

template <typename T>
void Deque<T>::pop_back() {
  if (empty()) return;
  typename Deque<T>::Node *tmp(dq_.tail);
  if (dq_.tail->prev == nullptr) {
    dq_.tail = dq_.head = nullptr;
  } else {
    dq_.tail = dq_.tail->prev;
  }
  delete tmp;
  dq_.size--;
}

template <typename T>
void Deque<T>::pop_front() {
  if (empty()) return;
  typename Deque<T>::Node *tmp(dq_.head);
  if (dq_.head->next == nullptr) {
    dq_.tail = dq_.head = nullptr;
  } else {
    dq_.head = dq_.head->next;
  }
  delete tmp;
  dq_.size--;
}

template <typename T>
Deque<T> &Deque<T>::operator=(const Deque &other) {
  if (this != &other) {
    while (!empty()) {
      pop_back();
    }
    typename Deque<T>::Node *current = other.dq_.head;
    while (current) {
      push_back(current->val);
      current = current->next;
    }
  }
  return *this;
}

template <typename T>
Deque<T> &Deque<T>::operator=(Deque &&other) noexcept {
  if (this != &other) {
    while (!empty()) {
      pop_back();
    }
    dq_.size = other.dq_.size;
    dq_.head = other.dq_.head;
    dq_.tail = other.dq_.tail;
    other.dq_.size = 0;
    other.dq_.head = nullptr;
    other.dq_.tail = nullptr;
  }
  return *this;
}

}  // namespace s21
