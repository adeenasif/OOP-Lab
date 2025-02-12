#include<iostream>

using namespace std;

class Matrix{
	int rows;
	int cols;
	int **elements;
	
	public:
		Matrix(int rows, int cols){
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
		
		int get_rows() const{
			return rows;
		}
		
		int get_cols() const{
			return cols;	
		}
		
		void set_element(int i, int j, int value){
			elements[i][j] = value;
		}
		
		int get_elements(int i , int j) const{
			return elements[i][j];
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

Matrix addMatrices(const Matrix &m1, const Matrix &m2){
	if (m1.get_rows() == m2.get_cols() && m1.get_cols() == m2.get_cols()){
		int sum = 0;	
		Matrix sumMatrix(m1.get_rows(), m1.get_cols());
		
		for (int i = 0; i < m1.get_rows(); i++){
			for (int j = 0; j < m1.get_cols(); j++){
				int sum = m1.get_elements(i, j) + m2.get_elements(i, j);
	            sumMatrix.set_element(i, j, sum);	
			}
		}
		return sumMatrix;	
	} else {
		cout << "Matrices cannot be added!" << endl;
		return Matrix(0, 0); // Return empty matrix
	}

}
	
Matrix multiplyMatrices(const Matrix &m1, const Matrix &m2){
	if (m1.get_cols() == m2.get_rows()){
		
		Matrix multiplied(m1.get_rows(), m2.get_cols());
		
		for (int i = 0; i < m1.get_rows(); i++){
			for (int j = 0; j < m2.get_cols(); j++){
				int sum = 0;
				for (int k = 0; k < m1.get_cols(); k++) {
					sum += m1.get_elements(i,k) * m2.get_elements(k,j);
				}
				multiplied.set_element(i, j, sum);
			}
		}	
		return multiplied;		
	} else {
		cout << "Matrices cannot be multiplied!" << endl;
		return Matrix(0, 0); // Return empty matrix
	}
}

int main(){
	Matrix m1(2,2);
	Matrix m2(2,2);
	
	for (int i = 0; i < m1.get_rows(); i++){
		for (int j = 0; j < m1.get_cols(); j++){
			m1.set_element(i,j,4);
		}
	}
	
	cout << "Matrix 1: \n";
	m1.display();
	
	for (int i = 0; i < m2.get_rows(); i++){
		for (int j = 0; j < m2.get_cols(); j++){
			m2.set_element(i,j,2);
		}
	}
	cout << "\nMatrix 2: \n";
	m2.display();
	
	cout << "\nSum of both Matrix: " << endl;
	Matrix result = addMatrices(m1, m2);
	result.display();
	
	cout << "\nAns of both Matrices multiplied: " << endl;
	Matrix ans = multiplyMatrices(m1, m2);
	ans.display();
	
	return 0;
}
