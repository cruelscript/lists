#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

#include <iostream>
#include <exception>

template <typename T>
class ForwardList
{
public:
  ForwardList() : front_(nullptr), back_(nullptr), size_(0)
    {};
  ~ForwardList();
  void push_front(const T&);
  void push_back(const T&);
  void pop_front();
  void pop_back();

  size_t size() const { return size_; };
  bool empty() const { return size_ == 0; };
  T front() const { return front_ ? front_->data_ : T(); };
  T back() const { return back_ ? back_->data_ : T(); };

  void print(std::ostream& out);

private:
  struct Node
  {
    T data_;
    Node* next_;
    explicit Node(const T& data, Node* next = nullptr) :
      data_(data), next_(next)
    {}
  };
  Node* front_;
  Node* back_;
  size_t size_;
};


template <typename T>
ForwardList<T>::~ForwardList()
{
  while (front_)
  {
    Node* current = front_;
    front_ = front_->next_;
    delete current;
  }
}

template<typename T>
void ForwardList<T>::push_front(const T& e)
{
  if (!front_)
  {
    front_ = new Node(e);
    back_ = front_;
    size_++;
    return;
  }
  front_ = new Node(e, front_);
  size_++;
}

template<typename T>
void ForwardList<T>::push_back(const T& e)
{
  if (!front_)
  {
    push_front(e);
    return;
  }
  Node* temp = back_;
  back_ = new Node(e);
  temp->next_ = back_;
  size_++;
}

template<typename T>
void ForwardList<T>::pop_front()
{
  if(!front_)
  {
    throw std::underflow_error("ForwardList: Error. ForwardList Underflow");
  }
  Node* temp = front_;
  front_ = front_->next_;
  delete temp;
  size_--;
}

template<typename T>
void ForwardList<T>::pop_back()
{
  if(!front_)
  {
    throw std::underflow_error("ForwardList: Error. ForwardList Underflow");
  }
  Node* temp = front_;
  while(temp->next_ != back_)
  {
    temp = temp->next_;
  }
  back_ = temp;
  back_->next_ = nullptr;
  delete temp->next_;
  size_--;
}

template<typename T>
void ForwardList<T>::print(std::ostream& out)
{
  out << "[";
  for (auto i = front_; i; i = i->next_)
  {
    out << i->data_;
    if (i->next_)
    {
      out << ", ";
    }
  }
  out << "]\n";
}

#endif
