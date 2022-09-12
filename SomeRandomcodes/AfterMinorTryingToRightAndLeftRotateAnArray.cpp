
//THIS PROGRAM WAS DONE AFTER MINOR JUST TO REVISE IF I CAN DO RIGHT SHIFT AND LEFT SHIFT(CIRCULAR)
//BY MYSELF WITHOUT ANY REVISION 


#include<iostream>
using namespace std;
void leftrotateby1(int *p,int length)
{
    int endele=p[0];
    for(int i=0;i<length-1;i++)
    {
        p[i]=p[i+1];
    }
    p[length-1]=endele;
}
void leftrotatebymany(int *arr,int positions,int len)
{
    for(int i=0;i<positions;i++)
    {
        leftrotateby1(arr,len);
    }
}
void rightrotateby1(int *p,int length)
{
    int startele=p[length-1];
    for(int j=length-1;j>=1;j--)
    {
        p[j]=p[j-1];
    }
    p[0]=startele;
}
void rightrotatebymany(int *arr,int positions,int len)
{
    for(int i=0;i<positions;i++)
    {
        rightrotateby1(arr,len);
    }
}
int main(){
    int a[5]={20,45,69,70,65};
    leftrotatebymany(a,3,5);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
     return 0;
}