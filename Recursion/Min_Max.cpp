#include <iostream>
using namespace std;
int findMin(int arr[], int n) 
{
	if (n == 1)
	{
		return arr[0];
	}
	int minRest = findMin(arr + 1, n - 1);
	if (arr[0] < minRest) 
	{
		return arr[0];
	}
	else {
		return minRest;
	}
}
int findMax(int arr[], int n) 
{
	if (n == 1) 
	{
		return arr[0];
	}
	int maxRest = findMax(arr + 1, n - 1);
	if (arr[0] > maxRest) 
	{
		return arr[0];
	}
	else 
	{
		return maxRest;
	}
}
int main() {
	int arr[] = { 5,9,7,1,5 };
	int n = 5;

	cout << "Minimum element: " << findMin(arr, n) << endl;
	cout << "Maximum element: " << findMax(arr, n) << endl;

	system("pause");
	return 0;
}
