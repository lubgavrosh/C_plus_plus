#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Vector_
{
private:
	
	T* buffer;
    int capacity;
	int size;

public:
	Vector_()
	{
		
		size = 0; capacity = 0;
		buffer = new T[size];
	}
	Vector_(int size)
	{
		
		this->size = size;
		capacity = size + 5;
		buffer=new T [size];

	}
	Vector_(int size, T value)
		: Vector_(size)
	{
		for (size_t i = 0; i < size; i++)
		{
			buffer[i] = value;
		}
	}
	Vector_(const Vector_& a)
		: buffer(a.buffer)
	{
		cout << "Ctor worked";
	}
	void readSize()
	{
		cout <<"Size: "<< size << endl;
	}
	void readCap()
	{
		cout << "Capacity: "<<capacity << endl;
	}
	bool empty()
	{
		if (size == 0)
		{
			return 1;
		}
		else
			return 0;
	}
	void setElem(int index, T element)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (i == index)
			{
				buffer[i] = element;
			}
		}
	}
	void readElem(int index)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (i == index)
			{
				cout<< buffer[i];
			}
		}
	}
	void Show()
	{
		cout << "Array: ";
		for (size_t i = 0; i < size; i++)
		{
			cout <<buffer[i] << " ";
		}
		cout << endl;
	}
	void reserve(int newcap)
	{
		if (newcap > capacity)
		{
			capacity = newcap;
		}
		
	}
	void resize(int newsize, T elem=0)
	{
		
		if (size > newsize)
		{

			size = newsize;
			T* resize_b = new T[size];
			for (size_t i = 0; i < size; i++)
			{
				resize_b[i] = buffer[i];
			}
			delete[] buffer;
			buffer = resize_b;
		}
		else if (size < newsize)
		{

			

			T* resize_b = new T[newsize];
			for (size_t i = 0; i < newsize; i++)
			{
				resize_b[i] = elem;
			}




			
			for (size_t i = 0; i < size; i++)
			{
				resize_b[i] = buffer[i];
			}
			delete[] buffer;
			buffer = resize_b;
			size = newsize;

		}
		
	
		

	}
	void pushBack(T element)
	{
		
		resize(size+1, element);
		
	}
	void popBack()
	{
		if (size != 0)
		{
			size--;
			T* resize_b = new T[size];
			for (size_t i = 0; i < size; i++)
			{
				resize_b[i] = buffer[i];
			}
			delete[] buffer;
			buffer = resize_b;
		}
	}
	int front()
	{
		T static errorFront=-1;
		if (empty())
			return errorFront;
		else
			return buffer[0];
	}
	int back()
	{
		T static errorFront = -1;
		if (empty())
			return errorFront;
		else
			return buffer[size-1];
	}
	int returnelem(int index)
	{
		if(index<size&&index>0)
		for (size_t i = 0; i < size; i++)
		{
			if (i == index)
			{
				return buffer[i];
			}
		}
	}
	void clear()
	{
		resize(0);
		
		
	}
void operator*(int num)
	{
		T* resize_b = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			resize_b[i] = buffer[i]*num;
		}
		delete[] buffer;
		buffer = resize_b;
		
	}

	



	~Vector_()
	{
		delete[] buffer;
		cout << "Dtor worked";
	}
};

void main()
{

	/*Vector_<int> a(3, 1) ;
	a.readCap();
	a.readSize();
	cout << boolalpha << a.empty() << endl;
	a.setElem(0, 1);
	a.readElem(0);
	
	a.Show();
	a.reserve(8);
	
	a.resize(5);
	a.readSize();
	
	a.Show();
	a.popBack(); 
	a.Show();
	
	a.pushBack(3);
	a.Show();
	cout << a.front() << endl;
	cout << a.back() << endl;
	cout << a.returnelem(3) << endl;
	a.clear();
	a.Show();*/

	Vector_<int> b(4, 1);
	
	b.Show();
	b*2;
	b.Show();

}