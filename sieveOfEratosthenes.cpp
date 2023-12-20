#include<bits/stdc++.h>
using namespace std;
void printprimenoupto(int n)
{
    int arr[n+1];
    for(int i=0; i<n+1; i++)
    {
        arr[i]=0;
    }
    for(int i=2; i<n+1; i++)
    {  
        if(arr[i]==1)
        {
            continue;
        }
        else if(i*i<=n)
        {
            for(int j=i*i;j<n+1; j+=i)
            {
                arr[j]=1;
            }
        }
        else
            break;
    }
    for(int i=2; i<n+1; i++)
    {
        if(arr[i]==0)
            cout<<i<<" ";
    }
}
void primefactors(int n)
{
    int spf[n+1];
    for(int i=2; i<n+1; i++)
    {
        spf[i]=i;
    }
    for(int i=2; i<n+1; i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i; j<=n; j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }
        }
    }
    while(n!=1)
    {
        cout<<spf[n]<<" ";
        n/=spf[n];
    }
}
int main()
{
    int n;
    cin>>n;
    printprimenoupto(n);
    cout<<endl;
    primefactors(n);
    cout<<endl;
    return 0;
}