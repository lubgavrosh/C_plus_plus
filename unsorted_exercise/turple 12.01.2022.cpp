#include <iostream>
#include <string>
#include <initializer_list>
#include <tuple>
using namespace std;
template <typename T, unsigned rows, unsigned cols >
class Matrix
{
public:
	T& operator () (unsigned r, unsigned c);
	
	Matrix();
	 Matrix(typename T a);
	 Matrix(const Matrix&a);

	 Matrix(initializer_list<T> a);
	

	void minID();
	

	 ~Matrix();
	
private:
	T matrix[rows][cols];
	template <typename T, unsigned rows, unsigned cols>
	friend ostream& operator <<(ostream& out, const Matrix<T, rows, cols>& m);
	template <typename T, unsigned rows, unsigned cols>
	friend istream& operator >>(istream& in, const Matrix<T, rows, cols>& m);
	using MIN = tuple<int, int>;
	MIN min1;
};

//init.list
template<typename T, unsigned rows, unsigned cols>
 Matrix<T, rows, cols>::Matrix(initializer_list<T>a)
{
	
	 for (size_t i = 0; i < rows; i++)
	 {
		 for (size_t j = 0; j < cols; j++)
		 {
			
				 matrix[i][j] = 0;
			 

		 }
		 cout << endl;
	 }
	
	 T arr[cols + rows+1]{};
	 int counter = 0;
	 int i = 0;
	 for (auto& el : a)
	 {
		 if (i < cols + rows+1)
		 {
		 
		 arr[i] = el;
		 arr[i++];
		 counter++;
	       }
	 }
	
	 size_t a1 = rows + cols;
	 size_t t = a1-1;
	
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
			
				
				if (a1 - t - 1 < counter) 
				{
					matrix[i][j] = arr[a1 - t - 1];
					t--;
				}
				
			}
		}
	
	
	
}



template<typename T, unsigned rows, unsigned cols>
inline void Matrix<T, rows, cols>::minID()
{
	auto min = matrix[0][0];
	get<0>(min1) = 0;
	get<1>(min1) = 0;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (matrix[i][j] < min)
			{
				min = matrix[i][j];
				get<0>(min1) = i;
				get<1>(min1) = j;
			}
		}


	}
	cout << "Min index: ";
	cout << "{";
	cout<<get<0>(min1);
	cout << ",";
	cout << get<1>(min1);
	cout << "}";
}


template <typename T, unsigned rows, unsigned cols>
inline T& Matrix<T, rows, cols>::operator() (unsigned r, unsigned c)
{
	return matrix[r][c];
}
template <typename T, unsigned rows, unsigned cols>
inline  Matrix<T, rows, cols>::Matrix()
{

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] = 0;

		}
		cout << endl;
	}
	
}
template <typename T, unsigned rows, unsigned cols>
inline  Matrix<T, rows, cols>::Matrix(typename T a)
{

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			matrix[i][j] = a;

		}
		cout << endl;
	}
}
template<typename T, unsigned rows, unsigned cols>
inline ostream& operator<<(ostream& out, const Matrix<T, rows, cols>& m)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			out << m.matrix[i][j] << "\t";
		
		}
		out << endl;
	}
	return out;
}
template<typename T, unsigned rows, unsigned cols>
inline istream& operator>>(istream& in, const Matrix<T, rows, cols>& m)
{
	
			in >> m.matrix;

	
		
	
	return in;
}

template<typename T, unsigned rows, unsigned cols>
inline Matrix<T, rows, cols>::Matrix(const Matrix<T, rows, cols>&a)
	:matrix(a.matrix)
{
	cout << "Ctor copy worked" << endl;
}

template<typename T, unsigned rows, unsigned cols>
inline Matrix<T, rows, cols>::~Matrix()
{
	
	cout << "Dctor worked" << endl;
}


void main()
{
	
	

	Matrix<float, 3, 3> b({2.3,23,2.5});

	

	cout << b << endl; 
	 b.minID();
	cout  << endl;
	
}
