#include<bits/stdc++.h>
using namespace std;
int getbit(int n, int pos)
{
    return ((n&(1<<pos))!=0);
}
void uniquetwo (int arr[], int n)
{
    int xorsum=0;
    for (int i=0; i<n; i++)
    {
        xorsum^=arr[i];
    }
    int setbit=xorsum&1; 
    int pos=0;
    while(setbit!=1)
    {
        pos++;
        xorsum=xorsum>>1;
        setbit=xorsum&1;
    }
    int xorsum2=0;
    for(int i=0; i<n; i++)
    {
        if(getbit(arr[i],pos))
        {
            xorsum2^=arr[i];
        }
    }
    while(pos--)
    {
        xorsum=xorsum<<1;
    }
    cout<<xorsum2<<" "<<(xorsum^xorsum2)<<endl;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    uniquetwo(arr,n);
    return 0;
}