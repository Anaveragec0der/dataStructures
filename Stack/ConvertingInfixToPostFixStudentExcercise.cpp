//NOTE :- THIS PROGRAM IS FOR CONVERTING INFIX EXPRESSION TO POSTFIX EXPRESSION, IT IS FOR THE EXPRESSIONS
//HAVING OPERATORS LIKE (),^,*,/,+,- THE PROGRAM USES A OUTSTACK AND INSTACK PRECEDENCES OF THESE OPERATORS
//BASICALLY THESE PRECENDENCES ARE NO FIXED VALUES BUT ARE USER DEFINED VALUES 
//THE PRECENDEDNCE OF THE OPERATORS +,- ARE KEPT LOWER THAN THE * ,/  AND SO ON
//THE OUTSTACK AND INSTACK PRECEDENCES OF PARTICULAR OPERATOR ARE KEPT IN ASCENDING ORDER IF THEY HAVE
//LEFT TO RIGHT ASSOCIATIVITY WHILE THEY ARE KEPT IN DESCENDING ORDER IF THEY FOLLOW RIGHT TO LEFT ASSOCIATIVITY
/*

THE TABLE USED IN THIS CODE IS AS FOLLOWS
      OPERATOR      OUTSTACK PRECEDENCE       INSTACK PRECEDENCE      ASSOCIATIVITY
      + OR -               1                         2                   L TO R
      * OR /               3                         4                   L TO R
      ^ OR ANY UNARY OP    6                         5                   R TO L
      (                    7                         0                   L TO R
      )                    0                  NEVER PUSHED HENCE NOT DEFINED    


AND SOO ON WE CAN KEEP ADDDING OPERATORS AND THE PRECEDENCES IN THE TABLE TO FIND POSTFIX OF 
EXPRESSIONS WITH DIFFERENT OPERATORS 
*/
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
class stack
{
    int size,top;
    char *s;
    public:
    stack()
    {
        size=0;
        top=-1;
        s=nullptr;
    }
    stack(int sz)
    {
        size=sz;
        s=new char[size];
        top=-1;
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
            s[top]=x;
            //cout<<"element pushed "<<endl;
        }
    }
    char pop()
    {
        char x='1';
        if(top==-1)
        {
            cout<<"stack underflow "<<endl;
        }
        else
        {
            x=s[top];
            top=top-1;
        }
        return x;
    }
    int IsEmpty()
    {
       return((top==-1?1:0)); 
    }
    char AtTop()
    {
        char x='1';
        if(IsEmpty())
        {
            cout<<"stack empty"<<endl;
        }
        else
        {
            x=s[top];
        }
        return x;
    }
};
int IsOperand(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')'||c=='^')
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}
int OutPrecedence(char c)
{
    if((c=='+')||(c=='-'))
    {
        return 1;
    }
    else if((c=='*')||(c=='/'))
    {
        return 3;
    }
    else if(c=='^')
    {
        return 6;
    }
    else if(c=='(')
    {
    return 7;
    }
    else if(c==')') 
    {
        return 0;
    }
    return -1;
}
int InPrecedence(char c)
{
    if((c=='+')||(c=='-'))
    {
        return 2;
    }
    else if((c=='*')||(c=='/'))
    {
        return 4;
    }
    else if(c=='^')
    {
        return 5;
    }
    else if(c=='(')
    {
    return 0;
    }
    return -1;
}
char* ConvertPostfix(char *infix)
{
    stack s(strlen(infix));
    char *postfix=new char[strlen(infix)];
    int i,j;
    i=j=0;
    while(infix[i]!='\0')
    {
        if(IsOperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else 
        {
            if(s.IsEmpty()||OutPrecedence(infix[i])>InPrecedence(s.AtTop()))
            {
                s.push(infix[i++]);
            }
            else if(OutPrecedence(infix[i])==InPrecedence(s.AtTop()))
            {
                s.pop();
                i++;
            }
            else 
            {
                postfix[j++]=s.pop();
            }
        }
    }
    while(!s.IsEmpty())
    {
        postfix[j++]=s.pop();
    }
    postfix[j]='\0';
    return postfix;
}
int main(){
    string str="(a+b)*c-d^e^f";
    char ch[str.length()];
    strcpy(ch,str.c_str());
    cout<<"the infix to postfix conversion of "<<str<<" is "<<endl;
    cout<<ConvertPostfix(ch)<<endl;
     return 0;
}