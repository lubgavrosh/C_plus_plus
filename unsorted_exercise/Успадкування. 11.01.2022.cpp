#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name_e;
    int number_e;
    string date_e;
public:
    Employee()
    {
        name_e = "Noname";
        number_e = 0;
        date_e = "01.01.1970";
        cout << "ctor default worked" << endl;
    }
    Employee(string name, int num, string date)
    {
        name_e = name;
        number_e = num;

        date_e = date;
    }
   void setName(string name)
    {
       name_e = name;
    }
   void setNum(int num)
   {
       number_e = num;
   }
   void setDate(string date)
   {
       date_e = date;
   }
   void show()
   {
       cout << "Name: " << name_e << endl;
       cout << "Number: " << number_e << endl;
       cout << "Date: " << date_e << endl;
       
   }
};


class ProducctionWorker : protected Employee
{
private:
    int Shift;
    double Hourly_p;

public:
    ProducctionWorker()
    {
        Shift = 1;
        Hourly_p = 20.5;
        cout << "ctor2 default worked" << endl;
    }
    ProducctionWorker(string name, int num, string date, int shift , double hourly_p)
        :Employee(name, num, date)
    {
     
        if (shift > 0 && shift < 3)
        {
            Shift = shift;
        }
        else
        {
            Shift = 1;
            cout << "Dont correct number default <Shift=1>"<<endl;
        }
        Hourly_p = hourly_p;
    }
    void setData(string date)
    {
        Employee::setDate(date);
    }
    void setName(string name)
    {
        Employee::setName(name);
    }
    void setNum(int num)
    {
        Employee::setNum(num);
    }
   void setShift(int num)
    {
       if (num > 0 && num < 3)
       {
           Shift = num;
       }
       
       else
       {
           cout << "Dont correct number default <Shift=1>"<<endl;
           Shift = 1;
       }
    }
   void setHourly_p(double hourly_p)
   {
       Hourly_p = hourly_p;
   }
    void show()
    {
        Employee::show();
        cout << "Shift: " << Shift << endl;
        cout << "Hourly_p: " << Hourly_p << endl;
       

    }

};


class TeamLeader :ProducctionWorker
{
private :
    int monthly_b;
    int required_h;
    int training_h;

public:
    TeamLeader()
    {
        monthly_b=10;
        required_h=0;
        training_h=50;
        cout << "ctor3 default worked" << endl;
    }
    TeamLeader(string name, int num, string date, int shift, double hourly_p , int Monthly_b ,int Required_h , int Training_h)
        :ProducctionWorker( name, num,date,shift,hourly_p)
    {
        monthly_b = Monthly_b;
        required_h = Required_h;
        training_h = Training_h;

    }

    void setMonthly_b(int num)
    {
        monthly_b = num;
    }
    void setRequired_h(int num)
    {
        required_h = num;
    }
    void setTraining_h(int num)
    {
        training_h = num;
    }
    void setData(string date)
    {
        Employee::setDate(date);
    }
    void setName(string name)
    {
        Employee::setName(name);
    }
    void setNum(int num)
    {
        Employee::setNum(num);
    }
    void setShift(int num)
    {
        ProducctionWorker::setShift(num);
    }
    void setHourly_p(double hourly_p)
    {
        ProducctionWorker::setHourly_p(hourly_p);
    }
    void show()
    {
       ProducctionWorker::show();
        cout << "Monthly bonus amount: " << monthly_b << endl;
        cout << "Required number of training hoursourly_p: " << required_h << endl;
        cout << "Number of training hours that the team leader has attended: " << training_h << endl;


    }

}; 









void main()
{
    Employee me{ "Maks",1,"20.11.2001" };
    me.show();
    cout << endl;

    me.setDate("10.11.2022");
    me.setName("Sasha");
    me.setNum(123);
    me.show();
    cout << endl;

    Employee you;
    you.show();
    cout << endl;

    ProducctionWorker me1{ "Maks",2,"20.11.2003",2,12.5 };
    me1.show();
    cout << endl;
    me1.setHourly_p(24.5);
    me1.setShift(1);
    me1.setNum(45);
    me1.show();
    cout << endl;



    TeamLeader you2{ "Ivan",3,"21.05.2010",1,40, 20, 2,45 };
    you2.show();
    cout << endl;

    you2.setMonthly_b(3);
    you2.setRequired_h(12);
    you2.setTraining_h(15);
    you2.show();
    you2.setName("Lev");
    cout << endl;
    you2.show();
}

