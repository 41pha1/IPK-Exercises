#include <iostream>

void collatz(int number)
{
	while(true)
	{
		std::cout << number << std::endl;

		if(number == 1 || number == 0 || number == -1 || number == -5 || number == -17)
			return;

		if(number % 2 == 0)
			number = number/2;
		else
			number = number * 3 + 1;
	}
}


int main()
{
	int number;

	while(true)
	{
		std::cout << "Zahl eingeben: ";
		std::cin >> number;
		collatz(number);
		std::cout << std::endl;
	}

	return 0;
}
