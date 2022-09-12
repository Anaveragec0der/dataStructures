#include<iostream>
using namespace std;

int main()
{
    int A[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12,}};

    int *p[3];//array of integer created in stack
    p[0]=new int[4];//these are created in heap 
    p[1]=new int[4];
    p[2]=new int[4];

    //now creating the array of integer in the heap
    int **q;
    q=new int *[3];//array of pointer of type integer created in heap

    q[0]=new int[4];
    q[1]=new int[4];
    q[2]=new int[4];
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<4;j++)
        {
            cout<<q[i][j];
        }
        cout<<endl;
    }



     return 0;
}