#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void matrix_multiplication_double(int N) {
    vector<vector<double>> A(N, vector<double>(N));
    vector<vector<double>> B(N, vector<double>(N));
    vector<vector<double>> C(N, vector<double>(N, 0.0));

    srand(static_cast<unsigned>(time(0)));

    // Initialize matrices A and B with random doubles
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = static_cast<double>(rand()) / RAND_MAX;
            B[i][j] = static_cast<double>(rand()) / RAND_MAX;
        }
    }

    clock_t start_time = clock();

    // Matrix multiplication
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    clock_t end_time = clock();
    double duration = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Double Matrix Multiplication (N=" << N << ") took " << duration << " seconds" << endl;
}

void matrix_multiplication_int(int N) {
    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));
    vector<vector<int>> C(N, vector<int>(N, 0));

    srand(static_cast<unsigned>(time(0)));

    // Initialize matrices A and B with random integers
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    clock_t start_time = clock();

    // Matrix multiplication
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    clock_t end_time = clock();
    double duration = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Integer Matrix Multiplication (N=" << N << ") took " << duration << " seconds" << endl;
}

int main() {
    // Test with different values of N
    int Ns[] = {64, 128, 256, 512, 1024};
    int num_tests = sizeof(Ns) / sizeof(Ns[0]);

    cout << "Testing Double Matrix Multiplication:" << endl;
    for (int i = 0; i < num_tests; ++i) {
        matrix_multiplication_double(Ns[i]);
    }

    cout << "\nTesting Integer Matrix Multiplication:" << endl;
    for (int i = 0; i < num_tests; ++i) {
        matrix_multiplication_int(Ns[i]);
    }

    return 0;
}
