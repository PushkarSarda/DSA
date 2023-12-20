#include<bits/stdc++.h>
using namespace std;
struct node
{
    node* left;
    node* right;
    string keyword;
    string meaning;
    int ht;
};
class avl
{
    public:
    node* root;
    node* temp;
    avl()
    {
        root=NULL;
        temp=NULL;
    }
    void create(string, string);
    void insert(node*, string, string);
    int height(node*);
    int BF(node*);
    void rotate_right_right(node*);
    void rotate_left_left(node*);
    void rotate_left_right(node*);
    void rotate_right_left(node*);
    void inorder_display(node*);
};
void avl::create(string key, string mean)
{
    insert(root,key,mean);
}
int avl::height(node* temp)
{
    int lht=0,rht=0;
    if(temp->left==NULL)
        lht=0;
    else
        lht=temp->left->ht;
    if(temp->right==NULL)
        rht=0;
    else    
        rht=temp->right->ht;
    if(lht>rht)
        return lht;
    else    
        return rht;
}
int avl::BF(node* temp)
{
    int lht=0,rht=0;
    if(temp->left==NULL)
        lht=0;
    else
        lht=temp->left->ht;
    if(temp->right==NULL)
        rht=0;
    else    
        rht=temp->right->ht;
    return(lht-rht);
}
void avl::rotate_left_left(node* p)
{
    int flag=0;
    if(root==p)
        flag=1;
    node* pl=p->left;
    node* plr=pl->right;
    temp=p;
    p=pl;
    p->right=temp;
    p->right->left=plr;
    p->ht=height(p);
    temp->ht=height(temp);
    if(flag==1)
        root=p;
}
void avl::rotate_right_left(node* p)
{
    rotate_right_right(p->left);
    rotate_left_left(p);
}
void avl::rotate_left_right(node* p)
{
    rotate_left_left(p->right);
    rotate_right_right(p);
}
void avl::rotate_right_right(node* p)
{
    cout<<"HI"<<endl;
    int flag=0;
    if(root==p)
        flag=1;
    node* pr=p->right;
    node* prl=pr->left;
    temp=p;
    p=pr;
    p->left=temp;
    p->left->right=prl;
    p->ht=height(p);
    temp->ht=height(temp);
    if(flag==1)
        root=p;
}
void avl::insert(node* temp, string key, string mean)
{
    if(temp==NULL)
    {
        temp=new node;
        //cout<<"HI"<<endl;
        temp->keyword=key;
        temp->meaning=mean;
        temp->right=NULL;
        temp->left=NULL;
        if(root==NULL)
            root=temp;
        return;
    }
    if(temp->keyword>key)
    {
        cout<<"hi"<<endl;
        insert(temp->left,key,mean);
        if(BF(temp)==2)
        {
            if(temp->left->keyword>key)
                rotate_left_left(temp);
            else
                rotate_right_left(temp);
        }
    }
    else
    {
        insert(temp->right,key,mean);
        if(BF(temp)==-2)
        {
            if(temp->right->keyword<key)
                rotate_right_right(temp);
            else    
                rotate_left_right(temp);
        }
    }
}
void avl::inorder_display(node* root)
{
    if(temp!=NULL)
    {
        inorder_display(root->left);
        cout<<root->keyword<<" ";
        inorder_display(root->right);
    }
}
int main()
{
    string a,b;
    avl obj;
    for(int i=0; i<4; i++)
    {
        cout<<"Enter the key:";
        cin>>a;
        cout<<"Enter the meaning:";
        cin>>b;
        obj.create(a,b);
    }
    cout<<obj.root->keyword<<endl;
    obj.inorder_display(obj.root);
}