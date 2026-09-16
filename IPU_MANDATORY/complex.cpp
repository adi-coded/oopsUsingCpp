#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

class matrix {
    int rows, cols;
    int** mat; 
public:
    matrix(int r, int c) {
        rows = r;
        cols = c;
        mat = new int*[rows];   
        for (int i = 0; i < rows; i++) {
            mat[i] = new int[cols]; 
        }
    }
    ~matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }

    matrix(const matrix& from) {
        cout << "Deep copy constructor is called" << endl;
        rows = from.rows;
        cols = from.cols;
        mat = new int*[rows];
        for (int i = 0; i < rows; i++) {
            mat[i] = new int[cols];
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = from.mat[i][j];
            }
        }
    }

    void initialize() {
        cout << "Enter the elements of the matrix" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }
    void print() const {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << setw(4) << mat[i][j];
            }
            cout << endl;
        }
    }

    matrix multiply(const matrix m2) const {

        if (this->cols != m2.rows) {
            throw invalid_argument("Matrix dimensions do not match for multiplication!");
        }
        matrix m3(this->rows, m2.cols); 
        
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < m2.cols; j++) {
                m3.mat[i][j] = 0; 
                
                for (int k = 0; k < this->cols; k++) {
                    m3.mat[i][j] += this->mat[i][k] * m2.mat[k][j];
                }
            }
        }
        return m3; 
    }
};

int main() {
    int r1, c1, r2, c2;
    
    cout << "Enter the number of rows and cols in 1st matrix: ";
    cin >> r1 >> c1;
    cout << "Enter the number of rows and cols in 2nd matrix: ";
    cin >> r2 >> c2;

    try {
        matrix m1(r1, c1);
        m1.initialize();
        m1.print();

        matrix m2(r2, c2);
        m2.initialize();
        m2.print();

        matrix m3 = m1.multiply(m2); 
        
        cout << "Resultant ";
        m3.print();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
