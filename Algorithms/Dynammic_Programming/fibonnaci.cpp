#include<iostream>
using namespace std;

int fib(int n){
    if(n==0 || n==1)
        return 1;

    return fib(n-1) + fib(n-2);    
}

long fib2(long n, long *arr){
    if(n==0 || n==1){
        arr[0] = 1;
        arr[1] = 1;
        return 1;
    }    
    if (arr[n] >0)
        return arr[n];
    long output = fib2(n-1, arr) + fib2(n-2, arr);
    arr[n] = output;
    return output;    
}

int main(){
    long n {42};
    // cout << "Enter a number: ";
    // cin >> n;
    long arr[n+1] {0};
    long res = fib(n);
    cout << res << endl;
    return 0;
}

