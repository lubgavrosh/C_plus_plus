#include <iostream>
#include <string>
#include <sstream>




using namespace std;


void Find(const string& text, const string& word)
{
   
  
    int ind = -1;
    size_t pos = text.find(word); // шукаємо перше входження слова word у text
    while (pos != string::npos)// -1
    {

        pos = text.find(word, pos + 1);
        ind = text.find(word, pos + 1);
    }
    cout << ind;
}
void rFind(string& text, const string& word)
{
    
   
    int ind = -1;
    
    size_t pos = text.rfind(word); // шукаємо перше входження слова word у text
    while (pos != string::npos)// -1
    {

        pos = text.rfind(word, pos - 1);

        ind = text.rfind(word, pos - 1);
        
    }

    cout << ind;
}

void IP(string& text)
{
    string s = text;
    int ip1, ip2, ip3, ip4;
    getline(cin, s);
    int first = s.find_first_of(".");
    int second = s.find_first_of(".", first + 1);
    int three = s.find_first_of(".", second + 1);
    int four = s.find_first_of(".", three + 1);

    if ((first + 1) != second && (second + 1) != three && (three + 1) != four && first > 0)
    {
        if (first != -1 && second != -1 && three != -1 && four == -1)
        {
            ip1 = stoi(s);
            ip2 = stoi(s.substr(first + 1, second - first - 1));
            ip3 = stoi(s.substr(second + 1, three - second - 1));
            ip4 = stoi(s.substr(three + 1, four - three - 1));
            if ((ip1 >= 0 && ip1 <= 255) && (ip2 >= 0 && ip2 <= 255) && (ip3 >= 0 && ip3 <= 255) && (ip4 >= 0 && ip4 <= 255))
            {
                cout << "IP: <" << s << "> IS CORRECT";
            }
            else
            {
                cout << "IP: <" << s << "> NOT EXIST";
            }
        }
        else if (four != -1)
        {
            cout << "IP: <" << s << "> NOT EXIST";
        }
    }
    else  cout << "IP: <" << s << "> NOT EXIST";
}

int main()
{
    /*
    string  str = "A type that describes 123 a typeinfo 7878 specialization  9090 9 type of the class template basic_string with elements of type char as a string.";
    cout << str << endl;
    string num;
    cout << "Enter u number: ";
    cin >> num;
    cout << "{"; Find(str,num); cout << ","; rFind(str,num);cout << "}" << endl;
    */

    string s;
    IP(s);

}
