#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void matrix_multi_double(int n) {
    vector<vector<double>> A(n, vector<double>(n, 2.5));  
    vector<vector<double>> B(n, vector<double>(n, 3.0));  
    vector<vector<double>> C(n, vector<double>(n, 0.0));  

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
    double duration = double(end- start) / CLOCKS_PER_SEC;
    cout << "Double Matrix Multiplication (n=" << n << ") took " << duration << " seconds" << endl;
}

int main() {
    // Test with different values of n
    int ns[] = {64, 128, 256, 512, 1024};
    int nt = sizeof(ns) / sizeof(ns[0]);// Number of test

    cout << "Testing Double Matrix Multiplication:" << endl;
    for (int i = 0; i < nt; ++i) {
        matrix_multi_double(ns[i]);
    }

    return 0;
}
