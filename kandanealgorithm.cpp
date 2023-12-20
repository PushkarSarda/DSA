#include<bits/stdc++.h>
using namespace std;
int kandane(int n, int arr[n])
{
    int currsum=0;
    int maxsum=INT_MIN;
    for (int i=0; i<n; i++)
    {
        currsum+=arr[i];
        if(currsum<0)
        {
            currsum=0;
        }
        maxsum=max(maxsum,currsum);
    }
    return maxsum;
}
int main()
{
     int n;
    cin>>n;
    int arr[n];
    for(int i =0; i<n; i++)
    {
        cin>>arr[i];
    }
    int totalsum=0;
    for (int i=0; i<n; i++)
    {
        totalsum+=arr[i];
    }
    cout<<kandane(n,arr)<<endl;
    for (int i=0; i<n; i++)
    {
        arr[i]=-1*arr[i];
    }
    cout<<kandane(n,arr)<<endl;
    int ans=totalsum+kandane(n,arr);
    cout<<ans<<endl;
}