#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
class Remote;
class TV
{

public:
    bool  on_of;
    int  currentvolume;
    int maxvolume;
    int currentChannel;
    int channelsall;
    friend class Remote;

    TV()
    {
        on_of = 0;
        maxvolume = 50;
        channelsall = 100;
        currentChannel = 1;
        currentvolume = 10;


    }

    void input()
    {

        cout << "Enter how many channels you want: ";
        cin >> channelsall;

        cout << "Enter you start channel ( " << channelsall << "): ";
        cin >> currentChannel;
        Currentchannel();
        cout << "Enter Current volume ( max " << maxvolume << "): ";
        cin >> currentvolume;
        Currentvolume();



    }
    void  Poweron()
    {


        on_of = 1;
        show();

    }
    void Poweroff()
    {
        system("cls");
        int key;
        cout << "TV: off" << endl;
        cout << "All Channels: " << channelsall << endl;
        cout << "Max Volume: " << maxvolume << endl << endl << endl << endl;


        cout << "Enter - [1] to the 'ON' TV" << endl;
        cout << "Enter - [E] to the 'EXIT'" << endl;
        key = _getch();
        if (key == 49)
        {
            Poweron();
        }
        else if (key == 69 || key == 101)
        {
            exit(0);
        }
        else if (key != 49 && key != 69 && key != 101)
        {
            Poweroff();
        }
    }

    void Currentchannel()
    {
        if (currentChannel > channelsall)
        {
            currentChannel = channelsall;
        }
        else if (currentChannel < 0)
        {
            currentChannel = 0;
        }
    }
    void Currentvolume()
    {
        if (currentvolume > maxvolume)
        {
            currentvolume = maxvolume;
        }
        else if (currentvolume < 0)
        {
            currentvolume = 0;
        }
    }

    void nextChannel()
    {

        if (currentChannel < channelsall)
        {
            currentChannel++;
        }
        else if (currentChannel = channelsall + 1)
        {
            currentChannel = 1;
        }

    }
    void prevChannel()
    {

        if (currentChannel < channelsall || currentChannel >= 1)
        {
            currentChannel--;
            if (currentChannel == 0) {
                currentChannel = channelsall;
            }
        }


    }

    void incVolume()
    {


        if (currentvolume < maxvolume)
        {
            currentvolume++;
        }


    }
    void decVolume()
    {


        if (currentvolume <= maxvolume && currentvolume >= 1)
        {
            currentvolume--;
        }


    }


    void show()
    {

        system("cls");
        cout << "TV: on" << endl;
        cout << "Current Channel: " << currentChannel << endl;
        cout << "Current Volume: " << currentvolume << endl << endl << endl << endl << endl << endl;
        cout << "Enter - [0] to the 'OFF' TV" << endl;




    }
    friend void operator++(TV& tv)
    {

        if (tv.on_of == 1)
        {
            tv.Currentchannel();
            if (tv.currentChannel < tv.channelsall)
            {
                tv.currentChannel++;
            }
            else if (tv.currentChannel = tv.channelsall + 1)
            {
                tv.currentChannel = 1;
            }
        }
    }

    friend void operator--(TV& tv)
    {
    if (tv.on_of == 1)
    {
        tv.Currentchannel();
        if (tv.currentChannel < tv.channelsall || tv.currentChannel >= 1)
        {
            tv.currentChannel--;
            if (tv.currentChannel == 0)
            {
                tv.currentChannel = tv.channelsall;
            }
        }
    }
}

};
class Remote
{
    friend class TV;
public:
    friend void operator++( TV& tv);
    friend void operator--(TV& tv);
    void Power(TV& tv)
    {
        int key;

        cout << "Enter - [1] to the 'ON' TV" << endl;
        cout << "Enter - [2] to the 'OFF' TV" << endl;        cin >> key;
        if (key == 1)
        {
            tv.Poweron();
        }
        else if (key == 2)
        {
            tv.Poweroff();
        }

    }
    void operator +(TV& tv)const 
    {
        if (tv.on_of == 1)
        {
        tv.Currentvolume();
        if (tv.currentvolume < tv.maxvolume)
         {
           ++ tv.currentvolume;
         }
       }
        
    }
 void operator -( TV& tv )  const
    {
      
       if (tv.on_of == 1)
       {
           tv.Currentvolume();
       
        if (tv.currentvolume <= tv.maxvolume && tv.currentvolume >= 1)
         {
            --tv.currentvolume;
           
         }
       }
    }

 



 void info(TV&tv)
 {
     system("cls");
     cout << "TV: on" << endl;
     cout << "Current Channel: " << tv.currentChannel << endl;
     cout << "Current Volume: " << tv.currentvolume << endl << endl << endl << endl << endl << endl;
 }
    void goChannel(TV& tv, int tmp)
    {
      
        cout << "Enter channel which you want to play: ";
      
        if (tmp <= tv.channelsall){
            tv.currentChannel = tmp;
    }
        
    }
};





int main()
{
  
    TV my;
   my.input();
   /* my.show();*/
    
    Remote remote;
    remote.Power(my);
   
    remote.info(my);
    Sleep(2000);
    remote.operator+(my); 
    remote.info(my);
    Sleep(2000); 
    remote.operator-(my);
    remote.info(my);
    Sleep(2000);
    operator++(my);
    remote.info(my);
    Sleep(2000);
    operator--(my);
    remote.info(my);
    Sleep(2000);
    remote.goChannel(my, 5);
    remote.info(my);


}


    



