#include <iostream>
#include <iomanip>

#include "tasks/Operator.hpp"

bool  testBalanceBrackets(const char* text, bool isList = true, int maxDepth = 30);
int   calculateDepth(const char* text);
char* transformToPostfix(const char* infix);
int   calculate(const char* postfix);

int main()
{
  try
  {
    const char* text00 = " ok ";
    std::cout << text00 << ": " << (testBalanceBrackets(text00) ? "right" : "wrong") << "\n";
    const char* text01 = "( ) ok ";
    std::cout<< text01 << ": " << (testBalanceBrackets(text01) ? "right" : "wrong") << "\n";
    const char* text02 = "( ( [] ) ) ok ";
    std::cout << text02 << ": " << (testBalanceBrackets(text02) ? "right" : "wrong") << "\n";
    const char* text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) OK";
    std::cout << text03 << ": " << (testBalanceBrackets(text03) ? "right" : "wrong") << "\n";
    const char* text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis ";
    std::cout << text04 << ": " << (testBalanceBrackets(text04) ? "right" : "wrong") << "\n";
    const char* text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
    std::cout << text05 << ": " << (testBalanceBrackets(text05) ? "right" : "wrong") << "\n";
    const char* text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
    std::cout << text06 << ": " << (testBalanceBrackets(text06) ? "right" : "wrong") << "\n";

    std::cout << text00 << ": " << calculateDepth(text00) << "\n";
    std::cout << text01 << ": " << calculateDepth(text01) << "\n";
    std::cout << text02 << ": " << calculateDepth(text02) << "\n";
    std::cout << text03 << ": " << calculateDepth(text03) << "\n";
    std::cout << text04 << ": " << calculateDepth(text04) << "\n";
    std::cout << text05 << ": " << calculateDepth(text05) << "\n";
    std::cout << text06 << ": " << calculateDepth(text06) << "\n";

    std::cout << "\n";

    const char* text07 = "(4*(6-3))+((8-6)/2)";
    const char* text08 = "(2+4)*(3+7)-1";
    const char* text09 = "4*(5-3)";
    const char* text10 = "2+2*2";
    const char* text11 = "1-2+5";


    std::cout << std::setw(20) << text07 << " [=] " << std::setw(12) << transformToPostfix(text07) << " [=] " << calculate(transformToPostfix(text07)) << "\n";
    std::cout << std::setw(20) << text08 << " [=] " << std::setw(12) << transformToPostfix(text08) << " [=] " << calculate(transformToPostfix(text08)) << "\n";
    std::cout << std::setw(20) << text09 << " [=] " << std::setw(12) << transformToPostfix(text09) << " [=] " << calculate(transformToPostfix(text09)) << "\n";
    std::cout << std::setw(20) << text10 << " [=] " << std::setw(12) << transformToPostfix(text10) << " [=] " << calculate(transformToPostfix(text10)) << "\n";
    std::cout << std::setw(20) << text11 << " [=] " << std::setw(12) << transformToPostfix(text11) << " [=] " << calculate(transformToPostfix(text11)) << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
  }
  return 0;
}
