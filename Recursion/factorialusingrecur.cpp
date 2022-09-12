#include<iostream>
using namespace std;
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else{
        return fact(n-1)*n;
    }
}
int main(){
    int num;
    cin>>num;
    cout<<"the factorial of "<<num<<" is "<<fact(num)<<endl;
     return 0;
}