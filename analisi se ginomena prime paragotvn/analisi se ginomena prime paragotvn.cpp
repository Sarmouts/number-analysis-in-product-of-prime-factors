#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<unsigned int> vci;

vci primes = { 2,3,5,7,11,13 };

bool CheckIfPrime(int n)
{
	if (n % 3 == 0)
		return 0;
	else if (sqrt(n) == int(sqrt(n)))
		return 0;
	for (size_t i = 3; 7 * primes[i] <= n; i++)
		if (n % primes[i] == 0)
			return 0;
	return 1;
}
void generatePrimes(int edge)
{
	int count = 1;
	size_t i = 17;
	while (i <= edge)
	{
		if (CheckIfPrime(i))
			primes.push_back(i);
		if (count == 4)
		{
			count = 1;
			i += 2;
		}
		else
			count++;
		i += 2;
	}
}
void result(int number)
{
	int i = 0;
	int n = 0;
	while (number != 1)
	{
		while (number % primes[i] == 0)
		{
			number /= primes[i];
			n++;
		}
		if (n != 0)
			std::cout << primes[i] << "^" << n << " ";
		n = 0;
		i++;
	}
}
int main()
{
	int number = 73544;
	generatePrimes(number);
	std::cout << number << " = ";
	result(number);
}