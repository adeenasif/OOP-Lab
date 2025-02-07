#include<iostream>

using namespace std;

class Glass{
	public:
		int LiquidLevel;
		
		void setLevel(int level){
			LiquidLevel = level;
		}
		
		void Refill(){
			LiquidLevel = 200;
			cout << "Glass is refilled to 200" << endl;
		}
		
		void Drink(int milliliters){
			LiquidLevel -= milliliters;
			cout << "You just drank "<< milliliters << " ml!" << endl;
			if (LiquidLevel < 100){
				Refill();
			} else {
				cout << "No need to refill!!";
			}
		}	
};

int main(int argc, char* argv[]){
	Glass obj;
	
	obj.setLevel(200);
	int milliliters = stoi(argv[1]);
	obj.Drink(milliliters);
	
	return 0;
}
