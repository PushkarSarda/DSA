#include<bits/stdc++.h>
using namespace std;
void countsort(int arr[],int n)
{
    int countarr[20]={0};
    for(int i=0; i<n;i++)
    {
        countarr[arr[i]]++;
    }
    for(int i=1; i<20; i++)
    {
        countarr[i]+=countarr[i-1];
    }
    int ansarr[n];
    for(int i=n-1; i>=0; i--)
    {
        //countarr[arr[i]]--;
        ansarr[--countarr[arr[i]]]=arr[i];
        //countarr[arr[i]]-=1;
    }
    for(int i=0; i<n; i++)
        cout<<ansarr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    countsort(arr,n);
}