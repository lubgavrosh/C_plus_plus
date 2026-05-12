#include <iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;
/*
void random(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		 arr[i]= rand() % -40 - 20;
		 
	}
}
void selectionsort(int arr[], int size)
{
	int min_index = 0;
	int max_index = 0;
	int temp1 = 0;
	int temp2 = 0;
	int b;
	for (int a = 0; a < size; a++)
	{
		if (arr[a] < 0)
		{
			min_index = a;
		break;
		}
	}
	for (int a = size-1; a > min_index; a--)
	{
		if (arr[a] < 0)
		{
			max_index = a;
			break;
		}
	}
	for (int i = min_index; i < max_index; i++)
	{
		b = arr[i];
		
		for (int j = i - 1; j > min_index && arr[j] > b; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = b;
		}
	}
}*/
void start(int arr[], int size)
{
	
	for (int i = 0; i < size; i++)
	{
			arr[i]= rand() %  20+1;

		
		
	}
}
void random(int arr[], int size)
{
	int b;

	for (int i = 0; i < size; i++)
	{
		b = arr[i];
		for (int j = i - 1; j >= 0 && arr[j] != b && arr[j] != arr[i]; j--)
		{
			arr[j + 1] = arr[j];
			arr[j ] = b;
		}
	}
}

int search(int arr[], int size, int num)
{
	for (int i = 0; i < size; i++)
		if (arr[i] == num)
			return i;
	return -1;
}

void sort(int arr[], int size, int key)
{
	int b;
	for (int i = 0; i < key; i++)
	{
		b = arr[i];
		for (int j = i - 1; j >= 0 && arr[j] < b; j--)
		{

			arr[j + 1] = arr[j];
			arr[j ] = b;
		}
	}
	for (int i = key + 1; i < size; i++)
	{
		b = arr[i];
		for (int j = i - 1; j >= key + 1 && arr[j] > b; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = b;
		}
	}
}
void see(int arr[],int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";

	}
	cout << endl;
}

void main()
{
	srand(time(0));
	/*
	const int size = 20;
	int arr[size];
	random(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";

	}
	cout << endl;
	selectionsort(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";

	}
	cout << endl;
	
	const int size = 20;
	int arr[size] ;
	random1(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";

	}
	cout << endl;
	*/
	
	const int size = 20;
	int arr[size];
	int num, c;
	start(arr, size);
	see(arr, size);
	cout << "Masiv after random:" << endl;
	random(arr, size);
	see(arr, size);
	cout << endl;
	cout << "Enter number of diopazon 1 to 20: ";
	cin >> num;
	cout << endl;
	c = search(arr, size, num);
	if (c != -1)
	{
		cout << "Num " << num << " in the masiv have a index " << c << "\n";
		sort(arr, size, c);
		
		see(arr, size);
	}
	else
	{
		cout << endl;
		cout << "Number " << num << " don't found the masiv";
	}
	

	
	




}
