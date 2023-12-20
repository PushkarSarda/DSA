#include<bits/stdc++.h>
using namespace std;
struct node
{
    node *head=NULL, *down,*next, *subhead;
    int flag;
    char data;
    void accept(int indicator);
    void display2(node *pt );
    void display3(node *pointer);
    void display();
    
};
node * x;//used to store the diversion node
vector <node*> diversions;//used to handle diversions 
void node::accept(int indicator)
{  
    node *p;
    if(indicator==0)//to insert a data node
    {
        if(head==NULL)
        {
            p=new node;
            cout<<"Enter info:";
            cin>>p->data;
            p->flag=0;
            p->next=NULL;
            p->down=NULL;
            head=p;
            x=head;
        }
        else
        {
            p=new node;
            p->flag=0;
            cout<<"Enter data:";
            cin>>p->data;
            if(x->flag==1)
            {
                x->down=p;
                p->next=NULL;
                p->down=NULL;
            }
            else if(x->flag==2)
            {
                x->next=p;
                p->next=NULL;
                p->down=NULL;
            }
            else
            {
                x->next=p;
                p->next=NULL;
                p->down=NULL;
            }
            x=p;
        }
    }
    else if(indicator==1)//to insert a diversion node
    {
        if(head==NULL)
        {
            p=new node;
            p->flag=1;
            p->data='\0';
            p->down=NULL;
            head=p;
            x=head;
            diversions.push_back(p);
        }
        else
        {
            p=new node;
            p->flag=1;
            p->data='\0';

            if(x->flag==1)
            {
                x->down=p;
                p->next=NULL;
                p->down=NULL;
            }
            else if(x->flag==2)
            {
                x->next=p;
                p->next=NULL;
                p->down=NULL;
            }
            else
            {
                x->next=p;
                p->next=NULL;
                p->down=NULL;
            }
            x=p;
            diversions.push_back(p);
        }
    }
    else//to backtrack to the diversion node
    {
        if(diversions.empty())
        {
            cout<<"There is no previous node"<<endl;
            return;
        }
        x=diversions[(diversions.size())-1];
        x->flag=2;
        diversions.pop_back();
    }
}
void node:: display()//initial approach
{
    node* temp;
    temp=head;
    while(temp->next!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
    node *temp2=head;
    while(temp2->flag!=2)
    {
        temp2=temp2->next;
    }
    temp2=temp2->down;
    cout<<"HI\n";
    while(temp2->next!=NULL)
    {
        cout<<temp2->data<<"->";
        temp2=temp2->next;
    }
    cout<<temp2->data<<endl;
}
node obj;
void node:: display2(node* temp)
{
    if(temp->next==NULL)
    {
        cout<<temp->data;
        return;
    }
    else if(temp->flag==2)
    {
        node* temp2=temp;
        temp=temp->down;
        cout<<"-->";
        obj.display3(temp);
        temp=temp2->next;
    }
    else 
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    display2(temp);
}
void node::display3(node* temp2)
{
    node* temp3=temp2;
    while(temp3->next!=NULL)
    {
        if(temp3->flag==2)
        {
            node* temp4=temp3->down;
            cout<<"-->";
            display3(temp4);
        }
            
        cout<<temp3->data<<"->";
        temp3=temp3->next;
    }
    cout<<temp3->data<<"   ";
    //temp3=temp3->next;
    return;
}
int main()
{
    int n;
    char ch='y';
    //node obj;
    while(ch=='y'||ch=='Y')
    {
        cout<<"Enter 1 to create diversion or 0 to continue and 2 to return back from a branch";
        cin>>n;
        obj.accept(n);
        cout<<"Do you want to continue?";
        cin>>ch;
    }
   //cout<<endl<<obj.head<<endl;
    obj.display2(obj.head);
    //obj.display();
    return 0;
}
