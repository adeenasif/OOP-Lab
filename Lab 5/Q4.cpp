#include<iostream>
#include <unistd.h> // to use sleep function
using namespace std;

class JuiceMaker{
	int numOfFruits;
	string *fruits;
	
	public:
		JuiceMaker(int numOfFruits){
			this->numOfFruits = numOfFruits;
			fruits = new string[numOfFruits];
			string tempFruits[] = {"Mango", "Apple", "Peach", "Kiwi"};
			for (int i = 0; i < numOfFruits; i++){
				fruits[i] = tempFruits[i];
			}
		}
		
		void blend(string fruit){
			int found = 0;
			for (int i = 0; i < numOfFruits; i++){
				if (fruit == fruits[i]){
					found = 1;
					cout << "Blending..." << endl;
					for(int i = 0; i < 1000000000; i++){
						// to delay
					}
					cout << fruit << " is blended!\n" << endl;
					break;
				}
			}
			if(!found){
				cout << "Sorry! " << fruit << " is not available!" << endl;
			}
		}
		
		void grind(string fruit){
			int found = 0;
			for (int i = 0; i < numOfFruits; i++){
				if (fruit == fruits[i]){
					found = 1;
					cout << "Grinding..." << endl;
					sleep(4);	
					cout << fruit << " is grinded!" << endl;
					break;
				}
			}
			if(!found){
				cout << "Sorry, this fruit is not existing on the list!" << endl;
			}
		}
};

int main(){
	JuiceMaker juice(4);
	
	juice.blend("Mango");
	juice.grind("Peach");
	juice.blend("Orange");
	return 0;
}
