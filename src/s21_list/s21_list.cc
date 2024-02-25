#include "s21_list.h"

namespace s21 {

// class Node
template <typename value_type>
List<value_type>::Node::Node(value_type data) {
  this->data = data;
  this->prev = this->next = nullptr;
}

// class List
template <typename value_type>
List<value_type>::List() : head_(nullptr), tail_(nullptr), count_node_(0) {
  end_ = new Node(count_node_);
}

template <typename value_type>
List<value_type>::List(size_type n) : List<value_type>::List() {
  for (size_type i = 0; i < n; ++i) {
    push_back(value_type{});
  }
}

template <typename value_type>
List<value_type>::List(std::initializer_list<value_type> const& items)
    : List<value_type>::List() {
  for (const value_type& item : items) {
    push_back(item);
  }
}

template <typename value_type>
List<value_type>::List(const List& l) : List<value_type>::List() {
  for (Node* ptr = l.head_; ptr != l.end_; ptr = ptr->next) {
    push_back(ptr->data);
  }
}

template <typename value_type>
List<value_type>::List(List&& l) noexcept
    : head_(l.head_), tail_(l.tail_), end_(l.end_), count_node_(l.count_node_) {
  l.head_ = l.tail_ = l.end_ = nullptr;
  l.count_node_ = 0;
}

template <typename value_type>
List<value_type>::~List() {
  clear();
}

template <typename value_type>
List<value_type>& List<value_type>::operator=(const List& l) {
  if (this != &l) {  // Проверка на самоприсваивание
    List temp(l);
    swap(temp);
  }
  return *this;
}

template <typename value_type>
List<value_type>& List<value_type>::operator=(List&& l) noexcept {
  if (this != &l) {  // Проверка на самоприсваивание
    List temp(std::move(l));
    swap(temp);
  }
  return *this;
}

template <typename value_type>
typename List<value_type>::const_reference List<value_type>::front() const {
  if (head_ != nullptr) {
    return head_->data;
  }
  // Обработка случая, когда список пуст
  throw "List is empty.";
}

template <typename value_type>
typename List<value_type>::const_reference List<value_type>::back() const {
  if (tail_ != nullptr) {
    return tail_->data;
  }
  // Обработка случая, когда список пуст
  throw "List is empty.";
}

template <typename value_type>
typename List<value_type>::iterator List<value_type>::begin() {
  return iterator(head_);
}

template <typename value_type>
typename List<value_type>::iterator List<value_type>::end() {
  return iterator(end_);
}

template <typename value_type>
typename List<value_type>::const_iterator List<value_type>::cbegin() const {
  return iterator(head_);
}

template <typename value_type>
typename List<value_type>::const_iterator List<value_type>::cend() const {
  return iterator(end_);
}

template <typename value_type>
bool List<value_type>::empty() const noexcept {
  return count_node_ == 0;
}

template <typename value_type>
typename List<value_type>::size_type List<value_type>::size() const {
  return count_node_;
}

template <typename value_type>
typename List<value_type>::size_type List<value_type>::max_size() const {
  return std::numeric_limits<size_type>::max();
}

template <typename value_type>
void List<value_type>::clear() {
  while (count_node_) {
    pop_back();
  }
  delete end_;
  end_ = nullptr;
}

template <typename value_type>
typename List<value_type>::iterator List<value_type>::insert(
    iterator pos, const_reference value) {
  if (pos == begin()) {
    push_front(value);
  } else if (pos == end()) {
    push_back(value);
  } else {
    Node* new_node = new Node(value);
    Node* cur_node = pos.node_;
    new_node->next = cur_node;
    new_node->prev = cur_node->prev;
    cur_node->prev->next = new_node;
    cur_node->prev = new_node;
    count_node_++;
    relate_end();
  }
  return pos;
}

template <typename value_type>
void List<value_type>::erase(iterator pos) {
  if (pos.node_ == head_) {
    pop_front();
  } else if (pos.node_ == tail_) {
    pop_back();
  } else {
    pos.node_->next->prev = pos.node_->prev;
    pos.node_->prev->next = pos.node_->next;
    delete pos.node_;
    count_node_--;
  }
}

template <typename value_type>
void List<value_type>::push_back(const_reference value) {
  Node* ptr = new Node(value);
  if (tail_ != nullptr) {
    ptr->prev = tail_;
    tail_->next = ptr;
  } else {
    head_ = ptr;
  }
  tail_ = ptr;
  count_node_++;
  relate_end();
}

template <typename value_type>
void List<value_type>::push_front(const_reference value) {
  Node* ptr = new Node(value);
  if (head_ != nullptr) {
    ptr->next = head_;
    head_->prev = ptr;
  } else {
    tail_ = ptr;
  }
  head_ = ptr;
  count_node_++;
  relate_end();
}

template <typename value_type>
void List<value_type>::pop_front() {
  if (head_ == nullptr) throw "list is empty";
  Node* ptr = head_;
  if (count_node_ == 1) {
    head_ = tail_ = nullptr;
  } else {
    head_ = head_->next;
    head_->prev = nullptr;
  }
  delete ptr;

  count_node_--;
  relate_end();
}

template <typename value_type>
void List<value_type>::pop_back() {
  if (tail_ == nullptr) throw "list is empty";
  Node* ptr = tail_;
  if (count_node_ == 1) {
    head_ = tail_ = nullptr;
  } else {
    tail_ = tail_->prev;
    tail_->next = nullptr;
  }
  delete ptr;

  count_node_--;
  relate_end();
}

template <typename value_type>
void List<value_type>::relate_end() {
  if (end_ != nullptr) {
    end_->next = head_;
    end_->prev = tail_;
    end_->data = count_node_;
  }
  if (head_ != nullptr) head_->prev = end_;
  if (tail_ != nullptr) tail_->next = end_;
}

template <typename value_type>
void List<value_type>::swap(List& other) {
  std::swap(head_, other.head_);
  std::swap(tail_, other.tail_);
  std::swap(end_, other.end_);
  std::swap(count_node_, other.count_node_);
}

template <typename value_type>
void List<value_type>::merge(List& other) {
  if (this == &other || other.empty()) return;

  List mergedList;
  iterator it1 = begin();
  iterator it2 = other.begin();

  while (it1 != end() && it2 != other.end()) {
    if (*it1 < *it2) {
      mergedList.push_back(*it1);
      ++it1;
    } else {
      mergedList.push_back(*it2);
      ++it2;
    }
  }
  while (it1 != end()) {
    mergedList.push_back(*it1);
    ++it1;
  }
  while (it2 != other.end()) {
    mergedList.push_back(*it2);
    ++it2;
  }

  other.clear();
  swap(mergedList);
}

template <typename value_type>
void List<value_type>::splice(const_iterator pos, List& other) {
  for (auto it_ = other.begin(); it_ != other.end(); ++it_) {
    insert(pos, *it_);
  }
  other.clear();
}

template <typename value_type>
void List<value_type>::reverse() {
  Node* head_ = this->head_;
  Node* tail_ = this->tail_;
  for (size_t i = 0; i < size() / 2; i++) {
    std::swap(tail_->data, head_->data);
    head_ = head_->next;
    tail_ = tail_->prev;
  }
}

template <typename value_type>
void List<value_type>::unique() {
  for (auto it{begin()}; it != end(); ++it) {
    if (it.node_->data == it.node_->prev->data) {
      erase(it.node_->prev);
    }
  }
}

template <typename value_type>
void List<value_type>::sort() {
  if (count_node_ > 1) {
    for (auto i = begin(); i != end(); ++i) {
      for (auto j = begin(), j1 = ++begin(); j != --end(); ++j, ++j1) {
        if (j.node_->data > j1.node_->data) {
          std::swap(j1.node_->data, j.node_->data);
        }
      }
    }
  }
}

template <typename value_type>
List<value_type>::ListIterator::ListIterator() : node_(nullptr) {}

template <typename value_type>
List<value_type>::ListIterator::ListIterator(Node* node) : node_(node) {}

template <typename value_type>
typename List<value_type>::reference
List<value_type>::ListIterator::operator*() {
  return node_->data;
}

template <typename value_type>
typename List<value_type>::value_type*
List<value_type>::ListIterator::operator->() const {
  return &node_->data;
}

template <typename value_type>
typename List<value_type>::ListIterator&
List<value_type>::ListIterator::operator++() {
  node_ = node_->next;
  return *this;
}

template <typename value_type>
typename List<value_type>::ListIterator
List<value_type>::ListIterator::operator++(int) {
  ListIterator temp(*this);
  operator++();
  return temp;
}

template <typename value_type>
typename List<value_type>::ListIterator&
List<value_type>::ListIterator::operator--() {
  if (node_->prev != nullptr) node_ = node_->prev;
  return *this;
}

template <typename value_type>
typename List<value_type>::ListIterator
List<value_type>::ListIterator::operator--(int) {
  ListIterator temp(*this);
  operator--();
  return temp;
}

template <typename value_type>
void List<value_type>::ListIterator::advance(int n) {
  if (n > 0) {
    for (int i = 0; i < n && node_ != nullptr; ++i) node_ = node_->next;
  } else if (n < 0) {
    for (int i = 0; i < -n && node_ != nullptr; ++i) node_ = node_->prev;
  }
}

template <typename value_type>
bool List<value_type>::ListIterator::operator==(
    const ListIterator& other) const {
  return node_ == other.node_;
}

template <typename value_type>
bool List<value_type>::ListIterator::operator!=(
    const ListIterator& other) const {
  return node_ != other.node_;
}

template <typename value_type>
bool List<value_type>::ListIterator::operator<(
    const ListIterator& other) const {
  return node_ < other.node_;
}

template <typename value_type>
bool List<value_type>::ListIterator::operator<=(
    const ListIterator& other) const {
  return node_ <= other.node_;
}

template <typename value_type>
bool List<value_type>::ListIterator::operator>(
    const ListIterator& other) const {
  return node_ > other.node_;
}

template <typename value_type>
bool List<value_type>::ListIterator::operator>=(
    const ListIterator& other) const {
  return node_ >= other.node_;
}

// class ListConstIterator
template <typename value_type>
List<value_type>::ListConstIterator::ListConstIterator() : ListIterator() {}

template <typename value_type>
List<value_type>::ListConstIterator::ListConstIterator(const ListIterator& node)
    : ListIterator(node) {}

template <typename value_type>
typename List<value_type>::const_reference
List<value_type>::ListConstIterator::operator*() const {
  return operator*();
}

template <typename value_type>
typename List<value_type>::const_iterator&
List<value_type>::ListConstIterator::operator++() {
  ListIterator::node_ = ListIterator::node_->next;
  return *this;
}

}  // namespace s21