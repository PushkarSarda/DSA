#include<bits/stdc++.h>
using namespace std;
int merge(int arr[],int l,int mid, int r)
{
    int len1=mid-l+1;
    int len2=r-mid;
    int arr1[len1];
    for(int i=0; i<len1; i++)
        arr1[i]=arr[i+l];
    int arr2[len2];
    for(int i=0; i<len2; i++)
        arr2[i]=arr[mid+1+i];
    int i=0;
    int j=0;
    int k=l;
    int inv=0;
    while(i<len1  && j<len2)
    {
        if(arr1[i]>arr2[j])
        {
            arr[k]=arr2[j];
            j++;
            k++;
            inv+=len1-i;
        }
        else
        {
            arr[k]=arr1[i];
            i++;
            k++;
        }
    }
    while(i<len1)
    {
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<len2)
    {
        arr[k]=arr2[j];
        j++;
        k++;
    }
    return inv;
}
int mergesort(int arr[],int l, int r)
{
    int ans=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        ans+=mergesort(arr,l,mid);
        ans+=mergesort(arr,mid+1,r);
        ans+=merge(arr,l,mid,r);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"no of inversions are= "<<mergesort(arr,0,n-1)<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}