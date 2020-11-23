#include <exception>
#include <iostream>


long double pow(long double q, int n)
{
	if(n == 0)
		return 1;
	if(n & 1)
		return pow(q, n-1) * q;

	long double partial = pow(q, n/2);
	return partial*partial;
}

long double root_iterative(double q, int n, int steps)
{
	if(steps == 0)
		return 1;

	long double prev = root_iterative(q, n, steps-1);

	return prev + (1./n) * ((q/pow(prev, n-1))-prev);
}

void test_root(double q, int n, int steps)
{

	double root = root_iterative(q, n, steps);
	std::cout << "Root: " << root << std::endl;
	long double res = pow(root, n);
	std::cout << "Error: "<< q - res << std::endl;
}



int main()
{
	double q;
	int n, steps;

	std::cout << "q = " << std::flush;
	std::cin >> q;

	std::cout << "n = " << std::flush;
	std::cin >> n;

	if(n <= 0)
	{
		std::cout << "Invalides n." << std::endl;
		return 1;
	}

	if(q < 0 && n % 2 == 0)
	{
		std::cout << "Die Wurzel ist kein Element der Reelen Zahlen." << std::endl;
		return 1;
	}

	std::cout << "steps = " << std::flush;
	std::cin >> steps;


	test_root(q, n, steps);

	return 0;
}
