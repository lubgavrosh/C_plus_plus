#include <iostream>
#include <time.h>
using namespace std;
void rand(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
	}
}
void show(int arr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";

	}
}
void max(int arr[], int size)
{
	int max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	cout << "Max = " << max;
}
void min(int arr[], int size)
{
	int min = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	cout << "Min = " << min;
}
void sort(int arr[], int size)
{
	int min_index = 0;
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min_index])
			{
				min_index = j;

			}
		}
		if (i != min_index)
		{
			temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;

		}
	}
}
void redakt(int arr[], int size, int key, int num)
{
	for (int i = 0; i <size; i++)
	{
		if (i == key)
		{
			arr[i-1] = num;
		}

	}

}
