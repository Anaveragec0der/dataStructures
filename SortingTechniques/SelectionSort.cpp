#include<iostream>
using namespace std;
void SwapUsing2var(int &a,int &b)//if we use this function for swapping we will not get desired output
{
    b=a+b;
    a=b-a;
    b=b-a;
}
void Swap(int &a,int &b)//if we use this function we get the desired output
{
int temp = a;
    a = b;
    b = temp;}
void SelectionSort(int *a,int n)
{
for (int i=0; i<n-1; i++){
        int j;
        int k;
        for (j=k=i; j<n; j++){
            if (a[j] < a[k]){
                k = j;
            }
        }
        //SwapUsing2var(a[i], a[k]);does not work
        Swap(a[i],a[k]);
    }
    // int i;
    // for(i=0;i<n-1;i++)
    // {
    //     int j,k;
    //     for(j=k=i;j<n;j++)
    //     {
    //         if(a[j]<a[k])
    //         {
    //             k=j;
    //         }
    //     }
    //   Swap(a[i],a[k]);
    // }
}
int main(){
 int A[]={10,24,1,4,69,25,42,55,100,2};
    SelectionSort(A,10);
    for(int i=0;i<10;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
   
     return 0;
}