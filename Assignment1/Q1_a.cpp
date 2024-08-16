//using recursion
#include<iostream>
using namespace std;
long long fib(int n){
    if (n<=1)
        return n;
    return fib(n-1) + fib(n-2);

}
int main(){
    cout<<"First 50 fibonaice sequence :\n";
    for (int i = 0;i<50;i++){
        cout<<i+1<<" - "<<fib(i)<<" "<<endl;
    }

}
