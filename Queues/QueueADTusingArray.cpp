#include<iostream>
using namespace std;
class queue
{
    int front,rear,size;
    int *p;
    public:
    queue()
    {
        p=nullptr;
        front=rear=-1;      
    }
    queue(int sz)
    {
        front =rear =-1;
        size=sz;
        p=new int[size];
    }
    void enqueue(int x)
    {
        if(rear ==size-1)
        {
            cout<<"queue is full "<<endl;
        }
        else
        {
            rear=rear+1;
            p[rear]=x;
            cout<<"element inserted in the queue "<<endl;
        }
    }
    int dequeue()
    {
        int x=-1;
        if(front ==rear)
        {
            cout<<"queue is empty "<<endl;
        }
        else 
        {
            front=front+1;
            x=p[front];
        }
        return x;
    }
    int isfull()
    {
        return((rear==size-1?1:0));
    }
    int isempty()
    {
        return((front==rear?1:0));
    }
    int first()
    {
        if(isempty())
        {
            cout<<"queue is empty "<<endl;
            return -1;
        }
        else 
        {
            return p[front+1];//returning front 1 because front pointer is not pointing on the first 
            //element but it is pointing on the element just before the first element 
        }
    }
    int islast()
    {
        if(isempty())
        {
            cout<<"queue is empty "<<endl;
            return -1;
        }
        else
        {
            return p[rear];
        }
    }
    void print()
    {
        for(int i=front+1;i<=rear;i++)
        {
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    int size;
    cout<<"enter the size of the queue "<<endl;
    cin>>size;
    queue q(size);
    cout<<"enter the elements in the queue "<<endl;
    int ele;
    for(int i=0;i<size;i++)
    {
        cin>>ele;
        q.enqueue(ele);
    }
    cout<<"enter the number of elements you want to delete from the queue"<<endl;
    int items;
    cin>>items;
    q.print();
    cout<<q.first()<<endl;
    cout<<q.islast()<<endl;
    for(int i=0;i<items;i++)
    {
        q.dequeue();
    }
    q.print();
    cout<<q.first()<<endl;
    cout<<q.islast()<<endl;
     return 0;
}