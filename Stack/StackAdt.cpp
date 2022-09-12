#include<iostream>
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

int main(){
    // stack s(5);
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // cout<<"enter the index from where you want to fetch the value "<<endl;
    // int pos;
    // cin>>pos;
    // if(s.peek(pos)> -1)
    // {
    //     cout<<"element at the index "<<pos<<" is "<<s.peek(pos)<<endl;
    // }
    int option,sz,ele,index;
    cout<<"enter the size of stack "<<endl;
    cin>>sz;
    stack s(sz);
    do
    {
        cout<<"enter option you want to preform on the stack or press 0 to exit "<<endl;
        cout<<"1. push in the stack "<<endl;
        cout<<"2. pop from the stack "<<endl;
        cout<<"3. peep at the entered index "<<endl;
        cout<<"4. know the element cuurently at the top of stack "<<endl;
        cout<<"5. check if the stack is empty "<<endl;
        cout<<"6. check if the stack is full "<<endl;
        cout<<"7. print the stack "<<endl;
        cout<<"8. clear the screen "<<endl;
        cin>>option;
        switch (option)
        {
        case 0:
        break;
        case 1:
        cout<<"enter the value to be pushed in the stack "<<endl;
        cin>>ele;
        s.push(ele);
        break;
        case 2:
        if(s.pop()> -1)
        {
            cout<<"the element popped is "<<s.pop()<<endl;
        }
        break;
        case 3:
        cout<<"enter the index "<<endl;
        cin>>index;
        if(s.peek(index)> -1)
        {
            cout <<"the element at "<<index<<" is "<<s.peek(index)<<endl;
        }
        break;
        case 4:
        cout<<"element at the top of stack is"<<s.StackTop()<<endl;
        break;
        case 5:
        if(s.IsEmpty())
        {
            cout<<"stack is empty "<<endl;
        }
        else
        {
            cout<<"stack is not empty "<<endl;
        }
        break;
        case 6:
        if(s.IsFull())
        {
            cout<<"stack is full "<<endl;
        }
        else
        {
            cout<<"stack is not full"<<endl;
        }
        break;
        case 7:
        s.PrintStack();
        break;
        case 8:
        system("clear");
        break;
        default:
        cout<<"enter a valid choice "<<endl;
            break;
        }
        
    } while (option !=0);
    
     return 0;
}