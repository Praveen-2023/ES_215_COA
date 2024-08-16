// using recursion and memoization
#include<iostream>
#include<vector>
using namespace std;
long long fib(int n,vector<long long>&arr){
    if (n<=1)return n;
    if (arr[n]!=-1) return arr[n];
    arr[n] = fib(n-1,arr) + fib(n-2,arr);
    return arr[n];

}

int main(){
    vector<long long> arr(50,-1);
    for (int i = 0; i<50; i++){
        cout << i+1<<" - "<<fib(i,arr)<<endl;
    }

}