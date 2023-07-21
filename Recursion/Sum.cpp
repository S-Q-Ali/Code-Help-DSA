#include <iostream>
using namespace std;
int recur_sum(int n) 
{
	if (n == 1) 
	{
		return 1;
	}
	return n + recur_sum(n - 1);
}

int main() {
	int n = 6;
	int sum = recur_sum(n);
	cout << "The sum of the first " << n << " natural numbers is: " << sum << endl;

	system("pause");
	return 0;
}
