#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
class LinkedList
{
    node *first,*last;
    public:
    void create(int *,int n);
    void display();
    int Length();
    int sum();
    int MaxEle();
    node* LinearSearch(int);
};
void LinkedList::create(int *a,int n)
{
    first=new node;
    first->data=a[0];
    first->next=nullptr;
    last=first;
    for(int i=1;i<n;i++)
    {
        node *t=new node;
        t->data=a[i];
        t->next=nullptr;
        last->next=t;
        last=t;
    }

}
void LinkedList::display()
{
    node *p=first;
    while(p!=nullptr)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int LinkedList::Length()
{
    int count=0;
    node *p=first;
    while(p!=nullptr)
    {
        count++;
        p=p->next;
    }
    return count;
}
int LinkedList::sum()
{
    int s=0;
    node *p=first;
    while(p!=nullptr)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}
int LinkedList::MaxEle()
{
    int max=INT16_MIN;
    node *p=first;
    while(p!=nullptr)
    {
        if(max<p->data)
        {
            max=p->data;
        }
        p=p->next;
    }
    return max;
}
node * LinkedList::LinearSearch(int n)
{
    node *p=first;
    while(p!=nullptr)
    {
        if(n==p->data)
        {
            return p;
        }
        p=p->next;
    }
    return nullptr;
}

int main(){
    int A[5]={1,2,99,4,5};
    LinkedList l;
    l.create(A,5);
    l.display();
    cout<<"the length / number of nodes in the linked list are "<<l.Length()
    <<endl;
    cout<<"the sum of all the elements of the linked list is "<<l.sum()<<endl;
    cout<<"the largest element in the linked list is "<<l.MaxEle()<<endl;
    if(l.LinearSearch(3))
    {
        cout<<"element found"<<endl;
    }
    else
    {
        cout<<"not found"<<endl;
    }
     return 0;
}