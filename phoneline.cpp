#include<bits/stdc++.h>
using namespace std;
class phoneline
{
    int mat[10][10];
    int st,en;
    int cost, min;
    int n;
    int e;
    int visited[10];
    public:
    void input();
    void minimum();
    void display();
};
void phoneline::input()
{
    cout<<"Enter the no of stations: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            mat[i][j]=999;
        }
    }
    cout<<endl<<"Enter the no. of connections: ";
    cin>>e;
    for(int i=0; i<e; i++)
    {
        cout<<"Enter the ends of the connection: ";
        cin>>st>>en;
        cout<<"Enter the cost of the connection: ";
        cin>>cost;
        mat[st-1][en-1]=cost;
        mat[en-1][st-1]=cost;
    }

}
void phoneline::display()
{
    cout<<"The Adj Mat is: "<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void phoneline::minimum()
{
    int p,q;
    int total=0;
    int min=0;
    visited[1]=1;
    for (int count=0; count<(n-1); count++)
    {
        min=999;
        for(int i=0; i<n; i++)
        {
            if(visited[i]==1)
            {
                for(int j=0; j<n; j++)
                {
                    if(visited[j]!=1)
                    {
                        if(min>mat[i][j])
                        {
                            min=mat[i][j];
                            p=i;
                            q=j;
                        }
                    }
                }
            }
        }
        visited[p]=1;
        visited[q]=1;
        total=total+min;
        cout<<"Minimum cost for "<<p+1<<" and "<<q+1<<"is: "<<min<<endl;
    }
    cout<<"Minimum total cost is: "<<total<<endl;
}
int main()
{
    phoneline p;
    p.input();
    p.display();
    p.minimum();
    cout<<endl;
}