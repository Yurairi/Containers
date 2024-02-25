#include "s21_vector.h"
namespace s21 {

template <typename value_type>
Vector<value_type>::Vector() : data_(nullptr), size_(0U), capacity_(0U) {}

template <typename value_type>
Vector<value_type>::Vector(size_type n)
    : data_(n ? new value_type[n] : nullptr), size_(n), capacity_(n) {}

template <typename value_type>
Vector<value_type>::Vector(std::initializer_list<value_type> const& items) {
  size_ = items.size();
  capacity_ = items.size();
  data_ = new value_type[capacity_];
  std::copy(items.begin(), items.end(), data_);
}

template <typename value_type>
Vector<value_type>::Vector(const Vector& v) {
  capacity_ = v.capacity_;
  size_ = v.size_;
  value_type* tmp = new value_type[capacity_];
  for (size_type i = 0; i < size_; i++) {
    tmp[i] = v.data_[i];
  }
  data_ = tmp;
}

template <typename value_type>
Vector<value_type>::Vector(Vector&& v)
    : data_(v.data_), size_(v.size_), capacity_(v.capacity_) {
  v.data_ = nullptr;
  v.size_ = 0;
  v.capacity_ = 0;
}

template <typename value_type>
Vector<value_type>::~Vector() {
  clear();
}

template <typename value_type>
Vector<value_type>& Vector<value_type>::operator=(const Vector& v) {  // LOOK
  if (this != &v) {
    Vector temp(v);
    swap(temp);
  }
  return *this;
}

template <typename value_type>
Vector<value_type>& Vector<value_type>::operator=(Vector&& v) {  // LOOK
  if (this != &v) {
    Vector temp(std::move(v));
    swap(temp);
  }
  return *this;
}

template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::at(size_type pos) {
  return data_[pos];
}

template <typename value_type>
typename Vector<value_type>::reference Vector<value_type>::operator[](
    size_type pos) {
  return at(pos);
}

template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::front() {
  return data_[0];
}

template <typename value_type>
typename Vector<value_type>::const_reference Vector<value_type>::back() {
  return data_[size_ - 1];
}

template <typename value_type>
value_type* Vector<value_type>::data() {
  return data_;
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::begin() {
  return data_;
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::end() {
  return data_ + size_;
}

template <typename value_type>
bool Vector<value_type>::empty() const {
  return size_ == 0;
}

template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::size() const {
  return size_;
}

template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::max_size() const {
  return std::numeric_limits<size_type>::max() / sizeof(value_type) / 2;
}

template <typename value_type>
void Vector<value_type>::reserve(size_type size) {
  if (size > capacity_) {
    value_type* new_data =
        static_cast<value_type*>(operator new(size * sizeof(new_data)));
    for (size_type i = 0; i < size_; ++i) {
      new (new_data + i) value_type(std::move(data_[i]));
      (data_ + i)->~value_type();
    }
    operator delete(data_);
    data_ = new_data;
    capacity_ = size;
  }
}

template <typename value_type>
typename Vector<value_type>::size_type Vector<value_type>::capacity() const {
  return capacity_;
}

template <typename value_type>
void Vector<value_type>::shrink_to_fit() {
  reserve(size_);
}

template <typename value_type>
void Vector<value_type>::clear() {
  delete[] data_;
  data_ = nullptr;
  size_ = 0U;
  capacity_ = 0U;
}

template <typename value_type>
typename Vector<value_type>::iterator Vector<value_type>::insert(
    iterator pos, const_reference value) {
  reserve(size_ + 1);

  iterator iter = data_ + (pos - data_);
  for (iterator it = data_ + size_; it != iter; --it) {
    *it = *(it - 1);
  }

  *iter = value;
  ++size_;
  return iter;
}

template <typename value_type>
void Vector<value_type>::erase(iterator pos) {
  if (pos < data_ || pos >= data_ + size_) {
    throw "Vector::erase index out of range";
  }

  for (iterator it = pos; it != data_ + size_ - 1; ++it) {
    *it = *(it + 1);
  }

  (data_ + size_ - 1)->~value_type();
  --size_;
}

template <typename value_type>
void Vector<value_type>::push_back(const_reference value) {
  if (size_ >= capacity_) {
    reserve(capacity_ == 0 ? 1 : capacity_ * 2);
  }
  new (data_ + size_) value_type(value);
  ++size_;
}

template <typename value_type>
void Vector<value_type>::pop_back() {
  if (size_ > 0) {
    (data_ + size_ - 1)->~value_type();
    --size_;
  }
}

template <typename value_type>
void Vector<value_type>::swap(Vector& other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

}  // namespace s21