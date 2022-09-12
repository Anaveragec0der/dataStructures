#include<iostream>
using namespace std;
class CircularQueue
{
    int front,rear,size;
    int *cq;
    public:
    CircularQueue()
    {
        front=0;rear=0;
        size=0;
        cq=nullptr;
    }
    CircularQueue(int sz)
    {
        size=sz;
        front=rear=0;
        cq=new int[size];
    }
    //inserting in the queue 
    void enqueue(int x)
    {
        if((rear+1)%size==front)
        {
            cout<<"queue is full "<<endl;
        }
        else
        {
            rear=(rear+1)%size;
            cq[rear]=x;
        }
    }
    //deleting in the queue 
    int dequeue()
    {
        int x=-1;
        if(front==rear)
        {
            cout<<"queue is empty "<<endl;
        }
        else
        {
            front=(front+1)%size;
            x=cq[front];
        }
        return x;
    }
    void print()
    {
        int i=(front+1)%size;
        do 
        {
            cout<<" "<<cq[i]<<" "<<" index "<<i;
            i=(i+1)%size;
        }
        while(i!=(rear+1)%size);
        cout<<endl;
    }
};
int main(){
    // int size;
    // cout<<"enter size of circular queue "<<endl;
    // cin>>size;
    // CircularQueue CQ(size);
    // cout<<"enter elements in the queue "<<endl;
    // int ele;
    // for(int i=0;i<size-1;i++)
    // {
    //     cin>>ele;
    //     CQ.enqueue(ele);
    // }
    CircularQueue CQ(5);
    CQ.enqueue(10);
    CQ.enqueue(20);
    CQ.enqueue(30);
    CQ.enqueue(40);
    CQ.print();
    cout<<"the element deleted is "<<CQ.dequeue()<<endl;
    CQ.print();
    CQ.enqueue(50);
    CQ.print();
//    cout<< CQ.dequeue()<<endl;
//    cout<< CQ.dequeue()<<endl;
//     CQ.enqueue(999);
//     CQ.enqueue(420);
//     CQ.print();
     return 0;
}