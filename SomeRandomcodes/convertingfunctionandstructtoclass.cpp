#include<iostream>
using namespace std;
//NOTE CONVERTING FUNCTIONANDSTRUCT.CPP TO C++ CODE BY USING CLASSES 
class rectangle
{
    int length,breadth;
    public :
    rectangle(int l,int b)
    {
        length=l;
        breadth=b;
    }
    int area()
    {
      return length*breadth;  
    }
    void change_length(int len)
    {
        length=len;
    }

};
int main(){
    rectangle r(10,25);
    int area=r.area();
    cout<<"the area is "<<area<<endl;
    r.change_length(25);
    int area2=r.area();
    cout<<"the area after changing the length is "<<area2<<endl;

     return 0;
}