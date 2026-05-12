#include <iostream>
using namespace std;
class FamilyBudget
{
private:
	FamilyBudget(const FamilyBudget&);
	FamilyBudget(int money = 0)
		:money(money)
	{}
	static FamilyBudget* instance;
	int money;

public:
	FamilyBudget& operator = (const FamilyBudget&) = delete;
	void addMoney(unsigned add)
	{
		money += add;
	}
	void spentMoney(unsigned sub)
	{
		if (money > sub) 
		{
			money -= sub;
		}
		else
		{
			cout << "Not enough money in the Budget" << endl;
		}
	}
	void print()  const
	{
		if (money > 0) {
			cout << "Money  ::: " << money << endl;
		}
		else
		{
			cout << "Budget is emply" << endl;
		}
	}
	static FamilyBudget* getBudget(int start = 10000)
	{
		if (instance == nullptr)
		{
			instance = new FamilyBudget(start);
		}
		return instance;
	}
	

};
FamilyBudget* FamilyBudget::instance = nullptr;


int NUM;
class Messages
{
private:
	int num_m;

	Messages(const Messages&);
	Messages(string message)
		:message(message)
	{
		if (message.size() != 0)
		{
			num_m = NUM + 1;
			NUM++;
		}
	}
	static Messages* instance;
	string message;
	

public:
	Messages& operator = (const Messages&) = delete;

	void addMessage(string add)
	{
		if (add.size() > 0) {
			message +=add;
			num_m = NUM;
			NUM++;
		}
	}
	
	void print()  const
	{
		
		if (num_m > 0 && message.size()!=0) {
			 
			cout << num_m<<": "<<message << " " << endl;
		}
		else
		{
			cout << "Emply" << endl;
		}
	}
	static Messages* getMessage(string start="Hi")
	{
		if (instance == nullptr)
		{
			instance = new Messages(start);
			NUM++;
		}
		return instance;
	}
	

};
Messages* Messages::instance = nullptr;


int main()
{
	/*FamilyBudget* budgetFather = FamilyBudget::getBudget(17000);
	budgetFather->addMoney(3'000);
	budgetFather->print();
	budgetFather->spentMoney(1);

	FamilyBudget* budgetMother = FamilyBudget::getBudget(5'000);
	budgetMother->addMoney(15'000);
	budgetFather->print();
	budgetMother->print();

	
	delete budgetFather;
	budgetMother->print();*/


	Messages* Tom = Messages::getMessage(" How are you?");
	
	Tom->print();
	

	Messages* Jake = Messages::getMessage();
	Jake->addMessage(" so so ");
	Jake->print();

	
	

	delete Tom;
	Jake->print();


}