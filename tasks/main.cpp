#include <iostream>
#include "List.hpp"

int main()
{

	List test;
	test += 2;
	test += 1;
	test += 4;
	test += 5;
	test += 1;
	test += 3;
	std::cout << test << std::endl;

	List first;
	List second;
	if (first == second)
		std::cout << first << " is equal to " << second << std::endl;

	first += 1;
	second += 2;
	if (first == second)
		std::cout << "that shouldn't be printed";

	List third;
	if (first == third)
		std::cout << "that shouldn't be printed too";

	first += 2;
	first += 3;
	third += 1;
	third += 2;
	third += 3;
	third += 4;
	if (first == third)
		std::cout << "once again it won't be printed";

	List fourth;
	fourth += 4;
	List fifth = second & fourth;
	std::cout << second << " & " << fourth << " = " << fifth << std::endl;

	second += 5;
	fourth += 2;
	second += 4;
	fourth += 3;
	fourth += 6;

	List fifth1 = second & fourth;
	std::cout << second << " & " << fourth << " = " << fifth1 << std::endl;

	first += 7;
	first += 10;
	first += 6;
	first += 9;
	first += 8;
	first += 4;
	first += 5;

	third += 7;
	third += 9;
	third += 5;

	List fifth2 = first & third;
	std::cout << first << " & " << third << " = " << fifth2 << std::endl;

	List zero;

	List fifth3 = zero | fourth;
	std::cout << zero << " | " << fourth << " = " << fifth3 << std::endl;

	List sixth;
	sixth += 6;

	List seventh;
	seventh += 7;
	seventh += 6;

	List fifth4 = sixth | seventh;
	std::cout << sixth << " | " << seventh << " = " << fifth4 << std::endl;

	List eighth;
	eighth += 7;
	eighth += 19;
	eighth += 15;
	eighth += 3;
	eighth += 6;

	List nineth;
	nineth += 27;
	nineth += 15;
	nineth += 8;
	nineth += 13;
	nineth += 29;

	std::cout << eighth << " merges with " << nineth << "is equal to ";
	eighth.merge(nineth);
	std::cout << eighth << std::endl;

	List tenth;
	tenth += 4;
	tenth += 7;
	tenth += 5;

	List eleventh;
	eleventh += 4;
	eleventh += 8;
	eleventh += 5;

	std::cout << tenth << " merges with " << eleventh << "is equal to ";
	tenth.merge(eleventh);
	std::cout << tenth << std::endl;

	return 0;
}
