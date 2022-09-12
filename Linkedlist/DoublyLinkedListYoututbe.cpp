#include<iostream>
using namespace std;
class node 
{
     public:
     int data;
     int key;
     node *next;
     node *previous;
};
class DoubleLinkedList
{
     public:
     node *head;
     DoubleLinkedList()
     {
          head=nullptr;
     }
     node *NodeExists(int );
     void AppendNode(node *);
     void PrependNode(node*);
     void InsertNodeafter(int ,node *);
     void DeleteNodeByKey(int );
     void UpdateNodeData(int ,int);
     void PrintList();
};
node* DoubleLinkedList::NodeExists(int k)
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
void DoubleLinkedList::AppendNode(node *n)
{
     if(NodeExists(n->key)!=nullptr)
     {
          cout<<"node already exists with key value "<<n->key<<"insert node with different key value "<<endl;
     }
     else
     {
          if(head==nullptr)
          {
               head=n;
               cout<<"node appended at the start "<<endl;
          }
          else
          {
               node *p=head;
               while(p->next!=nullptr)
               {
                    p=p->next;
               }
               p->next=n;
               n->previous=p;
               n->next=nullptr;
               cout<<"node apppended "<<endl;
          }
     }
}
void DoubleLinkedList::PrependNode(node *n)
{
     if(NodeExists(n->key)!=nullptr)
     {
          cout<<"node already exists with the key value "<<n->key<<" prepend node with different key value "<<endl;
     }
     else
     {
          head->previous=n;
          n->next=head;
          head=n;
          cout<<"node prepended "<<endl;
     }
}
void DoubleLinkedList::InsertNodeafter(int k, node *n)
{
     node *p=NodeExists(k);
     if(p==nullptr)
     {
          cout<<"no node exists with the key value "<<k<<endl;
     }
     else if(p!=nullptr)
     {
          if(NodeExists(n->key)!=nullptr)
          {
               cout<<"node already exists with the key value "<<n->key<<" enter a node with different key value "<<endl;
          }
          else 
          {
               if(p->next==nullptr)
               {
                    n->previous=p;
                    p->next=n;
                    n->next=nullptr;
                    cout<<"node inserted in the end "<<endl;
               }
               else
               {
                    n->next=p->next;
                    p->next->previous=n;
                    n->previous=p;
                    p->next=n;
                    cout<<"node inserted "<<endl;
               }
          }
     }
}
void DoubleLinkedList::DeleteNodeByKey(int k)
{
     node *p=NodeExists(k);
     if(p==nullptr)
     {
          cout<<"no node exists with the given key "<<k<<endl;
     }
     else if (p!=nullptr)
     {
          if(head==nullptr)
          {
               cout<<"linked list is already empty cannot delete the node "<<endl;
          }
          else if(head!=nullptr)
          {
               if(head->key==k)
               {
                    head=head->next;
                    cout<<"head node unlinked "<<endl;
               }
               else
               {
                    node *next_ptr=p->next;
                    node *prev_ptr=p->previous;
                    if(next_ptr->next=nullptr)
                    {
                         prev_ptr->next=nullptr;
                         cout<<"last node unlinked "<<endl;
                    }
                    else
                    {
                         prev_ptr->next=next_ptr;
                         next_ptr->previous=prev_ptr;
                         cout<<"node unlinked "<<endl;
                    }
               }
          }
     }
}
void DoubleLinkedList::UpdateNodeData(int k,int d)
{
     node *temp=NodeExists(k);
     int da=temp->data;//just so that data of temp node can be shown in the print statement
     if(temp==nullptr)
     {
          cout<<"no node exists with the given key "<<endl;
     }
     else
     {
          temp->data=d;
          cout<<"data updated at the key "<<k<<" from "<<da<<" to "<<d<<endl;
     }
}
void DoubleLinkedList::PrintList()
{
     if(head==nullptr)
     {
          cout<<"no node to display the linked list is empty "<<endl;
     }
     else
     {
          node *p=head;
          while(p!=nullptr)
          {
               cout<<"("<<p->key<<" , "<<p->data<<")"<<"<-->";
               p=p->next;
          }
          cout<<endl;
     }
}
int main(){
     DoubleLinkedList d;
     int keyindex;
     int key,data,option;
     do
     {
          cout<<"select the option you want to perform on the linked lsit "<<endl;
          cout<<"1. Append node in the list "<<endl;
          cout<<"2. prepend node in the list "<<endl;
          cout<<"3. insert the node after the given index "<<endl;
          cout<<"4. delete the node by the key "<<endl;
          cout<<"5. update the data of the given node by key "<<endl;
          cout<<"6. print the list "<<endl;
          cout<<"7. clear screen "<<endl;
          node *n=new node;
          cin>>option;
          switch (option)
          {
          case 0:
               break;
          case 1:
          cout<<"enter the key and data of the node "<<endl;
          cin>>key>>data;
          n->key=key;
          n->data=data;
          d.AppendNode(n);
          break;
          case 2:
          cout<<"enter the key and data of the node to be prepended "<<endl;
          cin>>key>>data;
          n->key=key;
          n->data=data;
          d.PrependNode(n);
          break;
          case 3:
          cout<<"enter the key after which node should be inserted and also the key and data of node "<<endl;
          cin>>keyindex>>key>>data;
          n->key=key;
          n->data=data;
          d.InsertNodeafter(keyindex,n);
          break;
          case 4:
          cout<<"enter the key of the node to be deleted "<<endl;
          cin>>keyindex;
          d.DeleteNodeByKey(keyindex);
          break;
          case 5:
          cout<<"enter the key of the node whose data is to be updated "<<endl;
          cin>>keyindex>>data;
          d.UpdateNodeData(keyindex,data);
          break;
          case 6:
          d.PrintList();
          break;
          case 7:
          system("clear");
          break;
          default:
          cout<<"enter the valid choice "<<endl;
               break;
          }
     } while (option!=0);
         
     return 0;
}