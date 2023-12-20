#include<bits/stdc++.h>
using namespace std;
int gcd(int n1, int n2)
{
    int rem=n1%n2;
    while(n2%rem!=0)
    {
        int temp=n2;
        n2=rem;
        rem=temp%rem;
    }
    return rem;
}
int main()
{
    cout<<"Enter no.'s to find gcd: ";
    int n1, n2;
    cin>>n1>>n2;
    int gcdans=gcd(max(n1,n2),min(n1,n2));
    cout<<"GCD= "<<gcdans<<endl;
    return 0;
}