#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

     class Train
    {
    private:
        int number;
        int hour, min;
        string destination;
    public:
        
        Train()
            :number(0), hour(0),min(0), destination("0") {}
      
        Train(int _number, int _hour, int _min, string _destination)
        {
          
            number = _number; 
            hour = _hour;
            min = _min;
            destination = _destination; 
        }
        int getNumber()
        {
            return number;
        }
        int getHour()
        {
            return hour;
        }
        int getMin()
        {
            return min;
        }
        string getDestination()
        {
            return destination;
        }
        void edit1(int hour, int min, string destination1)
        {
            this->hour = hour;
            this->min = min;
            this-> destination= destination1;
        }
       

        
    };
     int Hcorrect(int hour) {

         
         if (hour < 25 && hour >0)
         {
             return hour;
         }
         else if(hour>25 || hour<0)
         {
             cout << "You enter don't correct hour" << endl;
             cout << "Enter hour: ";
             cin >> hour;
             hour=Hcorrect(hour);
         }
         return hour;
     }
     int Mcorrect(int min) 
     {
        

         if (min < 60 && min>-1)
         {
             return min;
         }
         else if(min>60 || min<-1)
         {
         

         cout << "You enter don't correct min" << endl;
         cout << "Enter min: ";
         cin >> min;
         min=Mcorrect(min);
         }
         return min;

     }
   
     int Ncorrect(int num, vector<Train>& a)
     {
       
         for (vector <Train>::iterator it1 = a.begin(); it1 != a.end(); ++it1)
         {
             if (it1->getNumber() == num)
             {
                 cout << "This number is exist" << endl;
                 cout << "Enter number of train: ";
                 cin >> num;
                 num=Ncorrect(num, a);
             }
         }
         return num;
     }
    void Editcorrect(int num, vector<Train>& a)
     {
         int hour, min;
         string station;
         vector <Train>::iterator it = a.begin();

         if (it->getNumber() == num)
             {


                 cout << "Enter new hour: " << endl;
                 cin >> hour;
                 hour = Hcorrect(hour);
                 cout << "Enter new min: " << endl;
                 cin >> min;
                 min = Mcorrect(min);
                 cout << "Enter new destination: " << endl;
                 cin >> station;
                 it->edit1(hour, min, station);

             }
         else
         {
             cout << "Train with this number not exist" << endl;
         }
            

         
     }
    void addTrain(vector <Train> &a) 
    {
        
        
        int num, hour, min;
        
        string station;
       
        cout << "Number of train: " << endl;
        cin >> num;
       num= Ncorrect(num,a);
       
        cout << "Enter hour: " << endl;
        cin >> hour;
        hour=Hcorrect(hour);
       
        cout << "Enter min: " << endl;
        cin >> min;
        min=Mcorrect(min);
      
        cout << "Enter your distination: ";
        cin >> station;
        cout << endl;
        a.push_back(Train(num, hour, min , station));
    }

    void infoTrains(vector <Train>&a)
    {
        if (a.empty())
        {
            cout << "NOTHING " << endl; return;
        }
        vector <Train>::iterator it = a.begin();
        cout << "Number of train " << '\t' << " Time departure " << '\t' << " Destination " << endl;
        while (it != a.end())
        {
            cout << it->getNumber() << setw(25) << it->getHour() <<":"<< it->getMin() << setw(25) << it->getDestination() << '\n';
          
            it++;
        }
        
    }
    void infoTrain( vector<Train>& a)
    {
        if (a.empty()) 
        { 
        cout << "NOTHING\n";
        return;
        }
        int num;
        cout << "Enter number of train: " << endl;
        cin >> num;
        
        
      
        vector <Train>::iterator it = a.begin();

           if (it->getNumber() == num)
            {
                cout << "Number of train " << '\t' << " Time departure " << '\t' << " Destination " << endl;
                cout << it->getNumber() << setw(25) << it->getHour() << ":" << it->getMin() << setw(25) << it->getDestination() << '\n';
            }
           else
           {
               cout << "Train with this number not exist" << endl;
           }
           
        

       
    }
    void del(vector<Train>& a)
    {

        int num;

        cout << "enter number of train which you want to delete: ";
        cin >> num;


        for (int i = 0; i < a.size(); i++)
        {
            if (a[i].getNumber() == num)
            {
                a.erase(a.begin() + i);
            }
        }




    }
    void edit(vector<Train> &a)
    {
        
        int num;
      
        cout << "\nEnter number of train which you want to edit: ";
        cin >> num;
        Editcorrect(num, a);
    
         
        
    }
   
 

    void main()
       {
        
        
     /*  vector <Train> trains;
       for (int i = 0; i < 2; i++)
        {
            addTrain(trains);
        }
      
     infoTrains(trains);
        infoTrain(trains);
        edit(trains);
       
      infoTrains(trains);
        del(trains);
        infoTrains(trains);
        */
        vector <Train> train;
        addTrain(train);
        infoTrains(train);
        infoTrain(train);
        edit(train);
        del(train);
        infoTrain(train);
    }

