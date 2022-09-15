#ifndef QUEUELIST_HPP
#define QUEUELIST_HPP

#include <ostream>
#include "Queue.hpp"

template <class T>
class QueueList : public Queue<T>
{
public:
  QueueList();
  virtual ~QueueList();
  void     enQueue(const T& e)          override;
  T        deQueue()                    override;
  bool     isEmpty()              const override;
  void     out(std::ostream& out) const override;
private:
  class Node
  {
  public:
    Node(const T& data, Node* next) :
      data_(data), next_(next)
    {}
    T data_;
    Node* next_;
  };
  Node* head_;
  Node* tail_;
};

template <class T>
QueueList<T>::QueueList(): head_(nullptr), tail_(nullptr) {}

template<class T>
QueueList<T>::~QueueList()
{
  Node* temp = head_;

  while(temp)
  {
    temp = head_->next_;
    delete head_;
    head_ = temp;
  }
}

template<class T>
void QueueList<T>::enQueue(const T & e)
{
  Node* temp = new Node(e, nullptr);

  if(head_)
  {
    tail_->next_ = temp;
    tail_ = temp;
  }
  else
  {
    head_ = tail_ = temp;
  }
}

template<class T>
T QueueList<T>::deQueue()
{
  if (!head_)
    throw QueueUnderflow();

  Node* temp = head_;
  T data = head_->data_;
  head_ = head_->next_;
  delete temp;
  return data;
}

template<class T>
bool QueueList<T>::isEmpty() const
{
  return head_;
}

template<class T>
void QueueList<T>::out(std::ostream& out) const
{
  Node* temp = head_;
  while(temp)
  {
    out << temp->data_ << " ";
    temp = temp->next_;
  }
  out << "\n";
}
#endif
