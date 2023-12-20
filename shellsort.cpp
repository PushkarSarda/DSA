#include<bits/stdc++.h>
using namespace std;
void shellsort(int arr[],int n)
{
    int gap=n/2;
    int swaped;
    do
    {
        do
        {
            swaped=0;
            for(int i=0; i<n-gap;i++)
            {
                if(arr[i]>arr[i+gap])
                {
                    swap(arr[i],arr[i+gap]);
                    swaped=1;
                }
            }
        }while(swaped==1);
    }while((gap/=2)>=1);
}
int main()
{
    int arr[10]={10,9,8,7,6,5,4,3,2,1};
    shellsort(arr,10);
    for(int i=0; i<10; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}