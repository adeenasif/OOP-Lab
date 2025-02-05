#include<iostream>
using namespace std;

void* add(void* array, void* count, void* addValue){
	int* intArray = static_cast<int*>(array);
	int intCount = *static_cast<int*>(count);
	int value = *static_cast<int*>(addValue);
	
	for(int i = 0; i < intCount; i++){
		intArray[i] += value;
	}
	return static_cast<void*>(intArray);
}

int main(int argc, char* argv[]){
	int size = argc-1;
	int array[size];
	
	for (int i = 0; i < size; i++){
		array[i] = stoi(argv[i+1]);
	}
	
	//assuming 1st element is to be to added to each element in the array
	int addValue = array[0];
	
	void* returnArray = add(static_cast<void*>(array), static_cast<void*>(&size), static_cast<void*>(&addValue));
    int* finalArray = static_cast<int*>(returnArray);
    
    cout << "The Array Elements After Adding " << addValue << " To Each Element: "<< endl;
    for (int i = 0; i < size; i++){
        cout << finalArray[i] << " ";
    }
    cout << endl; 
    
    return 0;
}
