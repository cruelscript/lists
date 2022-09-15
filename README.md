# Linked List

Here are some implementations of a template Linked list data structure.

### Tasks C++

List does not include repeating elements. List elements are in ascending order.

Implement these operations and constructors: 

- Constructor 
- Move Constructor
- Destructor
- Operation "+=" for adding elements to the list
- Operation "<<" for printing elements
- Operation "==" for comparing elements as a class method
- Operation "&" for creation a third list which contains elements from first AND second input lists as a friend function
- Operation "|" for creation a third list which contains elements from first OR second input lists as a friend function
- Merge method which adds elements from list to another, deleting it from the list where they were originally. 
(list1 [1, 2, 3], list2 [4, 5] => list1.merge(list2) => list1 [1, 2, 3, 4, 5], list2 [])

Element movement is done by pointer changing

Deleting elements does not cause memory leakage

Were accounted special cases when testing e.g. (null lists, lack of required elements, etc.)

# Stack

Here are some implementations of a Stack in C++ and Python. Constrained stack via array (StackArray) and stack 
via linked list (StackList) were derived from template abstract type class. 

Python Stack was derived from built-in deque.

StackArray was implemented using PImpl pattern. 

C++ data structures have their own exceptions derived from base class exception.

[Max Stack](./stack/max_stack.cpp) - Stack with a max function.

### Tasks

- Implementation of a function 'testBalanceBrackets' which checks correct parentheses. It returns true if the number of open parentheses matches with the number of close parentheses, and they have correct nesting structure. 
Also function has a parameter allowing us to choose between stack implementations.
- Implementation of a function 'transformToPostfix' which transforms correct arythmetic expression from infix form to postfix form
- Implementation of a function 'calculate' which (don't be shocked) calculates the postfix expression value
- Implementation of a class 'Operator' which describes arytmetic operations as a mathematic sign of an operation and its priority. 

# Queue

Here are some implementations of a queue data structure. There are two version in C++. 
From template abstract type class stack were derived constrained queue via array (QueueArray) 
and stack via linked list (QueueList).

C++ data structures have their own exceptions derived from base class exception. 
Python queue was constructed from built-in deque. 

Added methods for enqueue, dequeue and copy constructor. 