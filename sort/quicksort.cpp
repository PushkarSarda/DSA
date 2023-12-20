#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int l, int r)
{
    int i=l-1;
    int pivot=arr[r];
    for(int j=l; j<r; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void quicksort(int arr[], int l, int r)
{
    if(l<r)
    {
        int mid=partition(arr, l, r);
        quicksort(arr, l, mid-1);
        quicksort(arr,mid+1, r);
    }   
}
int main()
{
    int arr[]={5,4,3,2,1};  
    quicksort(arr,0,4);
    for (int i=0; i<5; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}