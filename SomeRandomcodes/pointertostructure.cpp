#include <iostream>
using namespace std;
struct rectangle
{
    int length, breadth;
};
int main()
{
    struct rectangle r = {10, 20};
    //struct rectangle *p;
    //in c++ if you remove struct keyword it will also be considered valid
    rectangle *p;
    p = &r;
    cout << sizeof(struct rectangle) << endl;
    cout << sizeof(p) << endl;
    (*p).length = 25;
    p->breadth = 22;
    cout << p->breadth << " " << p->length << endl;
    return 0;
}