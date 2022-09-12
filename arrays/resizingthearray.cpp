#include<iostream>
using namespace std;


//NOTE:- AN ARRAY CREATED IN STACK CANNOT BE RESIZED AT ALL BUT AN ARRAY CREATED IN HEAP CAN BE RESIZED 
//TO RESIZE AN ARRAY A NEW ARRAY IN HEAP IS CREATED THEN THE PREVIOUSILY CREATED POINTER IS MADE TO POINT ON 
//THE NEW ARRAY THEN THE FIRST SMALLER SIZED CREATED ARRAY IS DELETED AND THE POINTER USED TO CREATE NEW ARRAY IS ALSO DELETED
//THERE IS NO ACTUAL WAY RESIZE AN ARRAY AS ARRAY IS CONTIGIOUS MEMORY BLOCK AND LATER A NEW CONTIGIOUS MEMORY
//BLOCK CANNOT BE ADDED AS IT IS NOT SURE IF THAT SPACE IS FREE OR NOT THUS CANNOT BE ASSIGNED 
int main(){
    int *p,*q;
    p=new int[5];
    p[0]=2;
    p[1]=4;
    p[2]=6;
    p[3]=8;
    p[4]=10;
    q=new int[10];
    for(int i=0;i<5;i++)
    {
        q[i]=p[i];
    }
    delete[] p;//deleting array p
    p=q;
    q=NULL;

    for(int i=0;i<5;i++)
    {
        cout<<p[i]<<endl;
    }
     return 0;
}