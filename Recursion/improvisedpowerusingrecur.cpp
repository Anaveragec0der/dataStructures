#include<iostream>
using namespace std;
int pow(int m,int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n%2==0){
        return pow(m*m,n/2);
    }
    else{
        return m*(pow((m*m),(n-1)/2));
    }
}
int main(){
    int num,raise;
    cin>>num>>raise;
    cout<<"the result of "<<num<<" raised to power "<<raise<<" is "<<pow(num,raise)<<endl;
     return 0;
}