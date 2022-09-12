#include<iostream>
using namespace std;
double e(double x,double n)
{
    double static s=1;
    if(n==0)
    {
        return s;
    }
    for(;n>0;n--)
    {
        s=1+(x/n)*s;
    }
    return s;
}
int main(){
    cout<<e(1,10)<<endl;
     return 0;
}