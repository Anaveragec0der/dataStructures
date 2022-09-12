#include<iostream>
using namespace std;
//NOTE THIS IS THE BEST STYLE OF WRITING THE CODE IN C LANGUAGE
struct rectangle
{
    int length;
    int breadth;
};
void intialize(struct rectangle *p,int l,int b)
{
    p->length=l;
    p->breadth=b;
}
int area(struct rectangle r1)
{
    return r1.breadth*r1.length;
}
void change_length(struct rectangle *r2,int le)
{
    r2->length=le;
}
int main(){
    struct rectangle r;
    intialize(&r,20,5);  
    int ar=area(r);
    cout<<"area before changing the length "<<ar<<endl;
    change_length(&r,25);
    int ar2=area(r);
    cout<<"area after changing length to 25 "<<ar2<<endl;

     return 0;
}