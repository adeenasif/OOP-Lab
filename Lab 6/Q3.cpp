#include<iostream>
using namespace std;

class Employee{
	protected:
		int ID;
		string name;
	
	public:
		Employee(int id, string n){
			ID = id;
			name = n;
		}
};

class IOrderTaker{
	public:
		virtual ~IOrderTaker(){}
		virtual void TakeOrder() = 0;
};
class IOrderPreparer{
	public:
		virtual ~IOrderPreparer(){}
		virtual void PrepareOrder() = 0;
};
class IBiller{
	public:
		virtual ~IBiller(){}
		virtual void TakeBill(double amount) = 0;
};

class Waiter : public Employee, public IOrderTaker {
	public:
		Waiter(int id, string n) : Employee(id, n) { }
		
		void TakeOrder() override {
			cout << "Waiter " << name << " is taking order!! " << endl;
		}
};

class Chef : public Employee, public IOrderPreparer{
	public:
	Chef(int id, string n) : Employee(id, n) { }
	
	void PrepareOrder() override {
		cout << "Chef " << name << " is preparing order!! " << endl;
	}
};

class Cashier : public Employee, public IBiller{
	public:
	Cashier(int id, string n) : Employee(id, n) { }

	void TakeBill(double amount) override {
		cout << "Cashier " << name << " is generating bill!! " << endl;
	}
};

class Manager : public Employee, public IOrderTaker, public IBiller{
	public:
		Manager(int id, string n) : Employee(id, n) { }

		void TakeOrder() override {
			cout << "Manager " << name << " is taking order!! " << endl;
		}
		void TakeBill(double amount) override {
			cout << "Manager " << name << " is generating bill of $" << amount << endl;
		}
};

class Menu{
	protected:
		string menuName;
	public:
		Menu(string mn) : menuName(mn) { }
		virtual ~Menu(){}
		virtual double calcCost(int itemCount) = 0;
};

class FoodMenu : public Menu{
	double foodPrice;
	const double foodPricePerItem;
	
	public:
		FoodMenu(string mn) : Menu(mn), foodPrice(0.0), foodPricePerItem(10.0) { }
		
		double calcCost(int itemCount) override { 
			foodPrice += foodPricePerItem * itemCount;
			cout << "Total Price of " << menuName << " is $" << foodPrice << endl;
			return foodPrice;
		}
};

class BeverageMenu : public Menu{
	double bevPrice;
	const double bevPricePerItem;
	public:
		BeverageMenu(string mn) : Menu(mn), bevPrice(0), bevPricePerItem(5) { }
		
		double calcCost(int itemCount) override { 
			bevPrice += bevPricePerItem * itemCount;
			cout << "Total Price of " << menuName << " is $" << bevPrice << endl; 
			return bevPrice;
		}
};

int main(){
    FoodMenu food("Food Menu");
	double foodP = food.calcCost(5);
    cout << endl;
    BeverageMenu beverage("Beverage Menu");
    double bevP = beverage.calcCost(5);
    cout << endl;
    double total = bevP + foodP;
    
    Waiter w(101, "Raza");
    w.TakeOrder();
    
    cout << endl;
    
    Chef c(102, "Ali");
    c.PrepareOrder();
    
    cout << endl;
    Cashier cash(103, "Ayesha");
    cash.TakeBill(total);
    
    cout << endl;
    Manager m(104, "Adeena");
    m.TakeOrder();
    
    cout << endl;
    m.TakeBill(total);
    
    return 0;

}
