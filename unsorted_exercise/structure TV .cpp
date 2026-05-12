#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

class TV
{
public:
   bool  on_of;
    int  currentvolume;
    int maxvolume;
    int currentChannel;
    int channelsall;

   
    TV()
    {
        on_of=0;
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
        cout << "Enter Current volume ( max " << maxvolume << "): ";
        cin >> currentvolume;

        cout << "\t\tMANAGEMENT" << endl;
        cout << "Next channel - [w]" << endl;
        cout << "Prev channel - [s]" << endl;
        cout << "Dec  volume  - [a]" << endl;
        cout << "Inc  volume  - [d]" << endl;
        Sleep(5000);

    }
  void  Poweron()
    {
        
        
            on_of =1;
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
      if (key == 69 || key ==101)
      {
          exit(0);
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
        
        
            if (currentvolume <= maxvolume && currentvolume >=1)
            {
                currentvolume--;
            }
            
        
    }


    void show()
    {
        int keypress;




       
        do
        {
            system("cls");
            cout << "TV: on" << endl;
            cout << "Current Volume: " << currentvolume << endl;
            cout << "Current Channel: " << currentChannel << endl << endl << endl << endl << endl << endl;
            cout << "Enter - [0] to the 'OFF' TV" << endl;

            keypress = _getch();
            if (keypress == 119)
            {
                nextChannel();
            }
            if (keypress == 115)
            {
                prevChannel();
            }
            if (keypress == 100)
            {
                incVolume();
            }
            if (keypress == 97)
            {
                decVolume();
            }
            if (keypress == 48)
            {
                
                Poweroff();
            }
           
        } while (true);

       
            
        
    }
    

};



int main()
{
  
    TV my;
    my.input();
    my.Poweron();





  
}


    



