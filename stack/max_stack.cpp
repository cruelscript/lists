#include <iostream>
#include <stack>
#include <sstream>

int main()
{
  std::stack<int> stack;
  std::stack<int> stack_m;

  size_t size;
  std::cin >> size;

  for (size_t i = 0; i < size; ++i)
  {
    std::string str;
    std::getline(std::cin >> std::ws, str);

    std::stringstream sin(str);
    std::string command;
    sin >> command;

    if (command == "push")
    {
      int number;
      sin >> number;

      stack.push(number);

      stack_m.push((stack_m.empty() ? number : std::max(stack_m.top(), number)));

    }
    if (command == "pop")
    {
      stack.pop();
      stack_m.pop();
    }
    if (command == "max")
    {
      std::cout << (stack.empty() ? 0 : stack_m.top());
      std::cout << "\n";
    }
  }
  return 0;
}