#include "List.hpp"
#include <iostream>
List::List() :
  head_(nullptr), tail_(nullptr)
{}

List::List(List&& that) noexcept :
  head_(that.head_), tail_(that.tail_)
{
  that.head_ = nullptr;
  that.tail_ = nullptr;
}

List::~List()
{
  while (head_)
  {
    Node* current = head_;
    head_ = head_->next_;
    delete current;
  }
}

void List::insertHead(int data)
{
  if (!head_)
  {
    head_ = new Node(data, nullptr);
    tail_ = head_;
    return;
  }
  head_ = new Node(data, head_);
}

void List::insertTail(int data)
{
  if (!tail_)
  {
    tail_ = new Node(data, nullptr);
    head_ = tail_;
    return;
  }
  Node* temp = tail_;
  tail_ = new Node(data, nullptr);
  temp->next_ = tail_;
}

List& List::operator=(List&& other) noexcept
{
  if(this == &other)
  {
    other.head_ = nullptr;
    other.tail_ = nullptr;
    return *this;
  }
  List copy(std::move(other));
  std::swap(head_, copy.head_);
  std::swap(tail_, copy.tail_);
  return *this;
}

bool List::operator+=(int data)
{
  if (!head_)
  {
    insertHead(data);
    return true;
  }

  Node* current = head_;

  while (current)
  {
    if (data > current->data_)
    {
      if (current == tail_)
      {
        insertTail(data);
        return true;
      }
      current = current->next_;
    }
    if (data < current->data_)
    {
      if (!current->next_)
      {
        std::swap(current->data_, data);
        current->next_ = new Node(data, current->next_);
        tail_ = current->next_;
      }
      else {
        std::swap(current->data_, data);
        current->next_ = new Node(data, current->next_);
      }
      return true;
    }
    if (data == current->data_)
      return false;
  }
  return true;
}

bool List::operator==(const List& other) const
{
  if (!this->head_ && !other.head_)
    return true;
  if ((!this->head_ && other.head_) || (this->head_ && !other.head_))
    return false;

  if(this->head_ && other.head_)
  {
    Node* thisList;
    Node* otherList;

    for (thisList = this->head_, otherList = other.head_;
         thisList && otherList;
         thisList = thisList->next_, otherList = otherList->next_)
    {
      if (thisList->data_ != otherList->data_)
        return false;
    }
    return !((!thisList && otherList) || (thisList && !otherList));
  }
}

List List::operator&(const List& other) const
{
  List current;

  if (!this->head_ && !other.head_)
    return current;
  if ((!this->head_ && other.head_) || (this->head_ && !other.head_))
    return current;

  Node* thisList;
  Node* otherList;

  for (thisList = this->head_, otherList = other.head_;
       thisList && otherList;
       thisList = thisList->next_, otherList = otherList->next_)
  {
    while (thisList->data_ < otherList->data_)
      if (thisList->next_)
        thisList = thisList->next_;
      else break;

    while (thisList->data_ > otherList->data_)
      if (otherList->next_)
        otherList = otherList->next_;
      else break;

    if (thisList->data_ == otherList->data_)
    {
      current.insertTail(thisList->data_);
    }
  }
  return current;
}

List List::operator|(const List& other) const
{
  List current;

  if (!this->head_ && !other.head_)
    return current;

  if (!this->head_ && other.head_)
  {
    current.head_ = other.head_;
    current.tail_ = other.tail_;
    return current;
  }

  if (this->head_ && !other.head_)
  {
    current.head_ = this->head_;
    current.tail_ = this->tail_;
    return current;
  }

  current.head_ = this->head_;
  current.tail_ = this->tail_;

  for (Node* i = other.head_; i; i = i->next_)
    current += i->data_;
  return current;
}

std::ostream& operator<<(std::ostream& out, const List& list)
{
  if (!list.head_)
  {
    out << "{Empty List}";
    return out;
  }

  out << "{";
  for (List::Node* i = list.head_; i; i = i->next_)
  {
    out << i->data_;
    if (i->next_)
      out << ", ";
  }
  out << "}";

  return out;
}

void List::merge(List& other)
{
  if ((!head_ && !other.head_) || (head_ && !other.head_))
    return;
  if (!head_ && other.head_)
  {
    *this = std::move(other);
  }
  if(head_ && other.head_)
  {
    Node* thisList = this->head_;
    Node* otherList = other.head_;

    while (otherList)
    {
      if (!thisList) // Если все элементы this больше чем other
      {
        insertHead(otherList->data_);
        otherList = otherList->next_;
      }

      if (!thisList->next_) // условие выполняется, когда все элементы this кроме последнего больше other
      {
        *this += otherList->data_; // += только из-за проверки на неодинаковость. Вызываться будет InsertTail
        otherList = otherList->next_;
      }

      else
      {
        if (otherList->data_ == thisList->data_)
          otherList = otherList->next_;

        else if (otherList->data_ > thisList->data_)
          thisList = thisList->next_;

        else if (otherList->data_ < thisList->data_) // меняем значения и переходим на следующий элемент
        {
          Node* temp = otherList;
          std::swap(thisList->data_, otherList->data_);
          otherList = temp->next_;

          if (thisList->next_)
            temp->next_ = thisList->next_;

          else temp->next_ = otherList;

          thisList->next_ = temp;
          thisList = temp;
        }
      }
    }
    other.head_ = nullptr;
    other.tail_ = nullptr;
  }
}
