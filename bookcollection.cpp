#include<bits/stdc++.h>
using namespace std;
struct node
{
    node* root=NULL;
    node* down, *next;
    int flag;
    string name;
    node* create();
    void insert_book();
    void insert_chapter();
    void insert_section();
    void insert_subsection();
    void display();
};
node* node::create()
{
    node* t1=new node();
    cout<<"Enter the name:";
    cin>>t1->name;
    t1->flag=0;
    t1->down=NULL;
    t1->next=NULL;
    return t1;
}
void node::insert_book()
{
    node* temp=root;
    node* b1=create();
    if(root==NULL)
    {
        node* prim=new node;
        prim->name="Book Collection";
        prim->flag=1;
        prim->down=b1;
        cout<<"Book added!"<<endl;
        prim->next=NULL;
    }
    else
    {
        temp=root->down;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=b1;
        cout<<"book is added!\n";
        return;
    }
}
void node::insert_chapter()
{   
    node* temp=root;
    if(root==NULL)
    {
        cout<<"No books present!"<<endl;
    }
    else
    {
        char ch='n';
        cout<<"Please enter y to choose the book listed";
        temp=root->down;
        node* c1=create();
        while(temp!=NULL)
        {
            //temp=temp->next;
            cout<<"Do you want to choose "<<temp->name<<"? : ";
            cin>>ch;
            if(ch=='y')
                break;
            temp=temp->next;
        }
        if(temp->flag==0)//no initial chapters are present in the book
        {
            temp->flag=1;
            temp->down=c1;
            cout<<"Chapter added!"<<endl;
        }
        else if(temp->flag==1)
        {
            temp=temp->down;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=c1;
            cout<<"Chapter added!"<<endl;
        }
        else
        {
            cout<<"You didnt choose a book!"<<endl;
            return;
        }
    }
}
void node::insert_section()
{
    node* temp=root;
    if(root==NULL)
    {
        cout<<"No books present!"<<endl;
    }
    else
    {
        char ch='n';
        cout<<"Please enter y to choose the book listed"<<endl;
        temp=root->down;
        node* s1=create();
        while(temp!=NULL)
        {
            //temp=temp->next;
            cout<<"Do you want to choose "<<temp->name<<"? : ";
            cin>>ch;
            if(ch=='y')
                break;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            cout<<"You didnt choose a book!"<<endl;
            return;
        }
        if(temp->flag==0)
        {
            cout<<"No chapters are present!"<<endl;
            return;
        }
        else
        {
            temp=temp->down;
            cout<<"Please enter y to choose the chapter listed"<<endl;
            while(temp!=NULL)
            {
                cout<<"Do you want to choose "<<temp->name<<"? : ";
                cin>>ch;
                if(ch=='y')
                    break;
                temp=temp->next;
            }
            if(temp==NULL)
            {
                cout<<"You didnt choose any chapter!"<<endl;
                return;
            }
            if(temp->flag==0)//no precreated sections are present
            {
                temp->flag=1;
                temp->down=s1;
            }
            else
            {
                temp=temp->down;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=s1;
            }
            cout<<"Section added!"<<endl;
        }
    }
}
void node::insert_subsection()
{
    node* temp=root;
    if(root==NULL)
    {
        cout<<"No books present!"<<endl;
    }
    else
    {
        char ch='n';
        cout<<"Please enter y to choose the book listed"<<endl;
        temp=root->down;
        node* sub1=create();
        while(temp!=NULL)
        {
            //temp=temp->next;
            cout<<"Do you want to choose "<<temp->name<<"? : ";
            cin>>ch;
            if(ch=='y')
                break;
            temp=temp->next;
        }
        if(temp==NULL)
        {
            cout<<"You didnt choose a book!"<<endl;
            return;
        }
        if(temp->flag==0)
        {
            cout<<"No chapters are present!"<<endl;
            return;
        }
        else
        {
            temp=temp->down;
            cout<<"Please enter y to choose the chapter listed"<<endl;
            while(temp!=NULL)
            {
                cout<<"Do you want to choose "<<temp->name<<"? : ";
                cin>>ch;
                if(ch=='y')
                    break;
                temp=temp->next;
            }
            if(temp==NULL)
            {
                cout<<"You didnt choose any chapter!"<<endl;
                return;
            }
            if(temp->flag==0)//no precreated sections are present
            {
                cout<<"No section is present!"<<endl;
                return;
            }
            else
            {
                cout<<"Please enter y to choose the sections listed"<<endl;
                temp=temp->down;
                while(temp!=NULL)
                {
                    cout<<"Do you want to choose "<<temp->name<<"? : ";
                    cin>>ch;
                    if(ch=='y')
                        break;
                    temp=temp->next;
                }
                if(temp==NULL)
                {
                    cout<<"You didnt choose any section!"<<endl;
                    return;
                }
                if(temp->flag==0)//nosubsections are present
                {
                    temp->flag=1;
                    temp->down=sub1;
                }
                else
                {
                    temp=temp->down;
                    while(temp->next!=NULL)
                    {
                        temp=temp->next;
                    }
                    temp->next=sub1;
                }
                    cout<<"Sub-section added!"<<endl;

            }
        }
    }
}
int main()
{
    char ch='y';
    node obj;
    while(ch=='y'||'Y')
    {
        cout<<"Enter option to perform any operation:"<<endl;
        cout<<"1- To add Book\n"<<"2- To add Chapter\n"<<"3- To add Section\n"<<"4- To add Sub-section\n";
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        switch(choice)
        {
            int n;
            case 1:
            cout<<"Enter how many books you want to add: ";
            //int n;
            cin>>n;
            for(int i=0; i<n; i++)
                obj.insert_book();
            break;

            case 2:
            cout<<"Enter how many chapters you want to add: ";
            //int n;
            cin>>n;
            for(int i=0; i<n; i++)
                obj.insert_chapter();
            break;

            case 3:
            cout<<"Enter how many books you want to add: ";
            //int n;
            cin>>n;
            for(int i=0; i<n; i++)
                obj.insert_section();
            break;

            case 4:
            cout<<"Enter how many books you want to add: ";
            //int n;
            cin>>n;
            for(int i=0; i<n; i++)
                obj.insert_subsection();
            break;
        }
        cout<<"Do you want to conitnue? : ";
        cin>>choice;
    }
    cout<<"Thankyou"<<endl;

}