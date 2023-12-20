#include<bits/stdc++.h>
#include<cstring>
#include<string.h>
using namespace std;
class student
{
    typedef struct stud{
        int roll;
        char name[20];
    };
    stud rec;
    public:
    void create();
    void display();
    int search();
    void delet();
};
void student::create()
{
    ofstream fout;
    char ch='y';
    fout.open("student_data.dat",ios::out|ios::binary);
    while(ch=='y')
    {
        cout<<"Enter the roll no: ";
        cin>>rec.roll;
        cout<<"Enter the name: ";
        cin>>rec.name;
        fout.write((char *)&rec,sizeof(stud))<<flush;
        cout<<"do you want to continue?: ";
        cin>>ch;
    }
    fout.close();
}
void student::display()
{
    ifstream fin;
    fin.open("student_data.dat",ios::in|ios::binary);
    fin.seekg(0,ios::beg);
    while(fin.read((char *)&rec, sizeof(stud)))
    {
        if(rec.roll!=-1)
        {
            cout<<rec.roll<<"\t "<<rec.name<<endl;
        }
    }
    fin.close();
}
int student::search()
{
    fstream f;
    f.open("student_data.dat",ios::in|ios::out|ios::binary);
    cout<<"Enter the roll no:";
    int x;
    cin>>x;
    int i=0;
    while(f.read((char *)&rec,sizeof(stud)))
    {
        if(rec.roll==x)
        {
            cout<<"found!!"<<endl;
            return i;
        }
        i++;
    }
    f.close();
    return 0;
}
void student::delet()
{
    int pos;
    pos=search();
    fstream f;
    f.open("student_data.dat",ios::in|ios::out|ios::binary);
    f.seekg(0,ios::beg);
    if(pos==0)
    {
        cout<<"record not present"<<endl;
        return;
    }
    else{
        int offset=pos*sizeof(stud);
        f.seekp(offset);
        rec.roll=-1;
        strcpy(rec.name,"\0");
        f.write((char *)&rec, sizeof(stud))<<flush;
        f.seekg(0);
        f.close();
        cout<<"Record deleted!"<<endl;
    }
}
int main()
{
    student obj;
    obj.create();
    obj.display();
    obj.search();
    obj.delet();
    obj.display();
}