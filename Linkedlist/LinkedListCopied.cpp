//THIS CODE WAS COPIED FROM Q&A SECTION FROM LETS CODE IMPROVED LINEAR SEARCH 

#include <iostream>
using namespace std;
 
class Node{
    public:
    //data
    int data;
    //address
    Node* next; 
}*head{nullptr};
 
void create(int a[], int sz){
    //so for creating we need  a pointer
    head = new Node;
 
    Node *t;
    Node *last;
    
    head->data=a[0];
    head->next=nullptr;
    last = head;
    // 0,0->
    for(int i{1}; i<sz;i++){
        //create a new temprory node
        t = new Node;
 
        //populate temp node
        t->data=a[i];
        t->next=nullptr;
 
        //last next is points to temp
        last->next=t;
        last = t;
    }
}
 
//display Linked list
void RprintLinked(Node *p){
    if(p!=nullptr){
        RprintLinked(p->next);
        cout<<p->data<<" -> ";
    }
}
 
 
//linear search normal without pointer 
int LinearS(Node *p,int key){
 
    while(p!=nullptr){
        if(key == p->data){
            // swap(p->data,p);
            return p->data;
        }
        p=p->next;
    }
    return -1;
}
 
//linear search with pointer
Node *Plinear(Node *p,int key){
 
    while(p){
        if(key== p->data){
            return p;
        }
        p=p->next;
    }
    return NULL;
 
}
 
//nw with recursion
Node *RLinear(Node *p, int key){
    if(p==nullptr){
        return nullptr;
    }
    else{
        // key==p->data ? return p : return RLinear(p->next,key);
        if(key==p->data){
            return p;
        }
        else{
            return RLinear(p->next,key);
        }
    }
}
 
//transposition method for linear search
Node *Tlinear(Node *p, int key){
    Node *q;
    while(p!=nullptr){
        if(key==p->data){
            if(p==head)
            {
                return p;
            }
            else
            {
            q->next=p->next;
            p->next=head;
            head=p;

            }
            return p;
        }
        q=p;
        p=p->next;
    }
    return nullptr;
}
 
 
 
int main(){
    Node *t;
    int arr[] = {2,4,55,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    create(arr, size);
    RprintLinked(head);
    cout<<endl;
    cout<<"linear is : "<<LinearS(head,4)<<endl;
    //for linear it returns address so we need pointer
    // t = Plinear(head,55);
    // t = RLinear(head,4);
    t = Tlinear(head,55);
 
    if(t!=nullptr){
        cout<<"key found at : "<<t->data<<endl;
        RprintLinked(head);
     } 
     else{
        cout<<"key not found"<<endl;
     }
    return 0;
}