#include<iostream>
using namespace std;
int pow(int m,int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return pow(m,n-1)*m;
    }
}
int main(){
    int num,raise;
    cin>>num>>raise;
    cout<<"the result of "<<num<<" raised to power "<<raise<<" is "<<pow(num,raise)<<endl;
     return 0;
}