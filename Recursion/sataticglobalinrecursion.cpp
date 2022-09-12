#include <iostream>
using namespace std;
int g=0;
int fun(int n)
{
   // int static x =0;static and global behave in the same way 
    if (n > 0)
    {
        ::g++;
        return fun(n - 1) + g;
    }
    return 0;
}
int main()
{
    int r;
    r = fun(5);
    cout << r << endl;
    return 0;
}