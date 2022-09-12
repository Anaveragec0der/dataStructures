#include<iostream>
using namespace std;
int * func(int sz)
{
    int *ptr;
    ptr=new int[sz];//creating array in the heap 
    for(int i=0;i<sz;i++)
    {
        ptr[i]=i+1;
    }
    return ptr;//returning the address of the created array
}
int main(){
    int *p;
    int size=6;
    p=func(size);//storing the address in other pointer so it can also acccess the created array in the 
    //heap
    for(int j=0;j<size;j++)
    {
        cout<<p[j]<<" ";//printing values of the array
    }
     return 0;
}