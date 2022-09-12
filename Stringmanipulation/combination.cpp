//  nCr
#include <iostream>
using namespace std;
int fact(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return fact(num - 1) *num;
    }
}
int c(int n, int r)
{
    int f1, f2, f3;
        f1 = fact(n);
        f2 = fact(r);
        f3 = fact(n - r);
    return (f1 / (f2 * f3));
}



//PASCAL'S TRIANGLE METHOD



int nCr(int n1,int r1)
{
    if(n1==r1||r1==0)
    {
        return 1;
    }
    else{
        return (nCr(n1-1,r1-1)+nCr(n1-1,r1));
    }
}
int main()
{
    cout<<c(5,3)<<endl;
    cout << nCr(5, 3) << endl;
    return 0;
}