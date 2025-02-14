#include<iostream>
using namespace std;

class Matrix{
	int rows;
	int cols;
	int **elements;
	
	public:
		Matrix(){  // default
			rows = 0;
			cols = 0;
			
			elements = new int*[rows];
			for (int i = 0; i < rows; i++) {
            	elements[i] = new int[cols];
        	}
        	
			for (int i = 0; i < rows; i++){
				for (int j = 0; j <  cols; j++){
					elements[i][j] = 0;
				}
			}
		}
		
		Matrix(int rows, int cols){  // parameterized
			this->rows = rows;
			this->cols = cols;
			
			elements = new int*[rows];
			for (int i = 0; i < rows; i++) {
            	elements[i] = new int[cols];
        	}
        	
			for (int i = 0; i < rows; i++){
				for (int j = 0; j <  cols; j++){
					elements[i][j] = 0;
				}
			}
		}
		
		Matrix(const Matrix &obj){  // copy
			this->rows = obj.rows;
			this->cols = obj.cols;
			
			elements = new int*[rows];
			for (int i = 0; i < rows; i++) {
            	elements[i] = new int[cols];
        	}
        	
			for (int i = 0; i < rows; i++){
				for (int j = 0; j <  cols; j++){
					elements[i][j] = obj.elements[i][j];
				}
			}
		}
		
		Matrix(Matrix&& obj) noexcept : rows(obj.rows), cols(obj.cols), elements(obj.elements){  // move
			obj.elements = nullptr;
			obj.rows = 0;
			obj.cols = 0;
		}
		
		~Matrix(){  // destructor
			for (int i = 0; i < rows; i++){
				delete[] elements[i];
			}
			delete[] elements;
		}
		
		int getRows(){
			return rows;
		}

		int getCols(){
			return cols;
		}
		
		int at(int r, int c){
			return elements[r][c];
		}
		
		void fill(double value){
			for (int i = 0; i < rows; i++){
				for (int j = 0; j <  cols; j++){
					elements[i][j] = value;
				}
			}
		}
		
	void transpose() {
       int** Transpose = new int*[cols];
       for (int i = 0; i < cols; i++) {
           Transpose[i] = new int[rows];
       }

       // Transposing
       for (int i = 0; i < rows; i++) {
           for (int j = 0; j < cols; j++) {
               Transpose[j][i] = elements[i][j];
           }
       }

       // Printing Transposed Matrix
       for (int i = 0; i < cols; i++) {
           for (int j = 0; j < rows; j++) {
               cout << Transpose[i][j] << " ";
           }
           cout << endl;
       }

       // Clean up the allocated memory for the transposed matrix
       for (int i = 0; i < cols; i++) {
           delete[] Transpose[i];
       }
       delete[] Transpose;
   	}
		
		void display(){
			for (int i = 0; i < rows; i++){
				for (int j = 0; j <  cols; j++){
					cout << elements[i][j] << " ";
				}
				cout << endl;
			}
		}
};


int main(){
	Matrix m1(3,2);
	cout << "Matrix 1: " << endl;
	m1.display();
	cout << endl;
	
	m1.fill(10);
	cout << "Matrix 1 after filling: " << endl;
	m1.display();
	cout << endl;
	
	Matrix m2 = m1;
	cout << "Matrix 2 copied from Matrix 1: " << endl;
	m2.display();
	cout << endl;
	
	Matrix m3 = move(m1);
	cout << "Matrix 3 moved from Matrix 1: " << endl;
	m3.display();
	cout << endl;
	
	cout << "Transpose of matrix 2: " << endl;

	m2.transpose();
	
	int x = m2.at(1,1);	
	cout << "The element at row 1 and column 1: " << x << endl;
	
	int r = m2.getRows();
	cout << "Number of rows: " << r << endl;

	int c = m2.getCols();
	cout << "Number of colummns: " << c << endl;

	return 0;
}


