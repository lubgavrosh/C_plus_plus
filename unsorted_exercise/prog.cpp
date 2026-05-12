#include <iostream>
#include "function.h"

using namespace std;
void main() {
	srand(time(0));
		const int size = 10;
		int arr[size];
		rand(arr, size);
		show(arr, size);
		cout << endl;
		max(arr, size);
		cout << endl;

		min(arr, size);
		cout << endl;
		sort(arr, size);
		show(arr, size);
		int a, b;
		cout << endl;

		cout << "Enter index ";
		cin >> a;
		cout << "Enter num";
		cin >> b;
		redakt(arr, size, a, b);
		show(arr, size);
		
}