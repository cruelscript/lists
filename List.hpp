#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <exception>



template <typename T>
class List
{
  struct Node;

public:
  List() : front_(nullptr), back_(nullptr), size_(0) {};
  ~List();
  void insertBefore(const T& val, Node* pos);
  void push_front(const T&);
  void push_back(const T&);

  void remove(Node* pos);
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
    Node* prev_;
    explicit Node(const T& data, Node* next = nullptr, Node* prev = nullptr) :
      data_(data), next_(next), prev_(prev)
    {}
  };
  Node* front_;
  Node* back_;
  size_t size_;
};

template<typename T>
List<T>::~List()
{
  while (front_)
  {
    Node* current = front_;
    front_ = front_->next_;
    delete current;
  }
}

template<typename T>
void List<T>::insertBefore(const T& val, List<T>::Node* pos)
{
  Node* temp = new Node(val);
  size_++;
  temp->next_ = pos;

  if (pos)
  {
    temp->prev_ = pos->prev_;
    pos->prev_ = temp;
  }
  else
  {
    temp->prev_ = back_;
    back_ = temp;
  }
  if (temp->prev_)
  {
    temp->prev_->next_ = temp;
  }
  else
  {
    front_ = temp;
  }
}

template<typename T>
void List<T>::push_front(const T& e)
{
  insertBefore(e, front_);
}

template<typename T>
void List<T>::push_back(const T& e)
{
  insertBefore(e, nullptr);
}

template<typename T>
void List<T>::remove(List<T>::Node* pos)
{
  if (pos)
  {
    if (pos->prev_)
    {
      pos->prev_->next_ = pos->next_;
    }
    if (pos->next_)
    {
      pos->next_->prev_ = pos->prev_;
    }
    if (pos == front_)
    {
      front_ = front_->next_;
    }
    if (pos == back_)
    {
      back_ = back_->prev_;
    }
    delete pos;
    size_--;
  }
}

template<typename T>
void List<T>::pop_front()
{
  remove(front_);
}

template<typename T>
void List<T>::pop_back()
{
  remove(back_);
}

template<typename T>
void List<T>::print(std::ostream& out)
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

#endif // LIST_HPP
