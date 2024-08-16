#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// using recursion
long long fib_recursion(int n) {
    if (n <= 1)
        return n;
    return fib_recursion(n - 1) + fib_recursion(n - 2);
}

// using loops
long long fib_loops(int n) {
    long long x = 0, y = 1, z;
    if (n == 0) return x;
    if (n == 1) return y;
    for (int i = 2; i <= n; i++) {
        z = x + y;
        x = y;
        y = z;
    }
    return z;
}

// using recursion and memoization
long long fib_recursion_memoization(int n, vector<long long> &arr) {
    if (n <= 1) return n;
    if (arr[n] != -1) return arr[n];
    arr[n] = fib_recursion_memoization(n - 1, arr) + fib_recursion_memoization(n - 2, arr);
    return arr[n];
}

// using loops and memoization
void fib_loops_memoization(int n) {
    vector<long long> arr(n + 1, 0);
    if (n >= 1) arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

// Function to measure time and calculate speedup
void clock_time_speedup(int n) {
    struct timespec start, end;
    double time_recursion, time_loops, time_recursion_memoization, time_loops_memoization;

    // Time for recursion
    clock_gettime(CLOCK_MONOTONIC, &start);
    fib_recursion(n);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_recursion = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    // Time for loops
    clock_gettime(CLOCK_MONOTONIC, &start);
    fib_loops(n);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_loops = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    // Time for recursion with memoization
    vector<long long> memo(n + 1, -1);
    clock_gettime(CLOCK_MONOTONIC, &start);
    fib_recursion_memoization(n, memo);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_recursion_memoization = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    // Time for loops with memoization
    clock_gettime(CLOCK_MONOTONIC, &start);
    fib_loops_memoization(n);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time_loops_memoization = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    // Calculate speedups
    double speedup_loops = time_recursion / time_loops;
    double speedup_recursion_memoization = time_recursion / time_recursion_memoization;
    double speedup_loops_memoization = time_recursion / time_loops_memoization;

    // Print results
    cout << "Time for recursion: " << time_recursion << " seconds" << endl;
    cout << "Time for loops: " << time_loops << " seconds, Speedup: " << speedup_loops << "x" << endl;
    cout << "Time for recursion with memoization: " << time_recursion_memoization << " seconds, Speedup: " << speedup_recursion_memoization << "x" << endl;
    cout << "Time for loops with memoization: " << time_loops_memoization << " seconds, Speedup: " << speedup_loops_memoization << "x" << endl;
}

int main() {
    int n = 50; // First 50 Fibonacci numbers
    clock_time_speedup(n);
    return 0;
}
