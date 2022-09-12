#include<iostream>
using namespace std;
char * touppercase(char *p)
{
    for(int i=0;p[i]!='\0';i++)
    {
        if(p[i]>='a' && p[i]<='z')
        {
            p[i]=p[i]-32;
        }
    }
    return p;
}
int main(){
    char str[]="hello";
    char *st=touppercase(str);
    cout<<st<<endl;
    //OR
    cout<<"converted string is "<<touppercase(str)<<endl;
     return 0;
}