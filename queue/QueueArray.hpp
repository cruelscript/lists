#ifndef QUEUEARRAY_HPP
#define QUEUEARRAY_HPP

#include <ostream>
#include "Queue.hpp"
#include "exceptions.hpp"

template <class T>
class QueueArray : public Queue<T>
{
public:
  explicit QueueArray(int size = 100);
  QueueArray(const QueueArray<T>& src);
  virtual ~QueueArray();
  void     enQueue(const T& e)          override;
  T        deQueue()                    override;
  bool     isEmpty()              const override;
  void     out(std::ostream& out) const override;
private:
  T* array_;
  int head_ = 1;
  int tail_ = 1;
  int size_;
};

template<class T>
QueueArray<T>::QueueArray(int size)
{
  try
  {
    array_ = new T[size_ = size + 1];
  }
  catch (...)
  {
    throw WrongQueueSize();
  }
  head_ = 1;
  tail_ = 1;
}

template<class T>
QueueArray<T>::QueueArray(const QueueArray<T> & src)
{
  try
  {
    array_ = new T[size_ = src.size_];
  }
  catch (...)
  {
    throw WrongQueueSize();
  }
  for (size_t i = 0; i < size_; i++)
  {
    array_[i] = src.array_[i];
  }
  head_ = src.head_;
  tail_ = src.tail_;
}

template<class T>
void QueueArray<T>::enQueue(const T & e)
{
  if (head_ == tail_ + 1)
    throw QueueOverflow();

  array_[tail_] = e;
  tail_ = (tail_ == size_) ? 1 : tail_ + 1;
}

template<class T>
T QueueArray<T>::deQueue()
{
  if (head_ == tail_)
    throw QueueUnderflow();

  int x = head_;
  head_ = (head_ == size_) ? 1 : head_ + 1;
  return array_[x];
}

template<class T>
QueueArray<T>::~QueueArray()
{
  delete[] array_;
}

template<class T>
bool QueueArray<T>::isEmpty() const
{
  return head_ == tail_;
}

template<class T>
void QueueArray<T>::out(std::ostream& out) const
{
  if(head_ < tail_)
    for (size_t i = head_ ; i < tail_; i++)
      out << array_[i] << " ";

  if(head_ > tail_)
  {
    for (size_t i = head_; i < size_; i++)
      out << array_[i] << " ";
    for (size_t i = 1; i < tail_; i++)
      out << array_[i] << " ";
  }
}
#endif
