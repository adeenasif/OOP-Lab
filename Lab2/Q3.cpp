#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]){
    
	int* Array = new int[5];
    if (argc <= 6){
    	int Size = argc - 1;
    	cout << "Without Resizing Array: " << endl;
    	for (int i= 0; i < Size; i++){
    		Array[i] = stoi(argv[i+1]);
		}
		for (int i= 0; i < Size; i++){
    		cout << Array[i] << " ";
		}
		cout << endl;
	
	}else{
		int Size = argc - 1;
		int* NewArray = new int[10];
		memcpy(NewArray, Array, 5 * sizeof(int));
		delete[] Array; 
		Array = NewArray;
		
		for (int i = 0; i < Size; i++){
    		NewArray[i] = stoi(argv[i+1]);
		}
		
		int* FinalNew = new int[Size];
		memcpy(FinalNew, NewArray, (Size) * sizeof(int));
		delete[] Array;
		Array = FinalNew;
		cout << "Resized array: " << endl;
		for (int i = 0; i < Size; i++){
    		cout << Array[i] << " ";
		}
		cout << "\n";
	}
	
	delete[] Array;
	return 0;
}

