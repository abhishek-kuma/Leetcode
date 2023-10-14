#include<bits/stdc++.h>
using namespace std;

// 0-1 Knapsack Problem
// Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
int knapsack_recusive(int n,int w,int *weight , int * val){
    if(n==0 or w==0) return 0;
    if(weight[n-1]>w) return knapsack_recusive(n-1,w,weight,val);
    return max(knapsack_recusive(n-1,w-weight[n-1],weight,val)+val[n-1],knapsack_recusive(n-1,w,weight,val));
}

int dp[1000][1000];
int knapsack_memo(int n,int w,int *weight , int *val){
    if(n==0 or weight==0) return 0;
    if(dp[n][w] != -1) return dp[n][w];
    if(weight[n-1]>w) return dp[n][w]=knapsack_memo(n-1,w,weight,val);

    return dp[n][w]=max(knapsack_memo(n-1,w,weight,val),val[n-1]+knapsack_memo(n-1,w-weight[n-1],weight,val));
}

int knapsack_tabular(int n,int w,int *weight,int *val){
    // int dp[n+1][w+1];
    for(int i = 0 ;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<w;i++) dp[0][i]=0;
    //iterating over the loop
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(j < weight[i-1]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j-weight[i-1]]+val[i-1],dp[i-1][j]);
        }
    }
    return dp[n][w];
}
int main()
{
    int n = 3;
    int w = 5;
    int wt[]={1,3,6};
    int val[]={3,5,1};
    memset(dp,-1,sizeof(dp));
    cout <<"Knapsack Recursive : " <<knapsack_recusive(n,w,wt,val)<<endl;
    cout <<"Knapsack Memoise : " <<knapsack_memo(n,w,wt,val)<<endl;
    cout <<"Knapsack Tabular Approach : " <<knapsack_tabular(n,w,wt,val)<<endl;
    return 0;
}