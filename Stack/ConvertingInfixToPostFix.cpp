#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class stack
{
private:
    int size;
    int top;
    char *c;

public:
    stack()
    {
        c = nullptr;
        size = 0;
        top = -1;
    }
    stack(int sz)
    {
        size = sz;
        c = new char[sz];
        top = -1;
    }
    void push(char x)
    {
        if (top == size - 1)
        {
            cout << "stack overflow " << endl;
        }
        else
        {
            top = top + 1;
            c[top] = x;
            cout << "element pushed " << endl;
        }
    }
    char pop()
    {
        char x = '1';
        if (top == -1)
        {
            cout << "stack underflow " << endl;
        }
        else
        {
            x = c[top];
            top = top - 1;
        }
        return x;
    }
    int isempty()
    {
        return (top == -1 ? 1 : 0);
    }
    char attop()
    {
        char t = '0';
        if (top == -1)
        {
            return t;
        }
        else
        {
            return c[top];
        }
    }
};
int IsOperand(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
char *ConvertPostFix(char *infix)
{
    stack st(strlen(infix));
    char *postfix = new char[strlen(infix) + 1];
    int i, j;
    i = j = 0;
    while (infix[i] != '\0')
    {
        if (IsOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (precedence(infix[i]) > precedence(st.attop()))
            {
                st.push(infix[i++]);
            }
            else
            {
                postfix[j++] = st.pop();
            }
        }
    }
    while (!st.isempty())
    {
        postfix[j++] = st.pop();
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    string str="a+b*c-d/e";
    int len=str.length();
    char ch[len+1];
    strcpy(ch,str.c_str());
    cout<<"converted expressiopn is "<<ConvertPostFix(ch)<<endl;
    //char infix[] = "a+b*c-d/e";
    //cout << ConvertPostFix(infix) << endl;
    return 0;
}