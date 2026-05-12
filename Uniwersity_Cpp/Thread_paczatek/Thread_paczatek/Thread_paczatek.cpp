#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <time.h>
using namespace std;
mutex m;


void hello()
{
	cout << "Hello World";
}
void hello_1(int nr)
{
	
		//5 lock_guard<mutex>blokada(m);
		//6 unique_lock<mutex>blokada(m);
	cout << "Jestem watkiem " << nr << endl;
}

void iloczyn(int* a, int b)
{
	*a=(*a) * b;
}




void suma(int& a, int b)
{
	a = a + b;
}


class klasa
{
public:
	klasa(void) {

	}
	~klasa(void) {}
	void operator()(int a)
	{
	cout << "uruchomienie";
	}

	
};
class operacje_1
{
public:
	
	void metoda()
	{
		string m = "metoda";
		for (int i = 0; i <6; i++)
		{
			cout << m[i];
		}
	}


};

class operacje
{
private:
	int x;
	int y;
public:
	operacje() : x(0), y(0) {};
	~operacje() {};

	void klawiatura(void)
	{
		cout << "podaj pierwsza liczbe ";
		cin >> x;
		cout << "podaj druga liczbe ";
		cin >> y;
	}

	void suma(int& wynik)
	{
		wynik = x + y;
	}

	void roznica(int& wynik)
	{
		wynik = x - y;
	}

	void iloczyn(int& wynik)
	{
		wynik = x * y;
	}
};



void suma_1(int* a, int b)
{

	*a = (*a) + b;
}
	
void suma_double(double* a, double b)
{
	
	*a = (*a) + b;

}
int main()
{
	/*//zad-1
		cout << "Funkcja main" << endl;
		thread t1(&hello);
		thread t2(&hello);
		t1.join();
		t2.join();
	*/

	/*//zad-2

		cout << "Funkcja main" << endl;
		thread t1(&hello);
		thread t2(&hello);
		t2.detach();
		t1.detach();
	*/

	/*//zad-3
		thread t1(&hello_1,1);
		thread t2(&hello_1,2);
		t1.join();
		t2.join();
		*/

   //zad-4

	/*vector<thread> t(10);

	for (int i = 0; i < 10; i++)
	{
		t[i] = thread(hello_1, i);
	}
	for (int i = 0; i < 10; i++)
	{
		
			t[i].join();
		
	}
	*/

	
	//5 i 6
	/*
	vector<thread> t(10);

	for (int i = 0; i < 10; i++)
	{
		t[i] = thread(hello_1, i);
	}
	for (int i = 0; i < 10; i++)
	{
		t[i].join();

	}*/

	//7
	/*int l_1 = 4;
	int l_2 = 2;
	cout << "Liczba_1= " << l_1 << endl;
	cout << "Liczba_2= " << l_2 << endl;
	thread t(iloczyn, &l_1, l_2);
	t.join();
	cout << "Iloczyn liczb= " << l_1 << endl;
	*/

	//8
	/*int l_1 = 4;
	int l_2 = 2;
	cout << "Liczba_1= " << l_1 << endl;
	cout << "Liczba_2= " << l_2 << endl;
	thread t(suma, ref(l_1), l_2);
	t.join();
	cout << "Iloczyn suma= " << l_1 << endl;
*/

	//9 i 10
	//klasa a;
	//thread t1(a//,1
	//	);
	//t1.join();

	//11
	/*operacje_1 a;
	thread t1(&operacje_1::metoda, &a);
	t1.join();*/


	//12
	/*operacje op;
	int wynik_suma = 0;
	int wynik_roznica = 0;
	int wynik_iloczyn = 0;
	op.klawiatura();
	thread t1(&operacje::suma, &op, ref(wynik_suma));
	thread t2(&operacje::roznica, &op, ref(wynik_roznica));
	thread t3(&operacje::iloczyn, &op, ref(wynik_iloczyn));
	t1.join();
	t2.join();
	t3.join();
	cout << "suma " << wynik_suma << endl;
	cout << "roznica " << wynik_roznica << endl;
	cout << "iloczyn " << wynik_iloczyn << endl;
	*/

//13

// A
cout << "--------------INT--------------:" << endl;
clock_t start, stop;
int a0 = 123;
int a1 = 321;

start = clock();
suma_1(&a0, a1);
stop = clock() - start;
double zegar_a1 = (double)stop / CLOCKS_PER_SEC;
cout << "A" << endl;
cout << "Wynik: " << a0 << endl;
cout << "Czas: " << zegar_a1 << " s\n" << endl;


//B
int a2 = 123;
int a3 = 321;

start = clock();
thread t1(suma_1, &a2, a3);
t1.join();
stop = clock() - start;

double zegar_a2 = (double)stop / CLOCKS_PER_SEC;
cout << "B" << endl;
cout << "Wynik: " << a2 << endl;
cout << "Czas: " << zegar_a2 << " s\n" << endl;

//double
cout << "-----------------------------Double-----------------------:\n" << endl;
//A
double d1 = 123.0, d2 = 321.0;
start = clock();
suma_double(&d1, d2);
stop = clock() - start;

double zegar_d1 = (double)stop  / CLOCKS_PER_SEC;
cout << "A" << endl;
cout << "Wynik: " << d1 << endl;
cout << "Czas: " << zegar_d1 << " s\n" << endl;
//B
double d3 = 123.0;
double d4 = 321.0;

start = clock();
thread t2(suma_double, &d3, d4);
t2.join();
stop = clock() - start;

double zegar_d2 = (double)stop / CLOCKS_PER_SEC;
cout << "B" << endl;
cout << "Wynik: " << d3 << endl;
cout << "Czas: " << zegar_d2 << " s\n" << endl;


	return 0;
}