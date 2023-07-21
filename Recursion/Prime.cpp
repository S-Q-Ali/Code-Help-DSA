#include <iostream>
using namespace std;
bool isPrime(int n, int i = 2) 
{
	if (n < 2) 
	{
		return false;
	}
	if (i * i > n) 
	{
		return true;
	}
	if (n % i == 0) 
	{
		return false;
	}
	return isPrime(n, i + 1);
}
int main() 
{
	int n = 17;
	if (isPrime(n)) 
	{
		cout << n << " is a prime number" << endl;
	}
	else 
	{
		cout << n << " is not a prime number" << endl;
	}

	system("pause");
	return 0;
}
