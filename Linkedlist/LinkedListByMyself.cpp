#include<iostream>
using namespace std;
class node
{
    public:
    int key;
    int data;
    node *next;

};
class linkedlist
{
    public:
    node *head;
    linkedlist()
    {
        head=nullptr;
    }
    node * nodeexists(int);
    void appendnode(node *);
    void prependnode(node*);
    void insertnodeafter(int ,node*);
    void deletenodebykey(int);
    void updatenodedatabykey(int ,int);
    void printlist();
    void ReverseTheList();

};
node * linkedlist::nodeexists(int k)
{
    node *temp=nullptr;
    node *p=head;
    while(p!=nullptr)
    {
        if(p->key==k)
        {
            temp=p;
        }
        p=p->next;
    }
    return temp;
}
void linkedlist::appendnode(node *n)
{
    node *p=head;
    if(nodeexists(n->key)!=nullptr)
    {
        cout<<"node already exists with key value "<<n->key<<"enter node with different key value "<<endl;
    }
    else
    {
        if(head==nullptr)
        {
            head=n;
            cout<<"node appended"<<endl;
        }
        else
        {
            while(p->next!=nullptr)
            {
                p=p->next;
            }
            p->next=n;
            cout<<"node appended"<<endl;
        }
    }
    
    
}
void linkedlist::prependnode(node *n)
{
    if(nodeexists(n->key)!=nullptr)
    {
        cout<<"node already exists with the key value "<<n->key<<"enter node with different key value "<<endl;
    }
    else
    {
        n->next=head;
        head=n;
        cout<<"node prepended "<<endl;
    }
}
void linkedlist::insertnodeafter(int k,node *n)
{
    node *p=nodeexists(k);
    if(p==nullptr)
    {
        cout<<"no node with the key "<<k<<"exists"<<endl;
    }
    else
    {
        if(nodeexists(n->key)!=nullptr)
        {
            cout<<"node already exists with the key "<<n->key<<" enter the node with different key value "<<endl;
        }
        else
        {
            n->next=p->next;
            p->next=n;
            cout<<"node inserted"<<endl;
        }
    }
}
void linkedlist::deletenodebykey(int k)
{
    if(head==nullptr)
    {
        cout<<"list already empty cannot delete the element"<<endl;
    }
    else if(head!=nullptr)
    {
        if(head->key==k)
        {
            head=head->next;
            cout<<"node unlinked with the key value "<<k<<endl;
        }
        else
        {
            node *onhead=head;
            node *afterhead=head->next;
            node *temp=nullptr;
            while(afterhead!=nullptr)
            {
                if(afterhead->key==k)
                {
                    temp=afterhead;
                    afterhead=nullptr;
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
                cout<<"node unlinked with the key "<<k<<endl;
            }
            else
            {
                cout<<"the node with the given key value "<<k<<" does not exists "<<endl;
            }
        }
    }
}
void linkedlist::updatenodedatabykey(int k,int d)
{
    node *temp=nodeexists(k);
    if(temp!=nullptr)
    {
        temp->data=d;
        cout<<"node data value updated "<<endl;        
    }
    else
    {
        cout<<"no node exists with the given key "<<k<<endl;
    }

}
void linkedlist::printlist()
{
    node *p=head;
    if(head==nullptr)
    {
        cout<<"no node to display the linked list is empty "<<endl;
    }
    else
    {
        while(p!=nullptr)
        {
            cout<<"("<<p->key<<" , "<<p->data<<")"<<"-->";
            p=p->next;
        }
        cout<<endl;
    }
}
void linkedlist::ReverseTheList()
{
    node *p=head;
    node *q=nullptr;
    node *r=nullptr;
    while(p!=nullptr)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head =q;
    printlist();
}
int main()
{
    linkedlist l;
    int keyindex,key,data,option;
    do
    {
        cout<<"enter the option number which you want to perform press 0 to exit "<<endl;
        cout<<"1. append node in the list "<<endl;
        cout<<"2. prepend node in the list "<<endl;
        cout<<"3. insert node after the given index "<<endl;
        cout<<"4. delete node at given index "<<endl;
        cout<<"5. update the data at the given node "<<endl;
        cout<<"6. print the linked list "<<endl;
        cout<<"7. clear the screen "<<endl;
        cout<<"8. reversing and printing the list"<<endl;
        cin>>option;
        node *n=new node;
        switch (option)
        {
        case 0:
            break;
        case 1:
        cout<<"enter the key and data of the node to be appended "<<endl;
        cin>>key;
        cin>>data;
        n->key=key;
        n->data=data;
        l.appendnode(n);
        break;
        case 2:
        cout<<"enter the key and data of node to be prepended "<<endl;
        cin>>key;
        cin>>data;
        n->key=key;
        n->data=data;
        l.prependnode(n);
        break;
        case 3:
        cout<<"enter the key after which node should be inserted and also the key and data of node "<<endl;
        cin>>keyindex;
        cin>>key;
        cin>>data;
        n->key=key;
        n->data=data;
        l.insertnodeafter(keyindex,n);
        break;
        case 4:
        cout<<"enter the key of the node that should be deleted "<<endl;
        cin>>keyindex;
        l.deletenodebykey(keyindex);
        break;
        case 5:
        cout<<"enter the key and the data "<<endl;
        cin>>keyindex;
        cin>>data;
        l.updatenodedatabykey(keyindex,data);
        break;
        case 6:
        cout<<"printing the list "<<endl;
        l.printlist();
        break;
        case 7:
        system("clear");
        break;
        case 8:
        cout<<"revrsing the list "<<endl;
        l.ReverseTheList();
        break;
        default:
        cout<<"enter a valid choice "<<endl;
            break;
        }
    } while (option!=0);
    
    return 0;
}