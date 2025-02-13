#include<iostream>
using namespace std;

class Matrix {
private:
    int nrows, ncols;
    int **elements;
public:
    Matrix(int r, int c) : nrows(r), ncols(c) {
    	elements = new int*[nrows];	
		for(int i=0 ; i<nrows ; i++){
			elements[i] = new int[ncols] ;
		}}
    
    int getRows() { return nrows; }
    int getCols() { return ncols; }
    
    void setElement(int i, int j, int val) {
        elements[i][j] = val;
    }
    
    Matrix add(Matrix& mat2) {
        if (nrows != mat2.nrows || ncols != mat2.ncols) {
            cout << "Matrices cannot be added" << endl;
            return Matrix(0, 0);
        }
        Matrix result(nrows, ncols);
        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < ncols; j++) {
                result.elements[i][j] = elements[i][j] + mat2.elements[i][j];
            }
        }
        return result;
    }
    
    Matrix multiply(Matrix& mat2) {
        if (ncols != mat2.nrows) {
            cout << "Matrices cannot be multiplied" << endl;
            return Matrix(0, 0);
        }
        Matrix result(nrows, mat2.ncols);
        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < mat2.ncols; j++) {
                result.elements[i][j] = 0;
                for (int k = 0; k < ncols; k++) {
                    result.elements[i][j] += elements[i][k] * mat2.elements[k][j];
                }
            }
        }
        return result;
    }
    
    void print() {
        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < ncols; j++) {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    int row1 = stoi(argv[1]), col1 = stoi(argv[2]);
    int row2 = stoi(argv[3]), col2 = stoi(argv[4]);
    
    Matrix matrix_i(row1, col1), matrix_ii(row2, col2);
    int index = 5;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            matrix_i.setElement(i, j, stoi(argv[index++]));
        }
    }
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            matrix_ii.setElement(i, j, stoi(argv[index++]));
        }
    }
    
    cout << "Matrix 1:" << endl;
    matrix_i.print();
    cout << "Matrix 2:" << endl;
    matrix_ii.print();
    
    cout << "Addition Result:" << endl;
    Matrix sum = matrix_i.add(matrix_ii);
    sum.print();
    
    cout << "Multiplication Result:" << endl;
    Matrix product = matrix_i.multiply(matrix_ii);
    product.print();
    
    return 0;
}
