#include <iostream>
#include <string.h>
#include<cstring>
#include<Windows.h>
using namespace std;


class String
{

private:
    char* ch;
public:
   
     
   
    

    String() 
    {
        int SIZE = 80;
        ch = new char[SIZE] {};
      
     
      
    }
    String(int size)
    {
        ch = new char[size]{};
       
    }

    String( const   char* string )
        
    {
        ch = new char[strlen(string) + 1];
        strcpy_s(this->ch, strlen(string) + 1, string);
    }
    

    void Show() const
    {
        cout  << ch<< endl;
        
    }
    String(const String& a)
        :String(a.ch)
    {
        cout << "Ctor worked\n";
    }
    String association(const String&other)
    {
      
        
        int size = strlen(this->ch) + strlen(other.ch) + 1;
        String str(size);
        
        strcat_s(str.ch, size, this->ch);

        strcat_s(str.ch, size, other.ch);
        return str;
        
            
        
     }
     String& operator--()
    {
         
        for (int i = 0; i < strlen(this->ch); i++)
        {
           this->ch[i]--;
        }
        return *this;
    }
     String operator--(int d)
    {
         String tmp(*this);
        
        for (int i = 0; i < strlen(this->ch); i++)
        {
            this->ch[i]--;
        }
      
        return tmp;
    }

    


   friend  ostream& operator <<(ostream& out, const String& obj) 
    {
        
       out << obj.ch;
      
        out << endl;
        return out; 
    }
    friend istream& operator >>(istream& in, String& obj) 
    {
       
            in >> obj.ch;
        
        return in;
    }
    
 
    String cross(const char * v)
    {
        String str;
       
        int k=0;
         char z='0';
         char g='0';
        
        for (int i = 0; i < strlen(this->ch); i++)
        {
            for (int j = 0; j < strlen(v); j++)
            {
               
                   
                    if (this->ch[i] == v[j])
                    {
                        g = v[j];
                        if (g != z)
                        {
                            z = g;
                            str.ch[k++] = v[j];
                        }
                    }
                
            }
          
        }
     
        return str.ch;

 

    }
   
    
    ~String()
    {
        delete[] ch;
        cout << "\nDctor worked\n";
    }
};

void main()
{
    String s{ "string" };
    String v{ "my" };
    
    s.Show();
    v.Show();
    
    cin>> s;
    cout<< s;
   
   
    --s;
    s.Show();
    
   
    s--;
    s.Show(); 
    cout << endl;
    cout<<"Cross: " << s.cross("interesting");
    cout << endl; 
    cout << "Association: "<< s.association(v);

    
     

   


    

}




