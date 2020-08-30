#include<bits/stdc++.h>
using namespace std;

int dptoone(int n,int dp[]){
    //base case
    if(n==1){
        return 0;
    }
    if(dp[n] != 0){
        return dp[n];
    }
    // rec case
    int opt1,opt2,opt3;
    opt1 = opt2 = opt3 =INT_MAX;
    if(n%3 == 0){
        opt1 = dptoone(n/3,dp);
    }
    if(n%2 == 0){
        opt2 = dptoone(n/2,dp);
    }
    opt3 = dptoone(n-1,dp);

    int ans = min(opt3,min(opt2,opt1))+1;

    return dp[n] = ans;

}
int minstepone(int n){
    //buttom up approach
    int dp[100] = {0};
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        int opt1,opt2,opt3;
        opt1 = opt2 = opt3 = INT_MAX;
        if(n%3 == 0){
            opt3 = dp[i/3];
        }
        else if(n%2 == 0){
            opt2 = dp[i/2];
        }
        opt1 = dp[i-1];
        dp[i] = min(min(opt1,opt2),opt3)+1;
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    int dp[100] = {0};
    //cout<<dptoone(n,dp);
    cout<<endl;
    cout<<minstepone(n)<<endl;
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
}