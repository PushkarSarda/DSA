#include<bits/stdc++.h>
using namespace std;
int getbit(int n, int pos)
{
    int check=(n&(1<<pos));
    if(check>0)
        return 1;
    else
        return 0;
}
int main()
{
    cout<<getbit(5,2);
    return 0;
}