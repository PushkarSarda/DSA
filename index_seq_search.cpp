#include<bits/stdc++.h>
using namespace std;
int sequential_index_search(int arr[], int grpsize,int n, int key)
{
    int entries;
    if(n%grpsize==0)
        entries=n/grpsize;
    else
        entries=(n/grpsize)+1;
    cout<<entries;
    int indexarr[entries];
    int inc=0;
    cout<<endl;
    for(int i=0; i<entries; i++)
    {
        indexarr[i]=inc;
        inc+=grpsize;
        cout<<indexarr[i]<<" ";
    }
    cout<<endl;
    int find=0;
    int flag=0;
    for(int i=0; i<entries; i++)
    {
        if(arr[indexarr[i]]>key)
        {
            find=i;
            flag=1;
            break;
        }
        // if(arr[indexarr[i]]<key)
        //     i++;
    }
    
    int i=0;
    if(flag==0)
    {
        i=indexarr[entries-1]+grpsize;
        find=n-1;
    }
    else
        i=indexarr[find]-grpsize;
    cout<<i-grpsize<<endl;
    cout<<find<<endl;
    for(i-=grpsize;i<indexarr[find]; i++)
    {
        if(arr[i]==key)
            return i;
    }
    if(i>=indexarr[find])
        return -1;
}
int main()
{
    int arr[9]={12,15,17,21,28,36,57,81,99};
    cout<<sequential_index_search(arr,3,9,69)<<endl;
    return 0;
}