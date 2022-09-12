#include<iostream>
#include<string>
#include<string.h>
using namespace std;
class stack
{
    int top,size;
    int *p;
    public:
    stack()
    {
        top=-1;
        size=0;
        p=nullptr;
    }
    stack(int sz,int t=-1)
    {
        size=sz;
        top=t;
        p=new int[sz];
    }
    void push(int);
    int pop();
    int peek(int);
    int StackTop();
    int IsEmpty();
    int IsFull();
    void PrintStack();
};
void stack::push(int x)
{
    if(top==size-1)
    {
        cout<<"stack overflow"<<endl;
    }
    else
    {
        top=top+1;
        p[top]=x;
        cout<<"element pushed "<<endl;
    }
}
int stack::pop()
{
    int x=-1;
    if(top==-1)
    {
        cout<<"stack underflow "<<endl;
    }
    else
    {
        x=p[top];
        top=top-1;
    }
    return x;
}
int stack::peek(int pos)
{
    int x=-1;
    if(top-pos+1<0 || top-pos+1>size-1)
    {
        cout<<"invalid position "<<endl;
    } 
    else
    {
        x=p[top-pos+1];//formula for converting array index to stack index
    }
    return x;
}
int stack::StackTop()
{
    if(top==-1)
    {
        return -1;
    }
    else
    {
        return p[top];
    }
}
int stack::IsFull()
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
int stack::IsEmpty()
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
void stack::PrintStack()
{
    for(int i=top;i>=0;i--)
    {
        cout<<"element -->"<<p[i]<<endl;
    }
}
int IsOperand(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int EvaluatePostFix(char *postfix)
{
    int x1,x2,res;
    stack s(strlen(postfix));
    for(int i=0;postfix[i]!=0;i++)
    {
        if(IsOperand(postfix[i]))
        {
            s.push(postfix[i]-'0');//as the stack in which we are inserting the elements is od integer type
            //and elements that we are inserting are of character type they will get typecasted 
            //and thus will be converted to their respective ascii values for example 3 will be
            //converted to 51 thus making our answers incorrect 
            //So to convert the digits to their respective integer values we subtract it from 
            //character '0' thus changing ascii values of digit to their integer values
        }
        else
        {
            x2=s.pop();
            x1=s.pop();
            switch(postfix[i])
            {
                case '+':
                res=x1+x2;
                s.push(res);
                break;
                case '-':
                res=x1-x2;
                s.push(res);
                break;
                case '*':
                res=x1*x2;
                s.push(res);
                break;
                case '/':
                res=x1/x2;
                s.push(res);
                break;
                default :
                cout<<"wrong input "<<endl;
                break;
            }
        }
    }
    return (s.pop());
}
int main(){
    char ch[]="35*62/+4-";
    cout<<"result of the postfix expression is "<<EvaluatePostFix(ch)<<endl;
     return 0;
}