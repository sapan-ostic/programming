// Given an int n, find the number of steps required to drop to 1 if allowed actions are:
// n-1
// n/2 if n%2=0
// n/3 if n%3=0

# include<bits/stdc++.h>
using namespace std;

int solveByRecurssion(int n){   

    if (n<=1){
        return 0;    
    }    
    int steps1 = solveByRecurssion(n-1); // 2(1)
    int steps3 = INT_MAX;
    int steps2 = INT_MAX;

    if (n%2==0)
        steps2 = solveByRecurssion(n/2); // 2(1)

    if (n%3==0)
        steps3 = solveByRecurssion(n/3);
    int res = min(min(steps2, steps3), steps1)+1;
    return res;
}

int solveByMemorization(int n, int *arr){   

    if (n<=1){
        return 0;            
    }
    if (arr[n]>0)
        return arr[n];

    int steps1 = solveByMemorization(n-1, arr); // 2(1) 
    int steps3 = INT_MAX;
    int steps2 = INT_MAX;

    if (n%2==0)
        steps2 = solveByMemorization(n/2, arr); // 2(1)

    if (n%3==0)
        steps3 = solveByMemorization(n/3, arr);
    int res = min(min(steps2, steps3), steps1)+1;
    arr[n] = res;
    return res;
}

int solveByDP(int n){
     int *dp = new int[n+1];
     dp[0] = 0;
     dp[1] = 0;

    for(int i{2}; i<=n; i++){
        
        int steps1 = dp[i-1];
        int steps2 = INT_MAX;
        int steps3 = INT_MAX;

        if(i%2==0)
            steps2 = dp[i/2];
        if(i%3==0)
            steps3 = dp[i/3];
        dp[i] = min(min(steps2, steps3), steps1)+1;
    }
    int res = dp[n];
    delete []dp; 
    return res;
}

int main(){
    int n = 10;
    cout << "Enter a number: ";
    cin >> n;
    int steps = solveByRecurssion(n);
    cout << "min steps: " << steps << endl;
    int arr[n] {0};
    steps = solveByMemorization(n, arr);
    cout << "min steps: " << steps << endl;
    steps = solveByDP(n);
    cout << "min steps: " << steps << endl; 
    return 0; 
}
