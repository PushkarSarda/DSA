#include<bits/stdc++.h>
using namespace std;
int getbit(int n, int pos)
{
    return ((n&(1<<pos))!=0);
}
int setbit(int n, int pos)
{
    return(n|(1<<pos));
}
void findunique(int arr[], int n)
{
    int buffer[64]={0};
    // for(int i=0; i<n; i++)
    // {
    //     int temp=arr[i];
    //     int pos=0;
    //     while(temp>0)
    //     {
    //         if(temp&1)
    //         {
    //             buffer[pos]++;
    //         }
    //         pos++;
    //         temp=temp>>1;
    //     }
    // }
    // for (int i=0; i<64; i++)
    // {
    //     if(buffer[i]%3!=0)
    //     {
    //         cout<<pow(2,i)<<endl;
    //         break;
    //     }
    // }
    int result=0;
    for(int i=0; i<64; i++)
    {
        int sum=0;
        for(int j=0; j<n; j++)
        {
            if(getbit(arr[j],i))
            {
                sum++;
            }
        }
        if(sum%3!=0)
        {
            result=setbit(result,i);
        }
    }
    cout<<result<<endl;
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
    findunique(arr,n);
    return 0;
}