// THIS CODE IS FOR THE DOUBLE ENDED QUEUE IN A DOUBLE ENDED QUEUE THE DELETION AND INSERTION CAN BE DONE FROM EITHER END
//ie DELETION AND INSERTION FROM FRONT POITNER AS WELL AS DELETION AND INSERTION FROM REAR POINTER
//THUS THIS TYPE OF QUEUE DOES NOT NECESSARILY FOLLOW FIFO OPERATION

#include <iostream>
using namespace std;
class node
{
public:
    int data, key;
    node *next;
};
class DEqueue
{
    node *front, *rear;

public:
    DEqueue()
    {
        front = rear = nullptr;
    }
    node *nodeexists(int k)
    {
        node *p = nullptr;
        node *temp = front;
        while (temp != nullptr)
        {
            if (temp->key == k)
            {
                p = temp;
            }
            temp = temp->next;
        }
        return p;
    }
    void EnqueueUsingRear(node *n)
    {
        node *t = new node;
        if (nodeexists(n->key) != nullptr)
        {
            cout << "node already exists with the key value " << n->key << " insert node with different key value " << endl;
        }
        else if (t == nullptr)
        {
            cout << "queue is full" << endl;
        }
        else if (front == nullptr)
        {
            t->next = nullptr;
            t->data = n->data;
            t->key = n->key;
            front = rear = t;
            cout << "node inserted as the first node " << endl;
        }
        else
        {
            t->data = n->data;
            t->key = n->key;
            rear->next = t;
            rear = t;
            cout<<"node inserted "<<endl;
        }
    }
    int DEqueueUsingfront() 
    {
        int x = -1;
        if (front == nullptr)
        {
            cout << "the queue is empty " << endl;
        }
        else
        {
            node *t = new node;
            x = front->data;
            t = front;
            front = front->next;
            delete (t);
        }
        return x;
    }
    void EnqueueUsingFront(node *n)// WE CREATE A NEW NODE MAKE ITS NEXT POINTER POINT TO WHERE FRONT POINTER POINTS
    //THEN WE MAKE FRONT POINT ON THE NEWLY CREATED NODE
    {
        if (nodeexists(n->key) != nullptr)
        {
            cout << "node already exists with the key value " << n->key << " enter node with different key value " << endl;
        }
        else
        {
            node *t = new node;
            if (front == nullptr)
            {
                t->next = nullptr;
                t->data = n->data;
                t->key = n->key;
                front = rear = t;
                cout << "first element in the queue inserted " << endl;
            }
            else
            {
                t->data = n->data;
                t->key = n->key;
                t->next = front;
                front = t;
                cout << "element inserted " << endl;
            }
        }
    }
    int DequeueUsingRear()//IN THIS CASE WE TAKE A TEMP POINTER AND MAKE IT POINT TO THE LAST SECOND NODE 
    //THAT IS THE NODE JUST BEFORE THE REAR POINTER BY CONDITION  (TEMP->NEXT!=REAR)
    //AND THEN WE MAKE A NEW POINTER TO STORE THE VALUE OF REAR POINTER AND DELETE IT 
    //MAKE THE TEMP->NEXT POINTER AS NULL AS IT NOW BECOMES THE LAST NODE IN THE QUEUE
    //THEN FINALLY MAKE REAR POINT ON THIS TEMP NODE
    {
        int x = -1;
        if (front == nullptr)
        {
            cout << "queue is empty " << endl;
        }
        else
        {
            if (front == rear)
            {
                node *t = new node;
                t = rear;
                x = front->data;
                delete t;
                front = rear = nullptr;
                cout << "the only element from the queue is deleted" << endl;
            }
            else
            {
                node *p = rear;
                node *t = new node;
                t=front;
                while (t->next != rear)
                {
                    t = t->next;
                }
                x = rear->data;
                t->next = nullptr;
                rear=t;
                delete p;
            }
        }
        return x;
    }
    void print()
    {
        if(front==nullptr)
        {
            cout<<"the queue is empty "<<endl;
        }
        else
        {
            node *temp=new node;
            temp=front;
            while(temp!=nullptr)
            {
                cout<<"("<<temp->key<<" "<<temp->data<<")"<<"-->";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};
int main()
{
    DEqueue d;
    int key,data,c;
    do
    {
        cout<<"Enter the operation number you want to perform or enter 0 to exit"<<endl;
        cout<<"1. Enqueue using rear "<<endl;
        cout<<"2. Dequeue using front "<<endl;
        cout<<"3. Enqueue using front "<<endl;
        cout<<"4. Dequeue using rear "<<endl;
        cout<<"5. print the queue "<<endl;
        cout<<"6. clear the screen "<<endl;
        node *n =new node;
        cin>>c;
        switch (c)
        {
        case 0:
            break;
        case 1:
            cout<<"enter the key and data of the node to be inserted"<<endl;
            cin>>key>>data;
            n->key=key;
            n->data=data;
            d.EnqueueUsingRear(n);
            break;
        case 2:
            cout<<"the node with the data "<<d.DEqueueUsingfront()<<" deleted "<<endl;
            break;
        case 3:
            cout<<"enter the key and the data of the node to be inserted "<<endl;
            cin>>key>>data;
            n->key=key;
            n->data=data;
            d.EnqueueUsingFront(n);
            break;
        case 4:
        cout<<"the node with the data "<<d.DequeueUsingRear()<<" deleted"<<endl;
        break;
        case 5:
            d.print();
            break;
        case 6:
            system("clear");
            break;
        default:
            cout<<"invalid choice enter a correct choice "<<endl;
            break;
        }
    } while (c!=0);
    
    return 0;
}