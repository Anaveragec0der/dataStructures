#include<iostream>
using namespace std;
int FindMin(int *A,int len)
{
    int min=A[0];
    for(int i=0;i<len;i++)
    {
        if(min>A[i])
        {
            min=A[i];
        }
    }
    return min;
}
int FindMax(int *A,int len)
{
    int max=A[0];
    for(int i=0;i<len;i++)
    {
        if(A[i]>max)
        {
            max=A[i];
        }
    }
    return max;
}
void Count_Sort(int *A,int size)
{
    int max=FindMax(A,size);
    int min=FindMin(A,size);
    int H[max]{0};//CONSIDER MAX ELEMENT IS 15 BUT IF WE DON'T ADD 1 TO IT TOTAL NUMBER OF INDEXS WILL BE TILL 14
    //ONLY  
    //AN UPDATE ON THIS QUERY THE CODE WILL STILL WORK IF WE DON'T USE MAX+1 BECAUSE WHEN WE USE
    //NEW KEYWORD THE ARRAY INDEX OUT OF BOUND IS NOT HANDELED BY C AND C++ COMPILERS
    int k=0;
    for(int i=0;i<size;i++)
    {
        H[A[i]]++;
    }
    for(int i=min;i<=max;i++) 
    {
        if(H[i]>0)
        {
            int j=0;
            while(j<H[i])
            {
                A[k++]=i;
                j++;
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int Ar[]={6,3,9,10,15,6,8,12,3,6};
    int size=sizeof(Ar)/sizeof(Ar[0]);
    Count_Sort(Ar,size);
     return 0;
}