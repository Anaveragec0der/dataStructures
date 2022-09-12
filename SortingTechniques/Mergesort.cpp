#include<iostream>
using namespace std;
void Merge(int *A,int l,int mid,int h)
{
    int i,j,k;
    i=l;
    k=l;
    j=mid+1;
    int temp[h+1];
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
        {
            temp[k++]=A[i++];
        }
        else
        {
            temp[k++]=A[j++];
        }
    }
    for(;i<=mid;i++)
    {
        temp[k++]=A[i];
    }
    for(;j<=h;j++)
    {
        temp[k++]=A[j];
    }
    for(i=l;i<=h;i++)//COPYING THE ELEMENTS BACK FROMM ARRAY TEMP TO ARRAY A
    {
        A[i]=temp[i];
    }
}
void MergeSort(int *A,int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);       
    }
}
int main(){
    int  A[]={8,3,9,7,4,9,2,6,5};
    MergeSort(A,0,8);
    for(int  i=0;i<9;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
     return 0;
}