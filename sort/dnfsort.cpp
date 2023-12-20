#include<bits/stdc++.h>
using namespace std;
void dnfsort(int arr[],int n)
{
    int low=0,mid=0;
    int high=n-1;
    while(mid<high)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[high],arr[mid]);
            high--;
        }
    }
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int arr[]={1,0,2,1,0,1,2,1,2};
    dnfsort(arr,9);
    cout<<endl;
    return 0;
}