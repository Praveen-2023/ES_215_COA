// using loops
#include<iostream>
using namespace std;
void fib(int n){
    long long x=0,y=1,z;
    if (n>=1)
        cout<<"1"<<" - "<<x<<endl;
    if(n>=2)
        cout<<"2"<<" - "<<y<<endl;
    for(int i = 2;i<n;i++){
        z = x + y;
        x = y;
        y = z;
        cout << i+1<<" - "<<z<<endl;
    }
}

int main(){
    cout<<"First 50 fibonaice are :\n"<<endl;
    fib(53);
}