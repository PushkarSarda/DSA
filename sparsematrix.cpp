#include<bits/stdc++.h>
using namespace std;
void sparseaddition()
{
    cout<<"Enter no of entries in 1st sparse matrix:";
    int t1;
    cin>>t1;
    int sparr1[t1+1][3];
    cout<<"Enter 1st Sparse matrix:"<<endl;
    for(int i=0; i<t1+1; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>sparr1[i][j];
        }
    }
    cout<<"Enter no of entries in 2nd sparse matrix:";
    int t2;
    cin>>t2;
    int sparr2[t2+1][3];
    cout<<"Enter 1st Sparse matrix:"<<endl;
    for(int i=0; i<t2+1; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin>>sparr2[i][j];
        }
    }
    if(sparr1[0][0]==sparr2[0][0] && sparr1[0][1]==sparr2[0][1])
    {
        int m=sparr1[0][2]; 
        int n=sparr2[0][2];
        int i=1,j=1;
        int anssparr[20][2]={-1};
        int k=1;
        anssparr[0][0]=sparr1[0][0];
        anssparr[0][1]=sparr1[0][1];
        while(i<=m && j<=n)
        {
            if(sparr1[i][0]==sparr2[j][0])
            {
                cout<<"hi1 ";
                if(sparr1[i][1]==sparr2[j][1])
                {
                    cout<<"HI ";
                    anssparr[k][0]=sparr1[i][0];
                    anssparr[k][1]=sparr1[i][1];
                    anssparr[k][2]=sparr1[i][2]+sparr2[j][2];
                    cout<<anssparr[k][2]<<" ";
                    cout<<endl;
                    i++;
                    j++;
                    k++;
                }
                else if(sparr1[i][1]>sparr2[j][1])
                {
                    anssparr[k][0]=sparr2[j][0];
                    anssparr[k][1]=sparr2[j][1];
                    anssparr[k][2]=sparr2[j][2];
                    j++;
                    k++;
                }
                else
                {
                    anssparr[k][0]=sparr1[i][0];
                    anssparr[k][1]=sparr1[i][1];
                    anssparr[k][2]=sparr1[i][2];
                    i++;
                    k++;
                }
            }
            else if(sparr1[i][0]>sparr2[j][0])
            {
                cout<<"hi2 ";
                anssparr[k][0]=sparr2[j][0];
                anssparr[k][1]=sparr2[j][1];
                anssparr[k][2]=sparr2[j][2];
                j++;
                k++;
            }
            else
            {
                cout<<"hi3 ";
                anssparr[k][0]=sparr1[i][0];
                anssparr[k][1]=sparr1[i][1];
                anssparr[k][2]=sparr1[i][2];
                i++;
                k++;
            }
        }
        while(i<=m)
        {
            anssparr[k][0]=sparr1[i][0];
            anssparr[k][1]=sparr1[i][1];
            anssparr[k][2]=sparr1[i][2];
            i++;
            k++;
        }
         while(j<=n)
        {
            anssparr[k][0]=sparr2[j][0];
            anssparr[k][1]=sparr2[j][1];
            anssparr[k][2]=sparr2[j][2];
            j++;
            k++;
        }
        cout<<endl<<endl;
        for(int x=0; x<k; x++)
        {
            cout<<anssparr[x][0]<<" "<<anssparr[x][1]<<" "<<anssparr[x][2]<<endl;
        }
    }
    else
        cout<<"Sparse matrices are not of same dimensions!! cant add";
}
int main()
{
    int row,col;
    cout<<"Enter the dimensions of matrix: ";
    cin>>row>>col;
    int arr[row][col];
    int counter=0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin>>arr[i][j];
            if (arr[i][j]>0)
                counter++;
        }
    }
    int sparr[counter+1][3];
    sparr[0][0]=row;
    sparr[0][1]=col;
    sparr[0][2]=counter;
    int k=1;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(arr[i][j]!=0)
            {
                sparr[k][0]=i;
                sparr[k][1]=j;
                sparr[k][2]=arr[i][j];
                k++;
            }
        }
    }
    for(int i=0; i<counter; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<sparr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    sparseaddition();
    cout<<endl;
}
