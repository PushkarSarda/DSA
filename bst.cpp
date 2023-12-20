#include<bits/stdc++.h>
using namespace std;
struct node
{
    node* left;
    node* right;
    node* root=NULL;
    string meaning;
    char key;
    node* create();
    void insert();
};
node* node::create()
{
    node* temp=root;
    node* t1=new node;
    cout<<"Enter the key:";
    cin>>t1->key;
    cout<<"Enter the meaning:";
    cin>>t1->meaning;
    t1->left=NULL;
    t1->right=NULL;
    return t1;
}
void node::insert()
{
    node* temp=root;
    node* t1=create();
    if(root==NULL)
    {
        root=t1;
    }
    else
    {
        int flag=0;
        while(flag==0)
        {
            if(t1->key<temp->key)
            {
                if(temp->left==NULL)
                {
                    temp->left=t1;
                    flag=1;
                }
                else
                    temp=temp->left;
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=t1;
                    flag=1;
                }
                else
                    temp=temp->right;
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the no of words you need to add:";
    cin>>n;
    node obj;
    for(int i=0; i<n; i++)
    {
        obj.insert();
    }
    // node* t2=obj.create();
    // cout<<t2->key<<":"<<t2->meaning<<endl;
    // cout<<"BYE!"<<endl;
}