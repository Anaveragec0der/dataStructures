#include<iostream>
using namespace std;
class node 
{
    public:
    int data,key;
    node *next;
};
class CircularLinkedList
{   
    public:
    node * head;
    CircularLinkedList()
    {
        head=nullptr;
    }
    node * NodeExists(int);
    void AppendNode(node *);
    void PrependNode(node *);
    void InsertNodeAfter(int ,node *);
    void DeleteNodeByKey(int);
    void UpadateNodeData(int,int);
    void PrintList();
};
node * CircularLinkedList::NodeExists(int k)
{
    node *temp =nullptr;
    node * p=head;
    if(head==nullptr)
    {
        return temp;
    }
    else 
    {
        {
        do
        {
            if(p->key==k)
            {
                temp=p;
            }
            p=p->next;
        } while (p!=head);
        return temp;
        }
        
    }
}
void CircularLinkedList::AppendNode(node *n)
{
    if(NodeExists(n->key)!=nullptr)
    {
        cout<<"node cannot be appended as node already exists with the key"<<n->key<<endl;
    }
    else
    {
        if(head==nullptr)
        {
            head=n;
            n->next=head;
            cout<<"node appended as the head node "<<endl;
        }
        else
        {
            node *p=head;
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next=n;
            n->next=head;
            cout<<"node appended "<<endl;
        }
    }
}
void CircularLinkedList::PrependNode(node *n)
{
    if(NodeExists(n->key)!=nullptr)
    {
        cout<<"node already exists with the key "<<n->key<<" enter node with the differnt key value "<<endl;
    }
    else
    {
        if(head==nullptr)
        {
            head=n;
            n->next=head;
            cout<<"node prepended as first node "<<endl;
        }
        else
        {
            node *p=head;
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next=n;
            n->next=head;
            head=n;
            cout<<"node prepended "<<endl;

        }
    }
}
void CircularLinkedList::InsertNodeAfter(int k,node *n)
{
    node *p=(NodeExists(k));
    if(p==nullptr)
    {
        cout<<"no node exists with the given key "<<k<<endl;
    }
    else
    {
        if(NodeExists(n->key)!=nullptr)
        {
            cout<<"node cannot be inserted as the node already exists with the key "<<n->key<<endl;
        }
        else
        {
            if(p->next==head)
            {
                p->next=n;
                n->next=head;
                cout<<"node inserted as the last node "<<endl;
            }
            else
            {
                n->next=p->next;
                p->next=n;
                cout<<"node inserted in between"<<endl;           
            }
        }
    }
}
void CircularLinkedList::DeleteNodeByKey(int k)
{
    node *p=NodeExists(k);
    if(p==nullptr)
    {
        cout<<"no node exists with the given key "<<k<<endl;
    }
    else
    {
        if(p==head)
        {
            if(head->next==head)
            {
                head==nullptr;
                cout<<"head node unlinked list empty"<<endl;
            }
            else
            {
                node *p1=head;
                while(p1->next!=head)
                {
                    p1=p1->next;
                }
                p1->next=head->next;
                head=head->next;
                cout<<"node unlinked with the key value "<<k<<endl;
            }
        }
        else
        {
            node *temp=nullptr;
            node *onhead=head;
            node *afterhead=head->next;
            while (afterhead!=head)
            {
                if(afterhead->key==k)
                {
                    temp=afterhead;
                    afterhead==nullptr;
                }
                else
                {
                    afterhead=afterhead->next;
                    onhead=onhead->next;
                }
            }
            if(temp!=nullptr)
            {
                onhead->next=temp->next;
                cout<<"node unlinked "<<endl;
            }
            else
            {
                cout<<"no node exists with the given key "<<endl;
            }
            
        }
    }
}
void CircularLinkedList::UpadateNodeData(int k,int d)
{
    node *p=NodeExists(k);
    if (p==nullptr)
    {
        cout<<"no node exists with the key "<<k<<endl;
    }
    else
    {
        int da=p->data;
        p->data=d;
        cout<<"the data updated from "<<da<<" to"<<d<<endl;
    }
}
void CircularLinkedList::PrintList()
{
    if (head==nullptr)
    {
        cout<<"cannot print the list as the list is empty "<<endl;
    }
    else
    {
        node* temp=head;
        cout<<"head address ="<<head<<endl;
        do
        {
            cout<<"("<<temp->key<<" , "<<temp->data<<" , "<<temp->next<<")"<<"-->"<<endl;
            temp=temp->next;
        } while (temp!=nullptr);
        
    }
}
int main(){
    CircularLinkedList C;
    int option,key,data,keyindex;
    do
    {
        cout<<"enter the operation you want to perform on the list "<<endl;
        cout<<"1. append node in the list"<<endl;
        cout<<"2. prepend node in the list"<<endl;
        cout<<"3. insert node after a given key "<<endl;
        cout<<"4. update node data"<<endl;
        cout<<"5. delete a node by the key "<<endl;
        cout<<"6. print the list "<<endl;
        cout<<"7. clear the screen"<<endl;
        cin>>option;
        node *n=new node;
        switch (option)
        {
        case 0:
            
            break;
        case 1:
        cout<<"enter the key and the data of the node to be appended "<<endl;
        cin>>key>>data;
        n->key=key;
        n->data=data;
        C.AppendNode(n);
        break;
        case 2:
        cout<<"enter the key and data of node to be prepended"<<endl;
        cin>>key>>data;
        n->key=key;
        n->data=data;
        C.PrependNode(n);
        break;
        case 3:
        cout<<"enter the key after which node is to be inserted and also the key and data of the new node"<<endl;
        cin>>keyindex>>key>>data;
        n->key=key;
        n->data=data;
        C.InsertNodeAfter(keyindex,n);
        break;
        case 4:
        cout<<"enter key of node whose data is to be updated and also the updated data"<<endl;
        cin>>keyindex>>data;
        C.UpadateNodeData(keyindex,data);
        break;
        case 5:
        cout<<"enter the key of the node to be deleted"<<endl;
        cin>>keyindex;
        C.DeleteNodeByKey(keyindex);
        break;
        case 6:
        cout<<"printing the list "<<endl;
        C.PrintList();
        break;
        case 7:
        system("clear");
        break;
        default:
            cout<<"enter a valid choice"<<endl;
            break;
        }
    } while (option!=0);
    
     return 0;
}