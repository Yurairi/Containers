#ifndef CPP2_S21_CONTAINERS_S21_MAP_S21_MAP_H
#define CPP2_S21_CONTAINERS_S21_MAP_S21_MAP_H

#include <stdexcept>

#include "s21_tree/s21_tree.cc"

namespace s21 {
template <typename Key, typename T>
class map : public BinaryTree<std::pair<Key, T>> {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BinaryTree<value_type>::iterator;
  using const_iterator = const typename BinaryTree<value_type>::const_iterator;
  using size_type = size_t;

  map();
  map(std::initializer_list<value_type> const &items);
  map(const map &s);
  map(map &&s) noexcept;

  ~map();

  T &at(const Key &key);
  T &operator[](const Key &key);

  std::pair<iterator, bool> insert(const value_type &value);
  std::pair<iterator, bool> insert(const Key &key, const T &obj);
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);

 private:
  iterator find(const Key &key);
};
}  // namespace s21

#endif  //  CPP2_S21_CONTAINERS_S21_MAP_S21_MAP_H