#include<iostream>
using namespace std;
double ty(int x,int n)
{
    double static p=1;
    double static f=1;
    double res;
    if( n==0)
    {
        return 1;
    }
    else
    {
       res= ty(x,n-1);
        p=p*x;
        f=f*n;
        return res+p/f;

    }
}
int main(){
    double num1,num2;
    cin>>num1>>num2;
    double result=ty(num1,num2);
    cout<<"the result is "<<result<<endl;
     return 0;
}