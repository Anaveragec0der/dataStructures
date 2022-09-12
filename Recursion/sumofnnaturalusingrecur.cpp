#include<iostream>
using namespace std;
int sum (int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    return sum(n-1)+n;
}
int main(){
    int num;
    cin>>num;
    cout<<"the sum of numbers from 1 to "<<num<<" is "<<sum(num)<<endl;
     return 0;
}