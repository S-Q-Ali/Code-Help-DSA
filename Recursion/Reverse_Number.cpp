#include<iostream>
using namespace std;

int reverse_n(int n1, int n2)
{
	if (n1 == 0)
	{
		return n2;
	}
	n2 *= 10;
	n2 += (n1 % 10);
	n1 = n1 / 10;
	return reverse_n(n1, n2);
}

int main()
{

	int i = 12321;

	cout << "Enter a number to check without spaces or comma: ";
	cin >> i;

	int b = reverse_n(i, 0);
	if (i==b)
	{
		cout << i << " is a palindrome" << endl;
	}
	else
	{
		cout << i << " is not a palindrome" << endl;
	}






	system("pause");
	return 0;
}