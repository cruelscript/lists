#include <iostream>
#include "ForwardList.hpp"

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

	return 0;
}
