#include <iostream>

namespace power
{
	int iterative(int q, int n)
	{
		int product = 1;
		for(int i = 0; i < n; i++)
			product *= q;

		return product;
	}

	int recursive(int q, int n)
	{
		return (n==0) ? 1 : q * recursive(q, --n);
	}

	int improved(int q, int n)
	{
		if(n == 0)
			return 1;
		if(n & 1)
			return improved(q, n-1) * q;

		int partial = improved(q, n/2);
		return partial*partial;
	}

}//end of namespace power



int main()
{
	int q, n;

	std::cout << "q = " << std::flush;
	std::cin >> q;

	std::cout << "n = " << std::flush;
	std::cin >> n;

	std::cout << "Improved:  " << power::improved(q, n)  << std::endl;
	std::cout << "Iterative: " << power::iterative(q, n)  << std::endl;
	std::cout << "Recursive: " << power::recursive(q, n) << std::endl;

	return 0;
}
