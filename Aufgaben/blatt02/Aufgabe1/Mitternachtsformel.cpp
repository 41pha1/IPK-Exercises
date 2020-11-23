#include <cmath>
#include <iostream>

const int SUCCCESS = 0, COMPLEX = 1, AMBIGUOUS = 2;

struct Result
{
	int status;
	double x1 = 0, x2 = 0;

	Result(int status_)
	{
		status = status_;
	}

	Result(int status_, double x1_, double x2_)
	{
		status = status_;
		x1 = x1_;
		x2 = x2_;
	}
};

Result calcFactors(double a, double b, double c)
{
	if(a == 0)
		return Result(AMBIGUOUS);

	double p = b/a;
	double q = c/a;

	double pHalved = p/2;
	double rootBody = pHalved * pHalved - q;

	if(rootBody < 0)
		return Result(COMPLEX);

	double sqrt = std::sqrt(rootBody);
	double x1 = -pHalved + sqrt;
	double x2 = -pHalved - sqrt;

	return Result(SUCCCESS, x1, x2);
}


int main()
{
	double a, b, c;

	std::cout << "a = " << std::flush;
	std::cin >> a;

	std::cout << "b = " << std::flush;
	std::cin >> b;

	std::cout << "c = " << std::flush;
	std::cin >> c;

	std::cout << "Berechne Koeffizienten der Gleichung " << a << "*x^2 + " << b << "*x + " << c << ":" << std::endl;
	Result result = calcFactors(a, b, c);

	switch(result.status)
	{
		case COMPLEX:  	std::cout << "Das Ergebnis ist Komplex." << std::endl;
						break;
		case AMBIGUOUS:	std::cout << "Das Ergebnis ist nicht eindeutig." << std::endl;
						break;
		case SUCCCESS:	std::cout << "x1 = " << result.x1 << ", x2 = " << result.x2 << std::endl;
						break;
	}

	return 0;
}
