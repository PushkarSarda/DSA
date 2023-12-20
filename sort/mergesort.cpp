#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int mid, int r)
{
    int len1=mid-l+1;
    int len2=r-mid;
    int arr1[len1];
    int arr2[len2];
    for (int i=0; i<len1; i++)
    {
        arr1[i]=arr[l+i];
    }
    for(int i=0; i<len2; i++)
    {
        arr2[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<len1 && j<len2)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k]=arr1[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=arr2[j];
            j++;
            k++;
        }
    }
    while(i<len1)
    {
        arr[k]=arr1[i];
        k++;
        i++;
    }
    while(j<len2)
    {
        arr[k]=arr2[j];
        k++;
        j++;
    }
}
void mergesort(int arr[],int l, int r)
{
    if(l<r)
    {

        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main()
{
    int arr[]={5,4,3,2,1};  
    mergesort(arr,0,4);
    for (int i=0; i<5; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}