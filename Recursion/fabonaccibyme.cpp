#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a,b,c;
    a=0;b=1;
    if(n<=1)
    {
        cout<<n<<endl;
    }
    for (int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;
        cout<<c<<" "<<endl;
    }
    return 0;
}