#include<bits/stdc++.h>
using namespace std;
struct node
{
    node* left;
    node* right;
    int data;
};
node* root;
node* temp;

class bst
{
    public:
    int count=0;
    bst()
    {
        root=NULL;
        count=0;
    }
    void create();
    void insert(node* root, node* temp);
    void display_inorder(node* root);
    void display_preorder(node* root);
    void display_postorder(node* root);
    void search(node* root, int key);
    int height(node* root);
    void mirror(node* root);
    void min(node*);
};
void bst::create()
{
    node* p=new node;
    p->left=NULL;
    p->right=NULL;
    cout<<"Enter the value of node: ";
    cin>>p->data;
    if(root==NULL)
    {
        root=p;
    }
    else
    {
        insert(root,p);
    }
    char ch;
    cout<<"Do you wish to insert more nodes?: ";
    count++;
    cin>>ch;
    if(ch=='y'||ch=='Y')
        create();
    cout<<"Total number of nodes created are: "<<count<<endl;
}
void bst:: insert(node* root, node* temp)
{
    if(temp->data>root->data)
    {
        if(root->right==NULL)
        {
            root->right=temp;
        }
        else
        {
            insert(root->right,temp);
        }
    }
    else
    {
        if(root->left==NULL)
        {
            root->left=temp;
        }
        else
            insert(root->left,temp);
    }
}
void bst::display_inorder(node* root)
{
    if(root!=NULL)
    {
        display_inorder(root->left);
        cout<<root->data<<" ";
        display_inorder(root->right);
    }
    cout<<endl;
}
void bst::display_preorder(node* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        display_preorder(root->left);
        display_preorder(root->right);
    }
    cout<<endl;
}
void bst::display_postorder(node* root)
{
    if(root!=NULL)
    {
        display_postorder(root->left);
        display_postorder(root->right);
        cout<<root->data<<" ";
    }
    cout<<endl;
}
void bst::search(node* root, int key)
{
    if (root==NULL)
    {
        cout<<"Element not found!!"<<endl;
        return;
    }
    else if (root->data==key)
    {
        cout<<"Element found!!"<<endl;
        return;
    }
    else if(root->data>key)
    {
        search(root->left,key);
    }
    else    
        search(root->right,key);
}
int bst::height(node* root)
{
    int height_right=0, height_left=0;
    //int ans=0;
    if(root==NULL)
        return 0;
    else if(root->right==NULL && root->left==NULL)
        return 1;
    height_right=1+height(root->right);
    height_left=1+height(root->left);
    if(height_right>height_left)
    {
        return (height_right);
    }
    else
        return (height_left);
}
void bst::min(node* root)
{
    temp=root;
    while(temp->left!=NULL)
        temp=temp->left;
    cout<<temp->data<<endl;
}
void bst::mirror(node* root)
{
    temp=root;
    if(root!=NULL)
    {
        mirror(root->left);
        mirror(root->right);
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
}
int main()
{
    bst b;
    int ch;
    while (true)
    {
        cout<<" 1 - To add nodes\n 2 - To find the no. of nodes in longest path\n 3- To find the minimum element of the tree\n 4 - To mirror the tree\n 5 - To search the element in tree\n 6 - Preorder Traversal\n 7 - Inorder Traversal\n 8 - Postorder Traversal"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                b.create();
                break;
            case 2:
                cout<<"Number of Nodes in the longest path= "<<b.height(root)<<endl;
                break;
            case 3:
                cout<<"The Min element of the tree is: ";
                b.min(root);
                cout<<endl;
                break;
            case 4:
                b.mirror(root);
                cout<<"The mirrored tree is: "<<endl;
                b.display_inorder(root);
                break;
            case 5:
                cout<<"enter the element to be searched";
                int x;
                cin>>x;
                b.search(root,x);
                cout<<endl;
                break;
            case 6:
                cout<<"View the preorder traversal: "<<endl;
                b.display_preorder(root);
                break;
            case 7:
                cout<<"View the inorder traversal: "<<endl;
                b.display_inorder(root);
                break;
            case 8:
                cout<<"View the postorder traversal: "<<endl;
                b.display_postorder(root);
                break;
        }
    }
}