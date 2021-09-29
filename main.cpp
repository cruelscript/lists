#include <iostream>
#include <string>

#include "ForwardList.hpp"
#include "List.hpp"

int main()
{
	ForwardList<int> temp;
  std::cout << temp.front() << std::endl;

	temp.push_back(2);
	temp.push_back(3);
	temp.push_back(4);
	temp.print(std::cout);
	temp.push_front(1);

  std::cout << temp.back() << std::endl;

	temp.print(std::cout);
	temp.pop_back();
	temp.pop_back();
	temp.print(std::cout);
	temp.pop_front();
	temp.print(std::cout);

  List<std::string> list;
  std::cout << list.front() << std::endl;

  list.push_back("hello");
  list.push_back("hi");
  list.push_back("ola");
  list.print(std::cout);
  list.push_front("privet");

  std::cout << list.back() << std::endl;

  list.print(std::cout);
  list.pop_back();
  list.pop_back();
  list.print(std::cout);
  list.pop_front();
  list.print(std::cout);
  list.pop_back();
  list.print(std::cout);

	return 0;
}
