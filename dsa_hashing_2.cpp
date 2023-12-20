#include<bits/stdc++.h>
using namespace std;
#define size 10
struct node
{
    string key;
    string meaning;
    int pos;
};
class hash_table
{
    public:
    node arr[size];
    int counter=0;
    hash_table()
    {
        for (int i=0 ;i<size; i++)
        {
            arr[i].pos=-1;
        }
    }
    void find(string);
    void insert();
    void del(string);
    void display();
};
void hash_table::insert()
{
    if(counter==10)
    {
        cout<<"Hash Table is full!!"<<endl;
        return;
    }
    else
    {
        string temp;
        cout<<"Enter the word to be added: ";
        cin>>temp;
        int ascii_sum=0;
        for (int i=0; i<temp.length(); i++)
            ascii_sum+=int(temp[i]);
        // considering hash function here as: (sum of ascii values of the word)%size
        int index;
        index=ascii_sum%size;
        for (int i=0; i<size; i++)
        {
            cout<<index<<" ";
            if(arr[index].pos==-1)
            {
                arr[index].key=temp;
                arr[index].pos=0;
                cout<<endl<<"Enter the meaning of the word: ";
                cin>>arr[index].meaning;
                break;
            }
            else
                index=(index+1)%size;
        }
        counter++;
    }
}
void hash_table::find(string find_key)
{
    int ascii_sum=0;
        for (int i=0; i<find_key.length(); i++)
            ascii_sum+=int(find_key[i]);
    int index=ascii_sum%size;
    int flag=0;
    for(int i=0; i<size; i++)
    {
        if(arr[index].key==find_key)
        {
            cout<<"Word: "<<arr[index].key<<"\tMeaning: "<<arr[index].meaning<<endl;
            flag=1;
            return;
        }
        else
        {
            index=(index+1)%size;
        }
    }
    if(flag==0)
    {
        cout<<"Word Not Found!"<<endl;
        return;
    }
}
void hash_table::del(string del_key)
{
    int ascii_sum=0;
        for (int i=0; i<del_key.length(); i++)
            ascii_sum+=int(del_key[i]);
    int index=ascii_sum%size;
    int flag=0;
    for(int i=0; i<size; i++)
    {
        if(arr[index].key==del_key)
        {
            cout<<"Word: "<<arr[index].key<<"\tMeaning: "<<arr[index].meaning<<"\t Is DELETED!"<<endl;
            arr[index].key="\0";
            arr[index].meaning="\0";
            arr[index].pos=-1;
            cout<<"Trying to find the word now...."<<endl;
            find(del_key);
            flag=1;
            return;
        }
        else
        {
            index=(index+1)%size;
        }
    }
    if(flag==0)
    {
        cout<<"Word doesnt exist!"<<endl;
        return;
    }
}
void hash_table::display()
{
    for (int i=0; i<size; i++)
    {
        cout<<arr[i].key<<" ";
    }
}
int main()
{
    hash_table h;
    for (int i=0; i<size; i++)
    {
        h.insert();
    }
    h.display();
    char ch='y';
    while(ch=='y')
    {
        cout<<"enter the word to be searched: ";
        string temp;
        cin>>temp;
        h.find(temp);
        cout<<endl<<"Do you wish to continue searching?: ";
        cin>>ch;
    }
    ch='y';
    while(ch=='y')
    {
        cout<<"enter the word to be deleted: ";
        string temp;
        cin>>temp;
        h.del(temp);
        cout<<endl<<"Do you wish to continue deleting?: ";
        cin>>ch;
    }
}