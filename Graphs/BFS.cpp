#include<iostream>
using namespace std;
class node
{
    public:
    node *next;
    int data;
};
class  queue
{
    node *front,*rear;
    public:
    queue()
    {
        front =rear=nullptr;
    }
    void enqueue(int data)
    {
        node *t=new node;
        t->next=nullptr;
        if(t==nullptr)
        {
            cout<<"cannot insert queue is full"<<endl;
        }
        else  if(front ==nullptr)
        {
            t->data=data;
            front =rear=t;
        }
        else
        {
            t->data=data;
            rear->next=t;
            rear=t;
        }
    }
    int dequeue()
    {
        int x=-1;
        if(front ==nullptr)
        {
            cout<<"cannot delete as the queue is empty "<<endl;
        }
        else
        {   
            node *t=front;
            x=front->data;
            front=front->next;
            delete t;
        }
        return x;
    }
    int Isempty()
    {
        return front==nullptr?1:0;
    }
    void print()
    {
        if(front==nullptr)
        {
            cout<<"the queue is empty "<<endl;
        }
        node *t=front;
        while(t!=nullptr)
        {
            cout<<t->data<<"-->";
            t=t->next;
        }
    }
};
void BFS(int vertex,int A[8][8],int n)
{
    queue q;
    int u;
    int visited[8]{0};
    visited[vertex]=1;
    cout<< vertex<<", "<<flush;
    q.enqueue(vertex);
    while(!q.Isempty())
    {
        u=q.dequeue();
        for(int v=1;v<=n;v++)
        {
            if(A[u][v]==1 && visited[v]==0)
            {
                cout<<v<<", ";
                visited[v]=1;
                q.enqueue(v);
            }
        }
    }
    cout<<endl;
}
int main(){
     int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 1 -> " << flush;
    BFS(1, A, 8);
 
    cout << "Vertex: 4 -> " << flush;
    BFS(4, A, 8);
    
     return 0;
}