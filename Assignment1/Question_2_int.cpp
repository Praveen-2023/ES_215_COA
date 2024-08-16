#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void matrix_multi_int(int n) {
    vector<vector<int>> A(n, vector<int>(n, 2));  
    vector<vector<int>> B(n, vector<int>(n, 1));  
    vector<vector<int>> C(n, vector<int>(n, 0));  
    clock_t start = clock();

    // Matrix multiplication
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Integer Matrix Multiplication (n =" << n << ") took "<< duration << " seconds" << endl;
}

int main() {
    // Test with different values of n
    for (int n : {64, 128, 256, 512, 1024}) {
        matrix_multi_int(n);
    }
    return 0;
}
