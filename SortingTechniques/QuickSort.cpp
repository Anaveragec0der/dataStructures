#include<iostream>
using namespace std;
void Swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
int Partitioning(int *A,int l,int h)
{
    int pivot=A[l];
    int j=h;
    int i=l;
    do
    {
        do
        {
            i++;
        } while (A[i]<=pivot);
        do
        {
            j--;
        } while (A[j]>pivot);
        if(i<j)
        {
            Swap(A[i],A[j]);
        }
        
    } while (i<j);
    Swap(A[l],A[j]);
    return j;
}
void QuickSort(int *A,int l,int h)
{
    int j;
    if(l<h)
    {
        j=Partitioning(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}
int main(){
int A[]={10,24,1,4,69,25,42,55,100,2,INT32_MAX};
    QuickSort(A,0,10);
    for(int i=0;i<10;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;    
     return 0;
}