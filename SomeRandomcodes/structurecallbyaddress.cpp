#include<iostream>
using namespace std;
struct rectangle
{
    int length;
    int breadth;
};
void changelength(struct rectangle *r1,int nl)
{
    r1->length=nl;
}
int main(){
    rectangle r{10,5};
    int newl;
    cout<<"enter the length that should be used instead of the assigned length "<<endl;
    cin>>newl;
    cout<<"the length was "<<r.length<<endl;
    changelength(&r,newl);
    cout<<"the length is now changed to "<<r.length<<endl;

     return 0;
}