#ifndef LIST_HPP
#define LIST_HPP

#include <iosfwd>

class List
{
public:
  List();
  List(List&&) noexcept;
  ~List();
  void insertHead(int);
  void insertTail(int);
  void merge(List&);
  List& operator=(List&& other) noexcept;
  bool operator += (int data);
  bool operator == (const List& other) const;
  List operator & (const List& other) const;
  List operator | (const List& other) const;
  friend std::ostream& operator << (std::ostream& out, const List& list);
private:
  class Node
  {
  public:
    int data_;
    Node* next_;
    explicit Node(int data, Node* next) :
      data_(data), next_(next)
    {}
  };
  Node* head_;
  Node* tail_;
};
#endif
