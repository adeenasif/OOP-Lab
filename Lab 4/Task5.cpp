#include<iostream>
using namespace std;

struct Item{  // fixed menu
	string ItemName;
	string type; // food or drink
	double price;
};

class CoffeeShop{  
	string name;  // coffee shop name
	Item* menu; 
	int menuSize;
	string *orders;  // list of order
	int orderSize;
	
	public:
		CoffeeShop(const string& name, const Item *menu, int menuSize){ // parameterized
			this->name = name;
			this->orders = new string[0];
			this->orderSize = 0;
			this->menuSize = menuSize;
			this->menu = new Item[menuSize];
			for (int i = 0; i < menuSize; i++){
				this->menu[i] = menu[i];
			}
		}
		
		string addOrder(const string& Dishname){
			
			for (int i = 0; i < menuSize; i++){
				if (Dishname == menu[i].ItemName){
					string* newOrders = new string[orderSize+1];
					for (int i = 0; i < orderSize; i++){
						newOrders[i] = orders[i];
					}
				
			        newOrders[orderSize] = Dishname;
			        
			        delete[] orders;
			        orders = newOrders;
			        orderSize++;
			        return Dishname + " added to the order\n";
				}
			}
			
		   	return Dishname + " is currently unavailable";
		}
		
		string fulfillOrder(){	
			if (orderSize == 0){  // order list is empty
				return "All orders have been fulfilled";	
			} 
			string item = orders[0];
			
			string* newOrders = (orderSize > 1) ? new string[orderSize - 1] : nullptr;
			for (int i = 1; i < orderSize; i++) {
			    newOrders[i - 1] = orders[i];
			}
			delete[] orders;
			orders = newOrders;
			orderSize--;
			
			return "The " + item + " is ready.";
		}
		
	    string* listOrder(int& count) const {
	        count = orderSize;
	        if (orderSize == 0) return nullptr;
	
	        string* orderList = new string[orderSize];
	        for (int i = 0; i < orderSize; i++) {
	            orderList[i] = orders[i];
	        }
	        return orderList;
	    }
		
		double dueAmount() const {
			double amount = 0.0;
			for (int i = 0; i < orderSize; i++) {
				for (int j = 0; j < menuSize; j++) {
					if (orders[i] == menu[j].ItemName) {
						amount += menu[j].price;
						break;
					}
				}
			}
			return amount;
		}
		
		string cheapestItem() const {
			if (menuSize == 0){
				return " ";
			}
			double cheapestPrice = menu[0].price;
			string cheapest = menu[0].ItemName;
			
			for (int j = 1; j < menuSize; j++){
				if (cheapestPrice > menu[j].price){
					cheapestPrice = menu[j].price;
					cheapest = menu[j].ItemName;
				}
			}
			return cheapest;
		}
		
		void getOrders() const{		
		for (int i = 0; i < orderSize; i++) {
		    cout << "Order " << i + 1 << ": " << orders[i] << endl;
		}
	}
		string* drinksOnly(int& drinkCount) const{
			drinkCount = 0;
			
			for (int i = 0; i < menuSize; i++){
				if (menu[i].type == "drink"){
					drinkCount++;
				}
			}
			
			if (drinkCount == 0){
				return nullptr;
			}
			
			string* drinks = new string[drinkCount];
			int j = 0;
			for (int i = 0; i < menuSize; i++){
				if (menu[i].type == "drink"){
					drinks[j++] = menu[i].ItemName;
				}
			}
			return drinks;
		}
		
		string* foodOnly(int& count) const {
		    count = 0;
		    
		    for (int i = 0; i < menuSize; i++) {
		        if (menu[i].type == "food") {
		            count++;
		        }
		    }
		    
		    if (count == 0) {
		    	return nullptr;	
			}
		
		    string* food = new string[count];
		    int j = 0;
		    
		    for (int i = 0; i < menuSize; i++) {
		        if (menu[i].type == "food") {
		            food[j++] = menu[i].ItemName;
		        }
		    }
		
		    return food;
	}

		
		~CoffeeShop(){
			delete[] menu;
			delete[] orders;
		}
};

int main(){
	Item menu[] = { {"Cappuccino", "drink", 6.0}, 
					{"Brownie", "food", 10.0}, 
					{"Latte", "drink", 3.5},
					{"Iced Tea", "drink", 4.5},
					{"Choco Cookie", "food", 3.75}};
					
	CoffeeShop shop("Melbrew", menu,  5);
	
	cout << "\n ---- WELCOME TO MELBREW! ---- \n" << endl;
    
    cout << "Menu: \n" << endl;
	int foodCount;
	string* foodItems = shop.foodOnly(foodCount);
	
	if (foodItems) {
	    cout << "Food items available: \n";
	    for (int i = 0; i < foodCount; i++) {
	        cout << " - " << foodItems[i] << endl;
	    }
	    delete[] foodItems; 
	} else {
	    cout << "No food items available.\n";
	}

	int drinkCount;
	string* drinkItems = shop.drinksOnly(drinkCount);
	
	if (drinkItems) {
	    cout << "\nDrink items available: \n";
	    for (int i = 0; i < drinkCount; i++) {
	        cout << " - "<< drinkItems[i] << endl;
	    }
	    delete[] drinkItems;
	} else {
	    cout << "No drink items available.\n";
	}
	cout << "\nThe Cheapest Item in our menu: " << shop.cheapestItem() << endl << endl;
	
	cout << shop.addOrder("Latte") << endl; 
	cout << shop.addOrder("Brownie") << endl; 
	cout << shop.addOrder("Tea") << endl << endl;

    int orderCount;
    string* orderList = shop.listOrder(orderCount);
	
	if (orderList) {
        cout << "Current orders: ";
        for (int i = 0; i < orderCount; i++) {
            cout << orderList[i] << (i < orderCount - 1 ? ", " : "\n");
        }
        delete[] orderList;
    } else {
        cout << "No orders pending.\n";
    }
    
	cout << "\nTotal amount: " << shop.dueAmount() << endl;
			
			
	cout << "\nStatus: \n";
	cout << "- " << shop.fulfillOrder() << endl;
	cout << "- " << shop.fulfillOrder() << endl;
	cout << "- " << shop.fulfillOrder() << endl;

	return 0;
}
