#include "Drib.h"
using namespace std;
Drib::Drib()
{
	chis = 0;
	znam = 1;
}

Drib::Drib(int t_znam)
{
	znam = 1;
}



Drib::Drib(int t_chis, int t_znam)
{
	if (t_znam != 0)
		chis = t_chis;
	znam = t_znam;
}
void Drib::print()const
{
	cout << chis << "/" << znam << endl;
}

void Drib::abb()
{
	int a;
	cout << "Enter the number by which you want to reduce the "<<chis<<"/"<<znam<<" : ";
	cin >> a;
	if (znam % a == 0 && chis % a ==0 )
	{
		znam = znam / a;
		chis = chis / a;
		cout << chis << "/" << znam << endl;
	}
	else
	{
		cout << "You entered a dont correct number or this fraction dont have a abbreviation" << endl;
	}
}

void Drib::addF(int f_chis, int f_znam, int s_chis, int s_znam) 
{
	chis = (f_chis * s_znam) + (s_chis * f_znam);
	znam = f_znam * s_znam;
	cout << f_chis << "/" << f_znam << " + " << s_chis << "/" << s_znam<<" = "<<chis<<"/"<<znam<<endl;
	abb();
}

void Drib::addNum(int t_chisl, int t_zname, int num)
{
	chis = num * t_zname + t_chisl;

	znam = t_zname;
	cout << t_chisl << "/" << t_zname << " + " << num << " = " << chis << "/" << znam << endl;
	abb();
}

void Drib::subF(int f_chis, int f_znam, int s_chis, int s_znam)
{
	chis = (f_chis * s_znam) - (s_chis * f_znam);
	znam = f_znam * s_znam;
	cout << f_chis << "/" << f_znam << " - " << s_chis << "/" << s_znam << " = " << chis << "/" << znam << endl;
	abb();
}

void Drib::multNum(int t_chisl, int t_zname, int num)
{
	
	chis = t_chisl * num;
	znam = t_zname;
	cout << t_chisl << "/" << t_zname << " * " << num<< " = " << chis << "/" << znam << endl;
	abb();
}

void Drib::multF(int f_chis, int f_znam, int s_chis, int s_znam)
{
	chis = f_chis * s_chis;
	znam = f_znam * s_znam;
	cout << f_chis << "/" << f_znam << " * " << s_chis << "/" << s_znam << " = " << chis << "/" << znam << endl;
	abb();
}

void Drib::divF(int f_chis, int f_znam, int s_chis, int s_znam)
{
	chis = f_chis * s_znam;
	znam = f_znam * s_chis;
	cout << f_chis << "/" << f_znam << " / " << s_chis << "/" << s_znam << " = " << chis << "/" << znam << endl; abb();
}

void Drib::equals(int f_chis, int f_znam, int s_chis, int s_znam)
{
	if (f_chis == s_chis && f_znam == s_znam || f_chis == s_chis/2 && f_znam == s_znam/2 || f_chis/2 == s_chis && f_znam/2 == s_znam )
	{
		cout << f_chis << "/" << f_znam << " = " << s_chis << "/" << s_znam << endl;
	}
	else
	{
		cout << f_chis << "/" << f_znam << " != " << s_chis << "/" << s_znam << endl;
	}

}


