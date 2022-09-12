#include<iostream>
using namespace std;
void Swap(int &a,int &b)
{
    b=a+b;
    a=b-a;
    b=b-a;
}
void BubbleSort(int *a,int n)
{
    for(int i=0;i<n-1;i++)//THIS LOOP IS FOR THE NUMBER OF PASSES AND AS THE PASSES ARE ALWAYS 1 LESS THAN TOTAL NUMBER OF 
    //ELEMENTS THUS FOR 5 ELEMENTS 4 PASSES AND FROM 0 TO 3 = 4 PASSES
    {
        int flag=0;//FOR MAKING BUBBLE SORT ADAPTIVE
        for(int j=0;j<n-1-i;j++)// HERE J<N-1 BECAUSE THE NUMBER OF COMPARISONS IN BUBBLE SORT ARE ALSO 1 LESS THAN
        //TOTAL NUMBER OF THE ELEMENTS 
        //J<N-1-I IS BECAUES AFTER EVERY PASS THE COMPARISONS SHOULD BE REDUCED BY 1 
        {
            if(a[j]>a[j+1])
            {
                Swap(a[j],a[j+1]);
                flag=1;
            }
        }
        if (flag==0)
            break;
    }
}
int main(){
    int A[]={10,24,1,4,69,25,42,55,100,2};
    BubbleSort(A,10);
    for(int i=0;i<10;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
     return 0;
}