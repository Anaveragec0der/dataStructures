#include <iostream>
using namespace std;
template <class T>
class arithmetic
{
    T a, b;

public:
    arithmetic(T, T);
    T add();
    T subtract();
};
template <class T>
arithmetic<T>::arithmetic(T x, T y)
{
    a = x;
    b = y;
}
template <class T>
T arithmetic<T>::add()
{
    return a + b;
}
template <class T>
T arithmetic<T>::subtract()
{
    return a - b;
}

int main()
{
    arithmetic<int> a1(57, 51);
    cout << "addition is " << a1.add() << endl;
    cout << "subtraction is " << a1.subtract() << endl;
    arithmetic<float> a2(35, 34);
    cout << "addition is " << a2.add() << endl;
    cout << "subtraction is " << a2.subtract() << endl;

    return 0;
}