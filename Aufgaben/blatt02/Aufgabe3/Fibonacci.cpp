#include <iostream>

long long int fibonacci(int number)
{
	long long int a = 0;
	long long int b = 1;

	for(int i = 0; i < number; i++)
	{
		std::cout << a << std::endl;
		long long int c = a + b;
		a = b;
		b = c;
	}
	return a;
}


int main()
{
	int N;

	while(true)
	{
		std::cout << "Zahl eingeben: ";
		std::cin >> N;
		std::cout << fibonacci(N) << std::endl;
		std::cout << std::endl;
	}

	return 0;
}

//  (a) iii. Wenn N zu groß wird, kommt es zu einem Integeroverflow, da die Integervariable so große Zahlen nicht speichern kann und deswegen ins negative überrollt.
