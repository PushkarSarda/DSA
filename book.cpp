#include<bits/stdc++.h>
using namespace std;
struct node
{
    char name[20];
    node* down;
    node* next;
    int flag;
};
class GLL
{
    char ch[20];
    node* head=NULL;
    node* temp=NULL;
    node* t1=NULL;
    node* t2=NULL;
    public:
    node * create();
    void insert_book();
    void insert_chap();
    void insert_sec();
    void insert_subsec();
    void display_book();
};
node* GLL :: create()
{
    node* p= new node;
    p->down=NULL;
    p->next=NULL;
    p->flag=0;
    cout<<"Enter the name:";
    cin>>p->name;
    return p;
}
void GLL::insert_book()
{
    if(head==NULL)//book doesnt exist
    {
        t1=create();
        head=t1;
    }
    else
    {
        cout<<"Book already exists!"<<endl;
        return;
    }
}
void GLL::insert_chap()
{
    if(head==NULL)
    {
        cout<<"Book doesnt exist!!"<<endl;
        return;
    }
    else
    {
        cout<<"enter the no. of chapters to be added:";
        int n;
        cin>>n;
        for (int i=0; i<n; i++)
        {
            if(head->flag==0)//no chapter is added
            {
                t1=create();
                head->down=t1;
                head->flag=1;
            }
            else
            {
                t1=create();
                temp=head->down;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=t1;
            }
        }
    }
}
void GLL::insert_sec()
{
    if(head==NULL)
    {
        cout<<"Book Doesnt Exist!"<<endl;
        return;
    }
    else
    {
        if(head->flag==0)
        {
            cout<<"No chapters exist!"<<endl;
            return;
        }
        else
        {
            cout<<"Enter the name of the chapter to which sections need to be added";
            string key;
            cin>>key;
            cout<<"Enter the number of sections to be added: ";
            int n;
            cin>>n;
            temp=head->down;
            int flag2=0;
            while(temp!=NULL)
            {
                if(temp->name==key)
                {
                    flag2=1;
                    break;
                }
                temp=temp->next;
            }
            if(flag2==0)
            {
                cout<<"Chapter doesnt exist!!"<<endl;
                return;
            }
            for (int i=0; i<n; i++)
            {
                if(temp->flag==0)//no sections present in the given chapter
                {
                    t1=create();
                    temp->down=t1;
                    temp->flag=1;
                }
                else
                {
                    t2=temp->down;
                    t1=create();
                    while(t2->next!=NULL)
                    {
                        t2=t2->next;
                    }
                    t2->next=t1;
                }
            }
        }
    }
}
void GLL::insert_subsec()
{
    if(head==NULL)
    {
        cout<<"Book doesnt exist!"<<endl;
        return;
    }
    else
    {
        if(head->flag==0)
        {
            cout<<"Chapters dont exist!!"<<endl;
            return;
        }
        else
        {
            cout<<"Enter the name of chapter in which subsections need to be added:";
            string key;
            cin>>key;
            temp=head->down;
            int flag2=0;
            while(temp->next!=NULL)
            {
                if(temp->name==key)
                {
                    flag2=1;
                    break;
                }
                temp=temp->next;
            }
            if (flag2==0)
            {
                cout<<"The given chapter doesnt exist!!"<<endl;
                return;
            }
            if(temp->flag==0)//sections are not added
            {
                cout<<"Sections dont exist!!"<<endl;
                return;
            }
            else
            {
                temp=temp->down;
                cout<<"Enter the name of the section to which you want to add subsections:";
                string key2;
                cin>>key2;
                int flag3=0;
                while(temp->next!=NULL)
                {
                    if(temp->name==key2)
                    {
                        flag3=1;
                        break;
                    }
                    temp=temp->next;
                }
                if(flag3==0)
                {
                    cout<<"Section mentioned doesnt exist!!"<<endl;
                    return;
                }
                cout<<"Enter the number of subsections to be added:";
                int n;
                cin>>n;
                for(int i=0; i<n; i++)
                {
                    if(temp->flag==0)//subsections donot exist
                    {
                        t1=create();
                        temp->down=t1;
                        temp->flag=1;
                    }
                    else
                    {
                        t1=create();
                        t2=temp->down;
                        while(t2->next!=NULL)
                        {
                            t2=t2->next;
                        }
                        t2->next=t1;
                    }
                }
            }
        }
    }
}
void GLL::display_book()
{
    if(head==NULL)
    {
        cout<<"Book Doesnt exist!!"<<endl;
        return;
    }
    else
    {
        temp=head;
        cout<<"Name of Book: "<<temp->name<<endl;
        if(temp->flag==1)
        {
            temp=temp->down;
            while(temp!=NULL)
            {
                cout<<"\tName of Chapter: "<<temp->name<<endl;
                if(temp->flag==1)
                {
                    t1=temp->down;
                    while(t1!=NULL)
                    {
                        cout<<"\t\tName of Section: "<<t1->name<<endl;
                        if(t1->flag==1)
                        {
                            t2=t1->down;
                            while(t2!=NULL)
                            {
                                cout<<"\t\t\tName of Subsection: "<<t2->name<<endl;
                                t2=t2->next;
                            }
                        }
                        t1=t1->next;
                    }  
                }
                temp=temp->next;
            }
        }
    }
}
int main()
{
    GLL g;
    while(true)
    {
        cout<<"Enter your choice:"<<endl;
        int opt;
        cout<<"1 - Insert Book \n 2 - Insert Chapter \n 3 - Insert Section \n 4 - Insert Subsection \n 5 - Display Book";
        cin>>opt;
        switch(opt)
        {
            case 1:
                g.insert_book();
                break;
            case 2:
                g.insert_chap();
                break;
            case 3:
                g.insert_sec();
                break;
            case 4:
                g.insert_subsec();
                break;
            case 5:
                g.display_book();
                break;
        }
        // cout<<"To continue press y else n";
        // int ch;
        // cin>>ch;
        // if(ch=='n')
        //     break;
    }
}