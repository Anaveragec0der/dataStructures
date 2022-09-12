#include<iostream>
using namespace std;
void adding(int a[3][3],int m,int n)
{
    int *H=new int [10]{0};
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int index1=a[i][0];
            int index2=a[i][1];
            while(index1<index2)
            {
                H[index1]=H[index1]+a[i][2];
                index1++;
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        cout<<H[i]/3<<" ";
    }
    cout<<endl;
}
int main(){
    int ma[3][3]={1,5,3,4,8,7,6,9,1};
    adding(ma,3,3);

     return 0;
}