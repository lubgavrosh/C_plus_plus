#include <iostream>
#include <string.h>
#include<cstring>
#include<Windows.h>
using namespace std;


class String
{

private:
    char* ch;
    int SIZE=80;
public:
   
     
   
    

    String() 
    {
       
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
     String& operator++()
     {

         for (int i = 0; i < strlen(this->ch); i++)
         {
             this->ch[i]++;
         }
         return *this;
     }
     String operator++(int d)
     {
         String tmp(*this);

         for (int i = 0; i < strlen(this->ch); i++)
         {
             this->ch[i]++;
         }

         return tmp;
     }
     String operator+(const String&other)
     {
         int size = strlen(this->ch) + strlen(other.ch) + 1;
         String str(size);

         strcat_s(str.ch, size, this->ch);

         strcat_s(str.ch, size, other.ch);
         return str;
     }
     String operator+(const char* v)
     {
         int size = strlen(this->ch) + strlen(v) + 1;
         String str(size);

         strcat_s(str.ch, size, this->ch);

         strcat_s(str.ch, size, v);
         return str;
     }
     String operator*(const char* v)
     {
       

         String str;

         char* p1;
         int i = 0;

         for (p1 = this->ch; *p1; p1++)
         {
             if (strchr(v, *p1) != NULL)
                 str.ch[i++] = *p1;
         }
         return str.ch;
     }
     String operator/(const char* v)
     {
        
         String str;
       
         char* p1;
         int i = 0;
        
         for (p1=this->ch; *p1; p1++)
         {
             if (strchr(v, *p1) == NULL)
                 str.ch[i++] = *p1;
         }
         return str.ch;


     }
     bool operator <(const char* v)
     {

         return    strcmp(this->ch, v);

     }
    bool operator >(const char* v)
     {

        if (strcmp(this->ch, v) == 1)
            return 1;
        else
        {
            return 0;
        }

     }
     bool operator <=(const char* v)
     {
         if (strcmp(this->ch, v) == -1 || strcmp(this->ch, v) == 0)
             return 1;
         else
         {
             return 0;
         }
     }
    bool operator >=(const char* v)
     {
        if (strcmp(this->ch, v) == 1 || strcmp(this->ch, v) == 0)
            return 1;
        else
        {
            return 0;
        }
     }
    bool operator ==(const char* v)
    {

        if (strcmp(this->ch, v) == NULL)
        return 1;
        else
        {
            return 0;
        }

    }
    bool operator !=(const char* v)
    {

        if (strcmp(this->ch, v) != NULL)
            return 1;
        else
        {
            return 0;
        }

    }
    
    void operator[]( unsigned index) 
    {
        cout<< this->ch[index];
        
    }
    String operator()(int start, int len=NULL)
    {

        if (start<0 || start>strlen(this->ch))
        {
            return " ";
        }
        else if (len<0 || len>strlen(this->ch))
        {
            return this->ch;
        }
        else if (len == NULL)
        {
            int size = strlen(this->ch) - start;
            String result(size+1);
            for (int i = 0; i < size; i++)
            {
                
                result.ch[i] = this->ch[start + i];
            }
            return result.ch;
        }
        else 
        {
            String result(len + 1);
        for (int i = 0; i < len; i++ )
        {
            
                result.ch[i] = this->ch[start + i];
                
          
        }
        return result.ch;
    }
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

        char* p1;
        int i = 0;

        for (p1 = this->ch; *p1; p1++)
        {
            if (strchr(v, *p1) != NULL)
                str.ch[i++] = *p1;
        }
        return str.ch;

 

    }
    String& operator=(const String& other)
    {
        if (this != &other)
        {
            if (SIZE < other.SIZE)
            {
                delete[] ch;
                ch = new  char[other.SIZE];
            }
            this->SIZE = other.SIZE;
            for (size_t i = 0; i < SIZE; i++)
            {
                ch[i] = other.ch[i];
            }
        }
        return *this;
   }
    explicit operator int()const
    {
       return  atoi(this->ch);
      
    }
    String operator !()
    {
        int size = strlen(this->ch)-1;
        String result{ this->ch  };
        for (int i = 0; i <=size; i++)
        {
            result.ch[i] = this->ch[size - i];
        }
        
        return result.ch;
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
    cout << "Association: "<< s + (v);
    cout << "Association: " << s + ("Al");
    cout << "Cross: " << s * ("interesting");
    cout << "unCross: " << s / ("allways");
    cout << (s < ("interesting")) << endl;
     cout << (s > ("sa")) << endl;
     cout <<  (s <=("s")) << endl;
     cout << (s >= ("full")) << endl;
     cout << (s == ("string")) << endl;
     cout << (s != ("rain")) << endl;
     
    cout << "a: " << !s;
    String l{ "My program" };
    cout << "index & len: " << l(3,2);
    int a1 = 1;
    cout << "index ["<<a1<<"]: ";s[a1];
    cout << endl;
    String a = "201";
     cout<<"int: "<<(int)a;
    cout << endl;
    String f ;
    cout << "f=s: ";
    f = s;//присвоєння
    f.Show();
    cin>> s;
    cout<< s;
    ++s;
    s.Show();
    s++;
    s.Show();
   
    --s;
    s.Show();
    s--;
    s.Show(); 
    

    
     

   


    

}




