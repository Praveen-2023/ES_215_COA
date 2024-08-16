#include <iostream>
#include <vector>
#include<time.h>
#include <ctime>
#include <cstdlib>
using namespace std;

// using recursion
long long fib_rec(int n) {
    if (n <= 1)
        return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

// using loops
long long fib_loops(int n) {
    long long x = 0,y = 1,z;
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
long long fib_rec_memo(int n, vector<long long> &arr) {
    if (n <= 1) return n;
    if (arr[n] != -1) return arr[n];
    arr[n] = fib_rec_memo(n - 1, arr) + fib_rec_memo(n - 2, arr);
    return arr[n];
}

// using loops and memoization
void fib_loops_memo(int n){
    vector<long long>arr(n,0);
    if (n>=1) arr[0] = 0;
    if (n>=2) arr[1] = 1;
    for (int i = 2; i<n;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
}
// Function to measure time and calculate average speedup
void clock_time_speedup(int n, int itr) {
    struct timespec start, end;
    double total_time_rec = 0, total_time_loops = 0,total_time_rec_memo = 0, total_time_loops_memo = 0;
    double time_rec_1 = 0, time_loops_1 = 0,time_rec_memo_1 = 0, time_loops_memo_1 = 0;

    for (int i = 0; i< itr; i++) {

        clock_gettime(CLOCK_MONOTONIC, &start);
        fib_rec(n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        double time_rec = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        total_time_rec += time_rec;
        if (i == 0) time_rec_1 = time_rec;

        clock_gettime(CLOCK_MONOTONIC, &start);
        fib_loops(n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        double time_loops = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        total_time_loops += time_loops;
        if (i == 0) time_loops_1 = time_loops;

        vector<long long> memo(n + 1, -1);
        clock_gettime(CLOCK_MONOTONIC, &start);
        fib_rec_memo(n, memo);
        clock_gettime(CLOCK_MONOTONIC, &end);
        double time_rec_memo = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        total_time_rec_memo += time_rec_memo;
        if (i == 0) time_rec_memo_1 = time_rec_memo;

        clock_gettime(CLOCK_MONOTONIC, &start);
        fib_loops_memo(n);
        clock_gettime(CLOCK_MONOTONIC, &end);
        double time_loops_memo = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        total_time_loops_memo += time_loops_memo;
        if (i == 0) time_loops_memo_1 = time_loops_memo;
    }

    // Calculating average times
    double avg_time_rec = total_time_rec / itr;
    double avg_time_loops = total_time_loops / itr;
    double avg_time_rec_memo = total_time_rec_memo / itr;
    double avg_time_loops_memo = total_time_loops_memo / itr;

    // Calculating speedups
    double speedup_loops = avg_time_rec / avg_time_loops;
    double speedup_rec_memo = avg_time_rec/ avg_time_rec_memo;
    double speedup_loops_memo = avg_time_rec / avg_time_loops_memo;

    // Results
    cout << "Time for 1st iteration (recursion): " << time_rec_1 << " seconds" << endl;
    cout << "Time for 1st iteration (loops): " << time_loops_1 << " seconds" << endl;
    cout << "Time for 1st iteration (recursion with memoization): " << time_rec_memo_1 << " seconds" << endl;
    cout << "Time for 1st iteration (loops with memoization): " << time_loops_memo_1<< " seconds" << endl;

    cout << "Average time for recursion: " << avg_time_rec << " seconds" << endl;
    cout << "Average time for loops: " << avg_time_loops << " seconds, Speedup: " << speedup_loops << "x" << endl;
    cout << "Average time for recursion with memoization: " << avg_time_rec_memo << " seconds, Speedup: " << speedup_rec_memo << "x" << endl;
    cout << "Average time for loops with memoization: " << avg_time_loops_memo << " seconds, Speedup: " << speedup_loops_memo << "x" << endl;
}

int main() {
    int n = 50; // First 50 Fibonacci numbers
    int itr = 10; // Number of iterations to compute average time
    clock_time_speedup(n, itr);
    return 0;
}
