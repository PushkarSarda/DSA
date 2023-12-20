#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > ans;
void permute(vector <int> &arr, int index)
{
    if(index==arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for(int i=index; i<arr.size(); i++)
    {
        swap(arr[i], arr[index]);
        permute(arr,index+1);
        swap(arr[i],arr[index]);
    }
}
void permute2(vector<int> & arr, int index)
{
    if(index==arr.size())
    {
        ans.push_back(arr);
        return;
    }
    for (int i=index;i<arr.size(); i++)
    {
        if(i!=index && arr[i]== arr[index])
            continue;
        swap(arr[i], arr[index]);
        permute(arr, index+1);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &i: arr)
    {
        cin>>i;
    }
    // permute(arr,0);
    // cout<<endl;
    // for (auto &i:ans)
    // {
    //     for(auto j:i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    sort(arr.begin(), arr.end());
    permute2(arr, 0);
     for (auto &i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    sort(arr.begin(),arr.end());
    vector< vector<int> > ans2;
    cout<<"Built in:"<<endl;
    do
    {
        ans2.push_back(arr);
    }while(next_permutation(arr.begin(),arr.end()));
     cout<<endl;
    for (auto &i:ans2)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}