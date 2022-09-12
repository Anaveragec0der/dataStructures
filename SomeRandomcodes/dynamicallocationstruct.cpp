#include<iostream>
#include<stdlib.h>
using namespace std;
struct rectangle{
    int length,breadth;
};
int main(){
    //struct rectangle *p;//in c++ even if you remove struct keyword it will be valid 
    rectangle *p;
    p=(struct rectangle*)malloc(sizeof(struct rectangle));
    //p=new struct rectangle;
    p->breadth=10;
    p->length=56;
    cout<<p->length<<" "<<p->breadth<<endl;
    return 0;
}