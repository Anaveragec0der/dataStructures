#include<iostream>
using namespace std;
int fib(int n)
{
    int t0=0,t1=1,s=0;
    if(n<=1)
    {
        return n;
    }
    else
    {
        for(int i=2;i<=n;i++)
        {
            s=t0+t1;
            t0=t1;
            t1=s;
        }
        return s;
    }
}
int rfib(int n)
{
    if(n<=1)
    {
        return n;
    }
    else 
    return fib(n-2)+fib(n-1);
}

int me[10];
int mfib(int n)
{
    if(n<=1)
    {
        me[n]=n;
        return n; 
    }
    else{
        if(me[n-2]==-1)
        {
            me[n-2]=mfib(n-2);
        }
        if(me[n-1]==-1)
        {
            me[n-1]=mfib(n-1);
        }
        me[n]=me[n-2]+me[n-1];
        return me[n-2]+me[n-1];
    }
}
int main(){
    for(int j=0;j<10;j++)
    {
        me[j]=-1;
    }
    for(int x=0;x<10;x++)
    {
        cout<<me[x]<<endl;
    }

    cout<<mfib(5)<<endl;
     return 0;
}