#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP

#include <cassert>
#include <algorithm>
#include "Stack.hpp"
#include "exceptions.hpp"

template <class T>
class StackImpl;

template <class T>
class StackArray : public Stack<T>
{
public:
  StackArray(size_t size = 0);
  StackArray(const StackArray& rhs);
  StackArray& operator=(const StackArray& rhs);
  ~StackArray() = default;
  void     push(const T& e) override;
  void     pop() override;
  T&       top() override ;
  bool     isEmpty() override ;
  size_t   size() const;
private:
  StackImpl<T>* impl_;
};

template <class T>
class StackImpl
{
public:
  StackImpl(size_t size = 0);
  StackImpl(const StackImpl& ) = delete;
  StackImpl& operator=(const StackImpl& ) = delete;
  ~StackImpl();

  void Swap(StackImpl& rhs) noexcept;

  T* array_;
  size_t size_;
  size_t capacity_;
};

template<class T>
StackImpl<T>::StackImpl(size_t size):
  array_(size == 0 ? nullptr : operator new(sizeof(T)* size)),
  capacity_(size),
  size_(0)
{}

template<class T>
StackImpl<T>::~StackImpl()
{
  destroy(array_, array_ + size_);
  operator delete(array_);
}

template<class T>
void StackImpl<T>::Swap(StackImpl& rhs) noexcept
{
  std::swap(array_, rhs.array_);
  std::swap(size_, rhs.size_);
  std::swap(capacity_, rhs.capacity_);
}


template <class T>
StackArray<T>::StackArray(size_t size):
  impl_(size)
{}

template <class T>
StackArray<T>::StackArray(const StackArray<T>& rhs):
  impl_(rhs.impl_.size_)
{
    while(impl_->size_ < rhs.impl_->size_)
    {
      construct(impl_->array_ + impl_->size_, rhs.impl_->array_[impl_->size_]);
      ++impl_->size_;
    }
}

template<class T>
StackArray<T>& StackArray<T>::operator=(const StackArray& rhs)
{
  StackArray temp(rhs);
  impl_->Swap(temp.impl_);
  return *this;
}

template <class T>
void StackArray<T>::push(const T& e)
{
  if(impl_->size_ == impl_->capacity_)
  {
    StackArray temp(impl_->size_ * 2 + 1);

    while(temp.size() < impl_->size_)
    {
      temp.push(impl_->array_[temp.size()]);
    }
    temp.push(e);
    impl_->Swap(temp.impl_);
  }
  else
  {
    construct(impl_->array_ + impl_->size_, e);
    ++impl_->size_;
  }
}

template <class T>
void StackArray<T>::pop()
{
  if (impl_->size_ == 0)
  {
    throw StackUnderflow();
  }
  else
  {
    --impl_->size_;
    destroy(impl_->array_ + impl_->size_);
  }
}

template<class T>
T& StackArray<T>::top()
{
  if(impl_->size_ == 0)
  {
    throw EmptyStack();
  }
  else
  {
    return impl_->array_[impl_->size_ - 1];
  }
}

template<class T>
bool StackArray<T>::isEmpty()
{
  return impl_->size_ == 0;
}

template<class T>
size_t StackArray<T>::size() const
{
  return impl_->size_;
}

#endif
