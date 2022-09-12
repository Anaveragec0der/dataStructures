//NOTE-----> THE DISPLAY FUNCTION FOR DISPLYING THE QUEUE DOES NOT WORKS 
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
    public:
    node *top;
    
    stack()
    {
        top=nullptr;
    }
    void push(int x)
    {
        node *t=new node;
        if(t==nullptr)
        {
            cout<<"stack overflow "<<endl;
        }
        else
        {
            if(top==nullptr)
            {
                t->next=nullptr;
                t->data=x;
                top=t;
            }
            else
            {
            t->data=x;
            t->next=top;
            top=t;
            cout<<"element pushed "<<endl;
            }
        }
    }
    int pop()
    {
        node *t;

        int x=-1;
        if(top==nullptr)
        {
            cout<<"stack underflow "<<endl;
        }
        else
        {
            x=top->data;
            t=top;
            top=top->next;
            delete t;
        }
        return x;
    }
    int Isempty()
    {
        return top==nullptr?1:0;
    }
    int Isfull()
    {
        node *t=new node;
        return t==nullptr?1:0;
    }
    int Attop()
    {
        return top->data;
    }
};
    void print(stack s)
    {
        node *t=s.top;
        if(s.top==nullptr)
        {
            cout<<"stack underflow "<<endl;
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

stack s1,s2;
void enqueue(int x)
{
    s1.push(x);
}
int dequeue()
{
    int x=-1;
    if(s2.Isempty())
    {
        if(s1.Isempty())
        {
            cout<<"queue is empty "<<endl;
            return x;
        }
        else
        {
            while(!s1.Isempty())
            {
                s2.push(s1.pop());
            }
        }
    }
    
    x=s2.pop();
    return x;
}
int main(){
    int choice;
    int ele;
    do
    {
        cout<<"enter the operation number you want to perform on the queue "<<endl;
        cout<<"1. enqueue "<<endl;
        cout<<"2. dequeue "<<endl;
        cout<<"3. print the queue "<<endl;
        cout<<"4. clear the screen  "<<endl;
        cin>>choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout<<"enter the element to be inserted in the queue "<<endl;
            cin>>ele;
            enqueue(ele);
            break;
        case 2:
            cout<<"the element "<<dequeue()<<" deleted fron the queue"<<endl;
            break;
        case 3:
            cout<<"printing first stack "<<endl;
            print(s2);
            cout<<"printing second stack "<<endl;
            print(s2);
            break;
        case 4:
            system("clear");
            break;
        default:
            cout<<"invalid choice "<<endl;
            break;
        }
    } while (choice!=0);
    
     return 0;
}