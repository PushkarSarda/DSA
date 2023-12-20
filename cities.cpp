#include<bits/stdc++.h>
using namespace std;
struct node
{
    node* next;
    string city_name;
    int time;
};
class adjmatlist
{
    node* head[10];
    string city_names[10];
    node* temp=NULL;
    int n;
    int adj_mat[10][10];
    public:
    void getgraph();
    void adjlist();
    void display_adjmat();
    void dispaly_adjlist();
};
void adjmatlist::getgraph()
{
    cout<<"Enter the number of cities :";
    //int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the name of the city "<<i+1<<": ";
        cin>>city_names[i];
    }
    char ch=' ';
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<"Press y if path exisits b/w city "<<city_names[i]<<" and city "<<city_names[j]<<": ";
            cin>>ch;
            if(ch=='y')
            {
                cout<<"Enter the time required to travel from "<<city_names[i]<<" to "<<city_names[j]<<": ";
                cin>>adj_mat[i][j];
            }
            else
                adj_mat[i][j]=0;
        }
    }
    adjlist();
}
void adjmatlist::adjlist()
{
    node* p;
    for(int i=0; i<n; i++)
    {
        p=new node();
        p->next=NULL;
        p->city_name=city_names[i];
        p->time=adj_mat[i][i];
        head[i]=p;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(adj_mat[i][j]>0)
            {
                p=new node;
                p->city_name=city_names[j];
                p->time=adj_mat[i][j];
                p->next=NULL;
                if(head[i]->next==NULL)
                    head[i]->next=p;
                else
                {
                    temp=head[i];
                    while(temp->next!=NULL)
                        temp=temp->next;
                    temp->next=p;
                }
            }
        }
    }
}
void adjmatlist:: dispaly_adjlist()
{
    cout<<"Adjacency list is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<head[i]->city_name;
        temp=head[i]->next;
        while(temp!=NULL)
        {
            cout<<"->"<<temp->city_name;
            temp=temp->next;
        }
        cout<<endl;
        cout<<"Time required for traversal: "<<head[i]->time;
        temp=head[i]->next;
        while(temp!=NULL)
        {
            cout<<"->"<<temp->time;
            temp=temp->next;
        }
        cout<<endl<<endl;
    }
}
void adjmatlist::display_adjmat()
{
    cout<<"Adjacency Matrix is: "<<endl;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 && j==0)
                cout<<"   \t";
            else if(i==0)
                cout<<"\t"<<city_names[j-1];
            else if(j==0)
                cout<<"\t"<<city_names[i-1];
            else
            {
                cout<<"\t"<<adj_mat[i-1][j-1];
            }
        }
        cout<<endl;
    }
}
int main()
{
    adjmatlist a;
    a.getgraph();
    a.dispaly_adjlist();
    a.display_adjmat();
    cout<<endl;
}
