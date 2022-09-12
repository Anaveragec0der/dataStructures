//PROGRAM TO CHECK IF THE NUMBER OF CLOSING AND OPENING ROUND BRACKETS ARE EQUAL IN THE 
//ENTERED EXPRESSION
//NOTE -------> THIS CODE DOES NOT CHECK IF THE EXPRESSION IS CORRECTLY PARENTHESISED OR NOT
//CORRECTLY PARENTHESISED EXPRESSIONS ARE THOSE IN WHICH OPERANDS AND THE RELATED OPERATORS ARE 
//IN THE SAME PARENTHERSIS 
//((A+B)*(C+D)) -------> CORRECTLY PARENTHESISED
//(A+)B(*C-D) --------> THIS EXPRESSION IS INCORRECTLY PARENTHESISED YET IS BALANCED EXPRESSION
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
class stack 
{
    public:
    int size,top;
    char *expr;
    stack()
    {
        size=0;
        expr=nullptr;
    }
    stack(int sz)
    {
        size =sz;
        top=-1;
        expr=new char[sz];
    }
    void push(char x)
    {
        if(top==size-1)
        {
            cout<<"stack overflow "<<endl;
        }
        else
        {
            top=top+1;
            expr[top]=x;
        }
    }
    char pop()
    {
        char x='1';
        if(top==-1)
        {
            cout<<"stack underflow"<<endl;
        }
        else
        {
            char x=expr[top];
            top=top-1;
        }
        return x;
    }
    int isfull()
    {
        if(top==size-1)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    int isempty()
    {
        if(top==-1)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    
};
int IsBalanced(char *s)
{
    stack stk (strlen(s));
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='(')
        {
            stk.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(stk.isempty())
            {
                return 0;
            }
            else 
            {
                stk.pop();
            }
        }
    }
    return stk.isempty()?1:0;

}
    
int main(){
    string str1;
    cout<<"enter an expression to check if the expression is balanced or not"<<endl;
    getline(cin,str1);
    int len=str1.length();
    char s[len +1];
    strcpy(s,str1.c_str());//converting c++ string to a c string;
    if(IsBalanced(s))
    {
        cout<<"expression has balanced parenthesis "<<endl;
    }
    else
    {
        cout<<"unbalanced expression "<<endl;
    }
     return 0;
}