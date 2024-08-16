// using loops and memoization
#include<iostream>
#include<vector>
using namespace std;
void fib(int n){
    vector<long long>arr(n,0);
    if (n>=1) arr[0] = 0;
    if (n>=2) arr[1] = 1;
    for (int i = 2; i<n;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    for (int i = 0; i<n;i++){
        cout<<i+1<<" - "<<arr[i]<<endl;
    }
}

int main(){
    fib(50);
    return 0;
}