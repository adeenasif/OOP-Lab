#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]){
    
	int* array = new int[5];
	
    if (argc < 7){
    	int size = argc - 1;
    	cout << "Without Resizing Array: " << endl;
    	for (int i = 0; i < size; i++){
    		array[i] = stoi(argv[i+1]);
		}
		for (int i = 0; i < size; i++){
    		cout << array[i] << " ";
		}
		cout << endl;
	
	} else {
		int size = argc - 1;
		int* NewArray = new int[10];
		memcpy(NewArray, array, 5 * sizeof(int));
		
		delete[] array; 
		array = NewArray;
		
		for (int i = 0; i < size; i++){
    		NewArray[i] = stoi(argv[i+1]);
		}
		
		int* FinalNew = new int[size];
		memcpy(FinalNew, NewArray, (size) * sizeof(int));
		
		delete[] array;
		array = FinalNew;
		
		cout << "Resized array: " << endl;
		for (int i = 0; i < size; i++){
    		cout << array[i] << " ";
		}
		cout << "\n";
	}
	
	delete[] array;
	return 0;
}
