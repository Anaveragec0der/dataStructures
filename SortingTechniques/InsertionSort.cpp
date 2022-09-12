#include<iostream>
using namespace std;
void InsertionSort(int *a,int n)
{
    for(int i=1;i<n;i++)// i STARTS FROM 1 AS THE FIRST ELEMENT IS ALREADY CONSIDERED TO BE IN SORTED ORDER
    //ALSO IT SIGNIFIES NUMBER OF PASSES
    {
        int x=a[i];
        int j=i-1;
        while(j>=0 && a[j]>x)//J>=0 FOR MAKING SURE J STAYS TILL VALID INDEXES 
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}
int main(){
 int A[]={10,24,1,4,69,25,42,55,100,2};
    InsertionSort(A,10);
    for(int i=0;i<10;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
     return 0;
}