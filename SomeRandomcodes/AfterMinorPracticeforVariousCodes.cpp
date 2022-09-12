#include<iostream>
using namespace std;
class various
{
    int length ,size;
    int *p;
    public:
    void createarray()
    {
        cout<<"enter the size of array "<<endl;
        cin>>size;
        p=new int[size];
    }
    void getlements()
    {
        cout<<"enter the number of elements in the array "<<endl;
        cin>>length;
        cout<<"enter elements in the array "<<endl;
        for(int i=0;i<length;i++)
        {
            cin>>p[i];
        }
    }
    int linearsearch(int ele)
    {
        for(int i=0;i<length;i++)
        {
            if(p[i]==ele)
            {
                return i;
            }
        }
        return -1;
    }
    void displayarr()
    {
        for(int i=0;i<length;i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
    void swap(int &x,int &y)
    {
        y=x+y;
        x=y-x;
        y=y-x;
    }
    int improvedlinearsearch(int ele)
    {
        for(int i=0;i<length;i++)
        {
            if(p[i]==ele)
            {
                //swap(p[i-1],p[i]);//transpositioning
                swap(p[0],p[i]);//move to head 
                return i;

            }
        }
        return -1;
    }
    void insert(int index,int el)
    { 
        if(index>=0 && index<=length)
        {
            for(int i=length;i>index;i--)
            {
                p[i]=p[i-1];
            }
            p[index]=el;
            length=length+1;
        }
    }
    int del(int);
    int findmin();
    int findmax();
    void reverse();
    void reverse2();
};
int various::del(int index)
{
    int dele=p[index];
    if(index>=0 && index<length)
    {
        for(int i=index;i<length;i++)
        {
            p[i]=p[i+1];
        }
        length=length-1;
    }
    return dele;
}

int various::findmax()
{
    int max=p[0];
    for(int i=0;i<length;i++)
    {
        if(max<p[i])
        {
            max=p[i];
    
        }
    }
    return max;
}

int various::findmin()
{
    int min=p[0];
    for(int i=0;i<length;i++)
    {
        if(min>p[i])
        {
            min=p[i];
        }
    }
    return min;
}
void various :: reverse()//reverse with an auxillary array 
{
    int *t;
    t=new int[length];
    for(int i=0,j=length-1;i<length;i++,j--)
    {
        t[i]=p[j];
    }
    cout<<"the reversed array is "<<endl;
    for(int i=0;i<length;i++)
    {
        cout<<t[i]<<" ";
    }
    cout<<endl;
}

void various :: reverse2()
{
    for(int i=0,j=length-1;i<j;i++,j--)
    {
        swap(p[i],p[j]);
    }
    cout<<"the reversed array is "<<endl;
    for(int i=0;i<length;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;

}
int binarysearch(int a[],int l, int h, int element)
{
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(a[mid]==element)
        {
            return mid;
        }
        else if(a[mid]>element)
        {
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}
int main(){
    various v;
    v.createarray();
    v.getlements();
    v.displayarr();
    // cout<<"999 inserted at index 2"<<endl;
    v.insert(5,999);
    v.displayarr();
   //  cout<<"deleting element at index 2 "<<endl;
    int deleted= v.del(5);
    cout<<"deleted element is "<<deleted<<endl;
    v.displayarr();
    int maxm=v.findmax();
    cout<<"the largest number in the array is "<<maxm<<endl;
    int minm=v.findmin();
    cout<<"the smallest number in the array is "<<minm<<endl;
    v.reverse2();
    // int res;
    // res=v.improvedlinearsearch(50);
    // if(res!=-1)
    // {
    //     cout<<"element found at index "<<res<<endl;
    //     v.displayarr();
    // }
    // else{
    //     cout<<"element not found "<<endl;
    // }
    // int arr[10]={1,12,34,56,67,78,79,90,94,100};
    // int res2=binarysearch(arr,0,9,79);
    // if(res2!=-1)
    // {
    //     cout<<"element found at index "<<res2<<endl;
    // }
    // else{
    //     cout<<"element not found "<<endl;
    // }

     return 0;
}