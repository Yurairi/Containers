#ifndef SRC_S21_SET_H_
#define SRC_S21_SET_H_

#include "s21_tree/s21_tree.cc"

namespace s21 {
template <typename Key>
class set : public BinaryTree<Key> {
 public:
  using key_type = Key;
  using value_type = key_type;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BinaryTree<Key>::iterator;
  using const_iterator = const typename BinaryTree<Key>::const_iterator;
  using size_type = size_t;
  using BinaryTree<Key>::find;

  set();
  set(std::initializer_list<value_type> const &items);
  set(const set &s);
  set(set &&s);
  set<Key> &operator=(set<Key> &&other);

  ~set();
};
}  // namespace s21

#endif  //  SRC_S21_SET_H_