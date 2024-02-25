#include "s21_queue.h"

namespace s21 {

template <typename T, typename Container>
Queue<T, Container>::Queue() : que_() {}

template <typename T, typename Container>
Queue<T, Container>::Queue(
    std::initializer_list<typename Queue<T, Container>::value_type> const
        &items)
    : que_(items) {}

template <typename T, typename Container>
Queue<T, Container>::Queue(const Queue &other) : que_(other.que_) {}

template <typename T, typename Container>
Queue<T, Container>::Queue(Queue &&other) : que_(std::move(other.que_)) {}

template <typename T, typename Container>
Queue<T, Container>::~Queue() {}

template <typename T, typename Container>
typename Queue<T, Container>::const_reference Queue<T, Container>::front()
    const {
  return que_.front();
}

template <typename T, typename Container>
typename Queue<T, Container>::const_reference Queue<T, Container>::back()
    const {
  return que_.back();
}

template <typename T, typename Container>
typename Queue<T, Container>::size_type Queue<T, Container>::size() const {
  return que_.size();
}

template <typename T, typename Container>
void Queue<T, Container>::push(const_reference value) {
  que_.push_back(value);
}

template <typename T, typename Container>
void Queue<T, Container>::pop() {
  que_.pop_front();
}

template <typename T, typename Container>
bool Queue<T, Container>::empty() const {
  return que_.empty();
}

template <typename T, typename Container>
void Queue<T, Container>::swap(Queue &other) {
  std::swap(que_, other.que_);
}

template <typename T, typename Container>
Queue<T, Container> &Queue<T, Container>::operator=(const Queue &other) {
  if (this != &other) {
    que_ = other.que_;
  }
  return *this;
}

template <typename T, typename Container>
Queue<T, Container> &Queue<T, Container>::operator=(Queue &&other) noexcept {
  if (this != &other) {
    que_ = std::move(other.que_);
  }
  return *this;
}

}  // namespace s21
