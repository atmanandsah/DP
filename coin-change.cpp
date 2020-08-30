#include<bits/stdc++.h>
using namespace std;
//topdown dp
int coinchange(int n,int coins[],int dp[],int T){
    if(n == 0) return 0;
    if(dp[n]!=0){
        return dp[n];
    }
    for(int i=0;i<=T;i++){
        int ans = INT_MAX;
        if(coins[i]-n>=0){
            int currentans = coinchange(coins[i]-n,coins,dp,T);
            dp[i] = min(ans,currentans)+1;
        }
        
    }
    return dp[n];
    
}
int main(){
    int n=15;
    //cin>>n;
    int coins[] = {1,7,10};
    int dp[100] = {0};
    int T = sizeof(coins)/sizeof(int);
    cout<<coinchange(n,coins,dp,T)<<endl;
    cout<<endl;
}