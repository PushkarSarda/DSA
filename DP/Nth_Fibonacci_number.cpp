#include<bits/stdc++.h>
using namespace std;
int dp[101];
int fibo(int n)//Memoization
{
    if(n==0||n==1)
        return n;
    if(dp[n]!=-1)
        return dp[n];
    dp[n]=fibo(n-1)+fibo(n-2);
    return dp[n];
}
int fibo2(int n)//Tabulation
{
    dp[0]=0;
    dp[1]=1;
    for(int i=2; i<=n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main()
{
    memset(dp,-1,sizeof(dp));//macro to set defaults to an arrays
    while(true)
    {
        int n;
        cin>>n;
        cout<<fibo(n);
        cout<<endl;
        cout<<fibo2(n);
    }
}