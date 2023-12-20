/* 
You need to find minimum number of squares required to form a given number.
Eg: 26=4^2+3^2+1
      =5^2+1
    therefore, 2---> is the ans!!
*/

#include<bits/stdc++.h>
using namespace std;
int dp[101];
int MinSquare(int n)
{
  if(n<=3)
    return n;
  //int ans=INT_MAX;
  if(dp[n]!=INT_MAX)
    return dp[n];
  for(int i=1; (i*i)<=n; i++)
  {
    dp[n]=min(dp[n],1+MinSquare(n-i*i));
  }
  return dp[n];
}
signed main()
{
  int n;
  cin>>n;
  // memset(dp,INT_MAX,sizeof(dp));
  // int i=0;
  rep (i,0,101)
    dp[i]=INT_MAX;
  cout<<MinSquare(n)<<endl;
}