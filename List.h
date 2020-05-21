#include <iostream>

class List {
private:
    class Node
    {
    public:
        int data_;
        Node* next_;
        Node() : data_(0), next_(nullptr) {};
        Node(int data, Node* next) : data_(data), next_(next) {};
    };
    Node* head_;
    Node* tail_;
public:
    List() : head_(nullptr), tail_(nullptr) {};
    List(List&& thisList)noexcept;
    void operator=(List&& other)noexcept;
    bool operator += (int data);
    bool operator == (const List& other) const;
    List operator & (const List& other) const;
    List operator | (const List& other) const;
    void merge(List& other);
    void insertHead(int data);
    void insertTail(int data);
    friend std::ostream& operator << (std::ostream& out, const List& list);
    ~List();
};
