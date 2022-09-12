#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s []="Hello";
    int len=0;
    int length=strlen(s);
    for(int i=0;s[i]!='\0';i++)
    {
        len++;
    }
    cout<<len<<endl;
    cout<<length<<endl;
     return 0;
}