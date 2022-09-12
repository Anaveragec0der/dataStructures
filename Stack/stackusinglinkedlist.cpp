#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
class stack
{
    private:
    node *top;
    public:
    stack()
    {
        top=nullptr;
    }
    void push(int);
    int pop();
    int peek(int);
    int isempty();
    int isfull();
    void print();
};
void stack::push(int x)
{
    node *t=new node;
    if(t==nullptr)
    {
        cout<<"stack overflow"<<endl;
    }
    else
    {
        t->data=x;
        t->next=top;
        top=t;
        cout<<"element pushed"<<endl;
    }
}
int stack::pop()
{
    node *t;
    int x=-1;
    if(top==nullptr)
    {
        cout<<"stack underflow"<<endl;
    }
    else
    {
        t=top;
        x=top->data;
        top=top->next;
        delete t;
    }
    return x;
}
int stack::peek(int index)
{
    if (top==nullptr)
    {
        return -1;
    }
    else
    {
        node *p=top;
        for(int i=0;p!=nullptr && i<index-1;i++)
        {
            p=p->next;
        }
        if(p!=nullptr)
        {
            return p->data;
        }
        else
        {
            return -1;
        }
        
    }
}
int stack ::isempty()
{
    int r=top?0:1;
    return r;
}
int stack ::isfull()
{
    node *t=new node;
    int r=t?0:1;
    return r;
    //this line corresponds to below written code 
    //t?0:1 means if (t) which means that if t is true that is it is not a null pointer
    ///then return 0 which means false that is stack is not full
    //in case of stack by linked list the full condition may never be encountered
    //beacuse the heap memory is abundant but theriotically stack full in linked list
    //is checked if bo more furthure nodes can be created in heap thus resulting 
    //node *t=new node with t having a nullpointer
    // if(t==nullptr)
    // {
    //     return 1;
    // }
    // else
    // {
    //     return 0;
    // }
}
void stack::print()
{
     node *t=top;
    if(top==nullptr)
    {
        cout<<"stack empty "<<endl;
    }
    else 
    {
        while(t!=nullptr)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<endl;
   }
}
int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.print();
   cout<<"element popped is "<<s.pop()<<endl;
   cout<<"element popped is "<<s.pop()<<endl;
   cout<<"element popped is "<<s.pop()<<endl;
    s.print();
    cout<<"element is "<<s.peek(1)<<endl;
    s.print();
    return 0;
}