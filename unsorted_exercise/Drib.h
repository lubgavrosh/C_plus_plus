#pragma once
#include<iostream>
class Drib
{
 public:

	

	  
	 Drib();
	 Drib(int t_znam );
	 Drib(int t_chis, int t_znam);
	 int getChis() ;
	 int getZnam()  ;
	void print()const;
	void abb();
	void addF(int f_chis,int f_znam, int s_chis, int s_znam);
	void addNum(int t_chisl, int t_zname, int num);
	void subF(int f_chis, int f_znam, int s_chis, int s_znam);
	void multNum(int t_chisl, int t_zname, int num);
	void multF(int f_chis, int f_znam, int s_chis, int s_znam);
	void divF(int f_chis, int f_znam, int s_chis, int s_znam);
	void equals(int f_chis, int f_znam, int s_chis, int s_znam);
private:
	int chis;
	int znam;
};
inline int Drib::getChis() 
{
	return chis;
}

inline int Drib::getZnam()  
{
	return znam;
}
