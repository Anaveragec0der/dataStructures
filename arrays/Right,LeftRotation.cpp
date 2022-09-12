#include<iostream>
using namespace std;
//LEFT SHIFTING ARRAY BY ONE 
void LeftShiftByOne(int a[],int length)
{
    int temp=a[0];
    for(int i=0;i<length;i++)
    {
        a[i]=a[i+1];
    }
    a[length-1]=temp;
}
//LEFT SHIFTING THE ARRAY BY MULTIPLE USING LEFT SHIFT BY ONE FUNCTION
void LeftShiftByMultiple(int a[],int length,int p)
{
    for(int i=0;i<p;i++)
    {
        LeftShiftByOne(a,5);
    }

}
//UTILITY FUNCTION TO PRINT ARRAY 
void printarr(int a[],int length)
{
    cout<<"the array is "<<endl;
    for(int i=0;i<length;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

//RIGHT SHIFTING ARRAY BY ONE 
void RightShiftByOne(int a[],int length)
{
    int temp=a[length-1];
    for(int i=length-1;i>=0;i--)
    {
        a[i]=a[i-1];
    }
    a[0]=temp;
}

//RIGHT SHIFTING ARRAY BY MULTIPLE 
void RightShiftByMultiple(int a[],int length,int p)
{
    for (int i=0;i<p;i++)
    {
        RightShiftByOne(a,length);
    }

}
int main(){
    int arr[5]={2,4,5,6,10};
   // LeftShiftByMultiple(arr,5,3);
   RightShiftByMultiple(arr,5,2);
    printarr(arr,5); 
     return 0;
}