#include <iostream>
using namespace std;
void swap(int& a, int& b) 
{
	int temp = a;
	a = b;
	b = temp;
}
void bubbleSortPass(int arr[], int n) 
{
	if (n == 1) 
	{
		return;
	}
	for (int i = 0; i < n - 1; i++) 
	{
		if (arr[i] < arr[i + 1])
		{
			swap(arr[i], arr[i + 1]);
		}
	}
	bubbleSortPass(arr, n - 1);
}
void bubbleSort(int arr[], int n) 
{
	if (n == 1) 
	{
		return;
	}
	bubbleSortPass(arr, n);
	bubbleSort(arr, n - 1);
}
int main() 
{
	int arr[] = { 4, 3, 5, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Original array: ";
	for (int i = 0; i < n; i++) 
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	bubbleSort(arr, n);

	cout << "Sorted array in descending order: ";
	for (int i = 0; i < n; i++) 
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
