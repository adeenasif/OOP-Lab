#include<iostream>
using namespace std;

class DynamicArray{
	int *array;
	int size;
	
	public:
		DynamicArray(){  // Default
			size = 0;
			array = new int[size];
			array = nullptr;
		}
		
		DynamicArray(int n){  // Parameterized
			this->size = n;
			array = new int[size];
			for (int i = 0; i < size; i++){
				array[i] = 0;
			}
		}
		
		DynamicArray(const DynamicArray &obj){  // Copy
			size = obj.size;
			array = new int[obj.size];
			for (int i = 0; i < obj.size; i++){
 				array[i] = obj.array[i] ;
			}
		}
		
		DynamicArray(DynamicArray&& obj) noexcept : size(obj.size), array(obj.array){  // Move
			obj.size = 0;
			obj.array = nullptr;
		}
		
		DynamicArray& operator = (const DynamicArray& obj) { // Copy Operator
			if (this != &obj){
				delete[] array;
				size = obj.size;
				array = new int[size];
				for (int i = 0; i < size; i++){
					array[i] = obj.array[i];
				}
			}
			return *this;
		}
		
		DynamicArray& operator = (DynamicArray&& obj) { // Move Operator
			if (this != &obj){
				delete[] array;
				array = obj.array;
				size = obj.size;
				obj.array = nullptr;
				obj.size = 0;
			}
			return *this;
		}
		
		~DynamicArray(){  // destructor
			delete[] array;
		}
		
		int getSize(){
			return size;
		}
		
		int& at(int index){
			return array[index];
		}
		
		const int& at(int Index) const{
			return array[Index];
		}
		
		void resize(int newSize){
			if (newSize < 0 ){
				newSize = 0;
			}
			if (newSize == 0){
				delete[] array;
				array = nullptr;
				size = 0;
				return;
			}
			
			int* newArray = new int[newSize];
			for(int i = 0; i < newSize; i++){
				newArray[i] = 0;
			}
			
			for (int i = 0; i < size; i++){
				newArray[i] = array[i];
			}
			
			delete[] array;
			array = newArray;
			size = newSize;
		}
		
		void display(){
			cout << "[ " ;
			for (int i = 0; i < size; i++){
				if (i != size-1){
					cout << array[i] << ", ";
				} else {
				cout << array[i] ;
					
				}
			}
			cout << " ]" ;
		}
		void fillArray(){
			for (int i = 0; i < size; i++){
    			cout << "Enter element " << i+1 << ": ";
    			cin >> array[i];
    		}
		}
};

int main(){
	DynamicArray array;
	cout << "Default constructor called! Empty Array: " << endl;
	array.display();
	cout << endl;
	
	DynamicArray array1(5);
	array1.fillArray();
	cout << "Array 1: " << endl;
	array1.display();
	cout << endl << endl;
	
	array1.resize(8);
	cout << "\nArray 1 after resizing to 8: " << endl;
	array1.display();
	cout << endl << endl;
	
	DynamicArray array2 = array1;
	cout << "Array 2 copied from Array 1: " << endl;
	array2.display();
	cout << endl << endl;
	
	DynamicArray array3 = move(array1);
	cout << "Array 3 moved from Array 1: " << endl;
	array3.display();
	cout << endl << endl;
	
	array3.resize(10);
	cout << "\nArray 3 after resizing to 10: " << endl;
	array3.display();
	cout << endl << endl;
	
	int x = array3.at(2);
	cout << "Element at index 2 of Array 3: " << x << endl;
	
	return 0;
}
