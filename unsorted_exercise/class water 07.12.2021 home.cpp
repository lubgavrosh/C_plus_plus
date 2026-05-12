#include <iostream>
#include <string.h>

using namespace std;
static int COUNTER;
class Water
{


	
	
private:
	static int count()
	{
		COUNTER++;
		return COUNTER;
	}
public:
	
	string name;
	string type;
	int width;
	int length;
	int max_depth;
	
	Water() 
	{
		
		name = "Baykal";
		type = "Lake";
		width = 80;
		length = 636;
		max_depth = 1642;
		
	}

	static int getcounter()
	{
		cout << "Total \"Waters\": ";
		return COUNTER;
	}

	
	Water(string name, string type, int width, int length, int max_depth)
	{
		if (type == "Lake" || type == "River" || type == "Sea" || type == "Ocean" || type == "lake" || type == "river" || type == "sea" || type == "ocean")
		{

			this->name = name;
			this->type = type;
			this->width = width;
			this->length = length;
			this->max_depth = max_depth;
			count();
		}
		else
		{
			this->name = name;
			this->type;
			this->width = width;
			this->length = length;
			this->max_depth = max_depth;
			count();
		}



	}
	
	
	
	void setName(string a)
	{
		name = a;
	}
	string getName()
	{
		return name;
	}
	void setType(string a)
	{
		if (type == "Lake" || type == "River" || type == "Sea" || type == "Ocean" || type == "lake" || type == "river" || type == "sea" || type == "ocean")
		{
			type = a;
		}
	}
	string getType()
	{
		return type;
	}
	
	void setWidth(int a)
	{
		if (a <= 0) {
			width = a;
		}
	}
	int getWidth()
	{
		return width;
	}
	void setLength(int a)
	{
		if (a <= 0) {
			length = a;
		}
	}
	int getLength()
	{
		return length;
	}
	void setDepth(int a)
	{
		if (a <= 0) {
			max_depth = a;
		}
	}
	int getDepth()
	{
		return max_depth;
	}
	int Amount()
	{
		return (width * length * max_depth);
	}
	int S_water()
	{
		return (width * length);

	}
	
	static bool Logictype(const Water& a1, const Water& a2)
	{
		return (a1.type == a2.type);
	}
	static int Logic_S(const Water& a1, const Water& a2)
	{
		if (a1.width * a1.length == a2.width * a2.length) {
			return 0;
		}
		else if (a1.width * a1.length > a2.width * a2.length) {
			return 1;
		}
		else if (a1.width * a1.length < a2.width * a2.length) {
			return -1;
		}
		
		
	}
	static void Search(Water a1[], int size, string type)
	{
		Water a{"","",0,0,0,};
		for (size_t i = 0; i < size; i++)
		{
			if (type == a1[i].type)
			{
				if (a1[i].width * a1[i].length > a.width * a.length)

				{
					a = a1[i];
				}
				
			 }
		}

	 cout <<"Name: "<< a.name << endl;
		cout << "S: " << a.width * a.length << "km2";
	}

};







int main()
{
	Water t("Lisa","River",23,44,2);
	Water b;
	/*
	cout << t.getName();
	cout << "\t";
	cout << t.getType();
	cout << "\t";
	cout << t.getWidth();
	cout << "\t";
	cout << t.getLength();
	cout << "\t";
	cout << t.getDepth();
	cout << "\t";
	cout << t.Amount(); cout << "\t";
	cout<<t.S_water();cout << "\t";
	*/
	cout<<"\nType A= Type B: "<<boolalpha << Water::Logictype(t, b);
	cout << "\nS_water A & S_water B. REsult: 0-[=], 1-[>], -1-[<] : " << Water::Logic_S(t, b);
	cout << endl;
	
	cout << endl;
	Water waters[3]
	{
		Water("Dnipro", "River", 50, 2200, 15),
		Water("Black Sea", "Sea", 5800, 1150, 2210),
		Water("Volga", "River", 50, 3500, 10)
	};
	
	Water::Search(waters, 3,"River");
	cout << endl;
	cout<<Water::getcounter();
	
}
