#include <iostream>
using namespace std;
void dec_to_bin(int n) 
{
	if (n > 1) 
	{
		dec_to_bin(n / 2);
	}
	cout << n % 2;
}
int main() {
	int n = 10;

	cout << "The binary representation of " << n << " is: ";
	dec_to_bin(n);
	cout << endl;

	system("pause");
	return 0;
}
