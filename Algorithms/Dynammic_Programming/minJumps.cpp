// Find min jumps required to reach the end 
// Input: vector of map [1,0,0,1,...] 1=free, 0=obstacle
//        min jump length (int)
//        max jump length (int)
//        1 jump length    
// output: n

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> map = {0,0,1,0,0,1,1,0}; 
    int minJump = 3;
    int maxJump = 5;
    int n = map.size();
    int *dp = new int[n+1];  // stores min jumps require to reach i th cell

    // base case: If end within jump range take one jump only     
    dp[0] = 0;
    if (map[1]==1)
        dp[1] = INT_MAX-1;
    else
        dp[1] = 1; 

    for(int i {2}; i<=n; i++){
        vector<int> adjacentList;
        if(map[i]==1){
            dp[i] = INT_MAX-1;
            cout << i << ": " << dp[i] << endl; 
            continue;
        }
        adjacentList.push_back(dp[i-1]+1);
        
        for(int j{minJump}; j<=maxJump; j++){
            if(i-j>=0)
                adjacentList.push_back(dp[i-j]+1);
        }
        sort(adjacentList.begin(), adjacentList.end());
        dp[i] = adjacentList[0];
        cout << i << ": " << dp[i] << endl; 
    }
    cout << "Min Steps: " << dp[n] << endl; 
    return 0;
}
