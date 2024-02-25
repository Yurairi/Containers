#include "s21_stack.h"

namespace s21 {

template <typename T, typename Container>
Stack<T, Container>::Stack() : stk_() {}

template <typename T, typename Container>
Stack<T, Container>::Stack(
    std::initializer_list<typename Stack<T, Container>::value_type> const
        &items) {
  for (auto i = items.begin(); i != items.end(); i++) push(*i);
}

template <typename T, typename Container>
Stack<T, Container>::Stack(const Stack &other) : stk_(other.stk_) {}

template <typename T, typename Container>
Stack<T, Container>::Stack(Stack &&other) : stk_(std::move(other.stk_)) {}

template <typename T, typename Container>
Stack<T, Container>::~Stack() {}

template <typename T, typename Container>
typename Stack<T, Container>::const_reference Stack<T, Container>::top() const {
  return stk_.front();
}

template <typename T, typename Container>
typename Stack<T, Container>::size_type Stack<T, Container>::size() const {
  return stk_.size();
}

template <typename T, typename Container>
void Stack<T, Container>::push(const_reference value) {
  stk_.push_front(value);
}

template <typename T, typename Container>
void Stack<T, Container>::pop() {
  stk_.pop_front();
}

template <typename T, typename Container>
bool Stack<T, Container>::empty() const {
  return stk_.empty();
}

template <typename T, typename Container>
void Stack<T, Container>::swap(Stack &other) {
  std::swap(stk_, other.stk_);
}

template <typename T, typename Container>
Stack<T, Container> &Stack<T, Container>::operator=(const Stack &other) {
  if (this != &other) {
    stk_ = other.stk_;
  }
  return *this;
}

template <typename T, typename Container>
Stack<T, Container> &Stack<T, Container>::operator=(Stack &&other) noexcept {
  if (this != &other) {
    stk_ = std::move(other.stk_);
  }
  return *this;
}

}  // namespace s21
