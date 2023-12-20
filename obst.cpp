#include<bits/stdc++.h>
using namespace std;
class obst
{
    int a[10];
    int r[10][10];
    int n;
    float w[10][10],c[10][10], p[10],q[10];
    public:
    void accept();
    void const_obst();
    void tree(int ,int);
    int kuthmin(int,int);
};
void obst::accept()
{
    cout<<"Enter the no. of entries in tree: ";
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    cout<<"Enter their pass and fail probabilities: ";
    for (int i=1; i<=n; i++)
    {
        cin>>p[i];
        cin>>q[i];
    }
}
void obst::const_obst()
{
    int i,j,k,m;
    for (i=0; i<n; i++)
    {
        w[i][i]=q[i];
        r[i][i]=c[i][i]=0;
        w[i][i+1]=p[i+1]+q[i+1]+q[i];
        r[i][i+1]=i+1;
        c[i][i+1]=w[i][i+1];
    }
    w[n][n]=q[n];
    c[n][n]=r[n][n]=0;
    for(m=2; m<=n; m++)
    {
        for(i=0; i<=n-m; i++)
        {
            j=i+m;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            k=kuthmin(i,j);
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
            r[i][j]=k;
        }
    }
    cout<<"Root node is: "<<a[r[0][n]];
    cout<<"Left child of "<<a[r[0][n]]<<"is :";
    tree(0,r[0][n]-1);
    cout<<"Right child of "<<a[r[0][n]]<<"is : ";
    tree(r[0][n],n);
}
int obst::kuthmin(int i, int j)
{
    int min=999,k,z;
    for(k=r[i][j-1]; k<=r[i+1][j]; k++)
    {
        if(min>c[i][k-1]+c[k][j])
        {
            min=c[i][k-1]+c[k][j];
            z=k;
        }
    }
    return z;
}
void obst::tree(int i,int j)
{
    if(r[i][j]==0)
    {
        cout<<"NULL\n";
        return;
    }
    cout<<a[r[i][j]];
    cout<<"\nleft child is: ";
    tree(i,r[i][j]-1);
    cout<<"\nright child is: ";
    tree(r[i][j],j);
}
int main()
{
    obst o;
    o.accept();
    o.const_obst();
    
}