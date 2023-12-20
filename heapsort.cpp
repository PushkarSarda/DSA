#include<bits/stdc++.h>
using namespace std;
void reheapdown(int arr[],int n, int i)
{
    while((2*i)+1<n)
    {
        int j=(2*i)+1;
        if(j+1<n && arr[j+1]>arr[j])
            j++;
        if(arr[i]>arr[j])
                break;
        else
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i=j;
            }
    }
}
void heapsort(int arr[],int n)
{
    int i;
    for(i=(n-1)/2; i>=0; i--)
    {
        cout<<i<<"hi";
        reheapdown(arr,n,i);
        cout<<"HI";
        cout<<endl;
    }
    cout<<"HI"<<endl;
    while(n>0)
    {
        int temp=arr[0];
        arr[0]=arr[n-1];
        arr[n-1]=temp;
        n--;
        reheapdown(arr,n,0);
    }
}
int main()
{
    int arr[5]={5,4,3,2,1};
    heapsort(arr,5);
    cout<<"JIJI"<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<" ";
    }
}
/*int main()
{
    int arr[10],n,i;
    cout<<"Enter n:"<<endl;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];
    heapsort(arr,n);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}*/