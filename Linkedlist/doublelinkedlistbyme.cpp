#include<iostream>
using namespace std;
class node
{
  public:
  int data;
  int key;
  node *previous;
  node *next;  
};
class DoubleLinkedList
{
    public:
    node *head;
    DoubleLinkedList()
    {
        head=nullptr;
    }
    node * nodeexists(int k)
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
    void appendnode(node *n)
    {
        if(nodeexists(n->key)!=nullptr)
        {
            cout<<"node exits with the key value "<<n->key<<" enter node with another key value "<<endl;
        }
        else
        {
            if(head==nullptr)
            {
                head=n;
                cout<<"node appended as head node "<<endl;
            }
            else
            {
                node *p =head;
                while(p->next!=nullptr)
                {
                    p=p->next;
                }
                n->previous=p;
                p->next=n;
                n->next=nullptr;
                cout<<"node appended "<<endl;
            }
        }
    }
    void prependnode(node *n)
    {
        if(nodeexists(n->key)!=nullptr)
        {
            cout<<"node already exists with key "<<n->key<<" enter node with different key"<<endl;
        }
        else
        {
            n->next=head;
            head->previous=n;
            head=n;
            cout<<"node prepended "<<endl;
        }
    }
    void insertnodeafter(int k,node* n)
    {
        node * p=nodeexists(k);
        if(p==nullptr)
        {
            cout<<"no node exists with the key "<<k<<endl;
        }
        else if(p!=nullptr)
        {
            if(nodeexists(n->key)!=nullptr)
            {
                cout<<"node already exists with the key "<<n->key<<" enter node with different key"<<endl;
            }
            else
            {
                if(head==nullptr)
                {
                    n->next=head;
                    head=n;
                    cout<<"node inserted as the head node "<<endl;
                }
                else if(p->next==nullptr)
                {
                    n->previous=p;
                    p->next=n;
                    n->next=nullptr;
                    cout<<"node inserted in the end"<<endl;
                }
                else
                {
                    n->previous=p;
                    n->next=p->next;
                    p->next->previous=n;
                    p->next=n;
                    cout<<"node inserted "<<endl;
                }
            }
        }
    }
    void deletenodebythekey(int k)
    {
        node* p=nodeexists(k);
        if(p==nullptr)
        {
            cout<<"no node exists with the ke "<<k<<endl;
        }
        else if(p!=nullptr)
        {
            if(head==nullptr)
            {
                cout<<"linked list is empty no nodes to delete "<<endl;
            }
            else if(head->key==k)
            {
                head=head->next;
                cout<<"head node unlinked "<<endl;
            }
            else if(p->next=nullptr)
            {
                p->previous=nullptr;
                cout<<"last node unlinked "<<endl;
            }
            else
            {
                p->previous->next=p->next;
                p->next->previous=p->previous;
                cout<<"node unlinked "<<endl;
            }
        }
    }
    void upatenodedatabykey(int k,int d)
    {
        node * ptr=nullptr;
        ptr=nodeexists(k);
        int da=ptr->data;
        
        if(ptr ==nullptr)
        {
            cout<<"no node exists with the given key "<<endl;
        }
        else
        {
            //int da=ptr ->data;
            ptr ->data=d;
            cout<<"data of node updated from "<<endl;//<<da <<" to "<<data<<endl;

        }
    }
    void PrintList()
    {
        node *p=head;
        if(head==nullptr)
        {
            cout<<"no node can be printed as the list is empty "<<endl;
        }
        else
        {
            while(p!=nullptr)
            {
                cout<<"( "<<p->key<<" , "<<p->data <<" )"<<"<-->";
                p=p->next;
            }
            cout<<endl;
        }
    }

};
int main(){
    DoubleLinkedList d;
    int option,keyindex,key,data;
    do
    {
        cout<<"select the option you want to perform on the list "<<endl;
        cout<<"1. append the node with the list "<<endl;
        cout<<"2. prepend the node "<<endl;
        cout<<"3. insert the node after the given key "<<endl;
        cout<<"4. delete the node with the key "<<endl;
        cout<<"5. update node data by the key "<<endl;
        cout<<"6. print the list "<<endl;
        cout<<"7. clear the screen "<<endl;
        node *n=new node;
        cin>>option;
        switch (option)
        {
        case 0:
        break;
        case 1:
        cout<<"enter the key and data of the node to be appended "<<endl;
        cin>>key>>data;
        n->key=key;
        n->data=data;
        d.appendnode(n);
        break;
        case 2:
        cout<<"enter the key and data of the node to be prepended "<<endl;
        cin>>key>>data;
        n->key=key;
        n->data=data;
        d.prependnode(n);
        break;
        case 3:
        cout<<"insert the key after which node should be inserted and also the key and data of node"<<endl;
        cin>>keyindex>>key>>data;
        n->key=key;
        n->data=data;
        d.insertnodeafter(keyindex,n);
        break;
        case 4:
        cout<<"enter the key of the node to be deleted "<<endl;
        cin>>keyindex;
        d.deletenodebythekey(keyindex);
        break;
        case 5:
        cout<<"enter the key of node whose data is to be updated and also the updated data "<<endl;
        cin>>keyindex>>data;
        d.upatenodedatabykey(keyindex,data);
        break;
        case 6:
        cout<<"printing the list "<<endl;
        d.PrintList();
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