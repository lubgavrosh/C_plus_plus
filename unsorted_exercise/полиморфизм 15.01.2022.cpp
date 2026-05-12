#include <iostream>
#include <string>
#include <vector>
using namespace std;


unsigned IDnum;

class Animal
{
private:
    string nick;
    int age;
    int IDNUM = IDnum;
public:
    Animal(string nick_1, int age1)
    {
        nick = nick_1;
        age = age1;
        
        IDnum++;
    }
   
    virtual void setNick(string nick1) 
        
    {
        nick = nick1;
    }
     virtual int getID() const
    {
        return IDnum;
    }
   virtual  string getNick() const 
    {
       return nick;
    }
    virtual void setAge(int age1)
    {
        age = age1;
    }
   virtual int getAge() const
    {
        return age;
    }

   virtual void Show() const
    {
        cout << "\n\n____Animal___" << endl;
        cout << "Nick: " << getNick() << endl;
        cout << "Age: " << getAge() << endl;
       
        sound();
        type();
        cout << "IDnum: " << getID() << endl;
    }


    virtual void sound() const
    {
        cout << "Sound: unknow" << endl;
    }

    virtual void type() const
    {
        cout << "Type: unknow" << endl;
    }

    ~Animal()
    {
        cout << "Dctor worked" << endl;
    }
};


class Cat :public Animal
{
private:
    string color;
    unsigned IDNUM = IDnum + 1;
public:

    Cat(string nick_1="Murka", int age1=1, string color_c="Gray")
        :Animal(nick_1, age1)
    {
        color = color_c;
    }
    int getID() const
    {
        return IDNUM;
    }
    void setNick(string nick1)
        
    {
        Animal::setNick(nick1);
    }
  
   
     string getNick()
    {
        return  Animal::getNick();
    }
     void setAge(int age1)
    {

         Animal::setAge(age1);;
    }
     int getAge() const
    {

        return  Animal::getAge();
    }
    void sound() const override

    {
        cout << "Sound: Meow" << endl;
    }
    void type() const override
    {
        cout << "Type: Cat" << endl;
    }
   
    void Show() const
    {
        Animal::Show();
        cout << "Color: " << color << endl;

    }






    ~Cat()
    {
        cout << "Dctor worked" << endl;
    }
};



class Dog :public Animal
{
private:
    string color;
    unsigned IDNUM = IDnum + 1;
public:

    Dog(string nick_1="Rex", int age1=2, string color_c="White")
        :Animal(nick_1, age1)
    {
        color = color_c;
    }

    int getID() const
    {
        return IDNUM;
    }
    void setNick(string nick1)

    {
        Animal::setNick(nick1);
    }


    string getNick()
    {
        return  Animal::getNick();
    }
    void setAge(int age1)
    {

        Animal::setAge(age1);;
    }
    int getAge() const
    {

        return  Animal::getAge();
    }
    void sound() const override

    {
        cout << "Sound: Bark" << endl;
    }
    void type() const override
    {
        cout << "Type: Dog" << endl;
    }

    void Show() const
    {
        Animal::Show();
        cout << "Color: " << color << endl;

    }






    ~Dog()
    {
        cout << "Dctor worked" << endl;
    }
};



class Lynx :public Animal
{
private:
    string color;
    unsigned IDNUM = IDnum + 1;
public:

    Lynx(string nick_1="Bob", int age1 = 4, string color_c = "Gray")
        :Animal(nick_1, age1)
    {
        color = color_c;
    }

    int getID() const
    {
        return IDNUM;
    }
    void setNick(string nick1)

    {
        Animal::setNick(nick1);
    }


    string getNick()
    {
        return  Animal::getNick();
    }
    void setAge(int age1)
    {

        Animal::setAge(age1);;
    }
    int getAge() const
    {

        return  Animal::getAge();
    }
    void sound() const override

    {
        cout << "Sound: Purr" << endl;
    }
    void type() const override
    {
        cout << "Type: Wild Cat" << endl;
    }

    void Show() const
    {
        Animal::Show();
        cout << "Color: " << color << endl;

    }






    ~Lynx()
    {
        cout << "Dctor worked" << endl;
    }



};


class Wolv :public Animal
{
private:
    string color;
    unsigned IDNUM = IDnum + 1;
public:

    Wolv(string nick_1="Dark", int age1=6, string color_c="Black")
        :Animal(nick_1, age1)
    {
        color = color_c;
    }
    int getID() const
    {
        return IDNUM;
    }
    void setNick(string nick1)

    {
        Animal::setNick(nick1);
    }


    string getNick()
    {
        return  Animal::getNick();
    }
    void setAge(int age1)
    {

        Animal::setAge(age1);;
    }
    int getAge() const
    {

        return  Animal::getAge();
    }
    void sound() const override

    {
        cout << "Sound: Grow" << endl;
    }
    void type() const override
    {
        cout << "Type: Wolv" << endl;
    }

    void Show() const
    {
        Animal::Show();
        cout << "Color: " << color << endl;

    }






    ~Wolv()
    {
        cout << "Dctor worked" << endl;
    }



};


class Zoo
{

    vector <Animal*>zoo;
public:
    Zoo()
    {
        cout << "Zoo is empty" << endl;
    }

    void addAnimal()
    {
        string nick{};
        int age = 0;
        string color{};
        int num;;
        cout << "Enter type of Animal: " << endl;
        cout << " Cat-[1]" << endl;
        cout << " Dog-[2]" << endl;
        cout << " Wolv-[3]" << endl;
        cout << " Lynx-[4]" << endl;
        cin >> num;


        switch (num)
        {
        case 1:
        {
            cout << "Enter Nick: ";
            cin >> nick;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter color: ";
            cin >> color;


            Cat* cat = new Cat(nick, age, color);
            zoo.push_back(cat);
            break;
        }
        case 2:
        {
            cout << "Enter Nick: ";
            cin >> nick;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter color: ";
            cin >> color;


            Dog* dog = new Dog(nick, age, color);
            zoo.push_back(dog);
            break;
        }


        case 3:
        {
            cout << "Enter Nick: ";
            cin >> nick;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter color: ";
            cin >> color;


            Wolv* wolv = new Wolv(nick, age, color);
            zoo.push_back(wolv);
            break;
        }
        case 4:
        {
            cout << "Enter Nick: ";
            cin >> nick;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter color: ";
            cin >> color;

            Lynx* lynx = new Lynx(nick, age, color);
            zoo.push_back(lynx);
            break;
        }

        }
    }

    void Show()
    {
        if (zoo.size() > 0) {
            for (int i = 0; i < zoo.size(); i++)
            {
                zoo[i]->Show();
            }
            cout << endl;
        }
        else
            cout << "Zoo is empty" << endl;

    }

    
    void editAnimal()
    {
        Show();
        int a;
        string str;
        unsigned age;
        cout << "Enter IDnum of Animal : ";
        cin >> a;
        cout << "Enter new Nick: ";
        cin >> str;
        cout << "Enter new Age: ";
        cin >> age;
        if (a > 0)
        {
           
            for (int i = 0; i < zoo.size(); i++)
            {
                if (zoo[i]->getID() == a)
                {
                    zoo[i]->setNick(str);
                    zoo[i]->setAge(age);
                  


                }
            }
        }
    }

    void Add_Rnd_Animal()
    {
        int a = rand() % 4 + 1;
        switch (a)
        {
        case 1:
        {
            Cat* CAT = new Cat;
            zoo.push_back(CAT);
            break;
        }
        case 2:
        {
            Dog* DOG = new Dog;
            zoo.push_back(DOG);
            break;
        }
        case 3:
        {
            Lynx* LYNX = new Lynx;
            zoo.push_back(LYNX);
            break;
        }
        case 4:
        {
            Wolv* WOLV = new Wolv;
            zoo.push_back(WOLV);
            break;
        }
       }
        


    }
    void sale_All_animals()
    {
        for (int i = 0; i < zoo.size(); i++)
        {
            delete zoo[i];
        }
        zoo.clear();
    }
    void saleAnimal()
    {
        Show();
        int a;
        cout << "Enter IDnum of Animal : ";
        cin >> a;
        if (a > 0)
        {
            
            for (int i = 0; i < zoo.size(); i++)
            {
                if (zoo[i]->getID() == a)
                {

                    vector<Animal*>::iterator it = remove(zoo.begin(), zoo.end(), zoo[i]);
                    delete(*it);
                    zoo.erase(it);
                    
                }
            }
        }
    }



    ~Zoo()
    {
        for (int i = 0; i < zoo.size(); i++)
        {
            delete zoo[i];
        }
        zoo.clear();
        cout << "Dtor zoo worked" << endl;
    }
};



void  main()
{
    srand(time(NULL));
    /*Animal q("Noname", 1);
    q.Show();
    Cat cat("Murka", 2, "black");
    cat.Show();
    Dog dog("Rex", 3, "White");
    dog.Show();

    cout << "\n\n_____ArrayAnimal____" << endl;
    Animal* arr[] = { new Cat("Musya",2,"orange"),new Dog("Jack", 1, "Black")};
    for (int i = 0; i < 2; i++)
    {
        arr[i]->Show();
    }*/


    Zoo a;

    
    a.Add_Rnd_Animal();
    a.Add_Rnd_Animal();
    a.Add_Rnd_Animal();
    a.Show();
    

   
}
