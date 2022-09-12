#include <iostream>
using namespace std;
double e(double x, double n)
{
    double static s = 1;
    if (n == 0)
        return s;
    else
    {
        s = 1 + (x / n) * s;
    }

    return e(x, n - 1);
}
int main()
{
    cout << " the result is " << e(1, 10) << endl;
    return 0;
}