#include <iostream>
using namespace std;
class node
{
public: 
    int data;
    node *next;
};

class Queue
{
    node *rear, *front;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(node *no)
    {
        
            node *t = new node;
            t->next=nullptr;
            if(t==nullptr)
            {
                cout<<"cannot insert as the queue is full"<<endl;
            }

            else if (front == nullptr)
            {
                t->data=no->data;
                front = rear = t;
                cout<<"node inserted as the first node"<<endl;
            }
            else
            {
                t->data=no->data;
                rear->next=t;
                rear=t;
                cout<<"node inserted at the end"<<endl;
            }
        
    }

    int dequeue()
    {
        int x = -1;
        if (front == nullptr)
        {
            cout << "cannot delete the node as the queue is empty " << endl;
        }
        else
        {
            node *t = nullptr;
            x = front->data;
            t = front;
            front = front->next;
            delete (t);
        }
        return x;
    }
    void PrintTheQueue()
    {
        if (front == nullptr)
        {
            cout << "queue is empty " << endl;
        }
        else
        {
            node *temp = front;
            while (temp != nullptr)
            {
                cout<< temp->data 
                     << "-->";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};
int main()
{
    Queue q;
    int data;
    int ke;
    int choice;
    do
    {
   
        cout << "enter the operation number you want to perform on the queue OR enter 0 to exit" << endl;
        cout << "1. insert in the queue " << endl;
        cout << "2. delete from the queue " << endl;
        cout << "3. print the queue " << endl;
        cout << "4. clear the screen " << endl;
        cin >> choice;
        node *n = new node;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "enter the key and the data of the node to be inserted " << endl;
            cin >> data;
            n->data = data;
            q.enqueue(n);
            break;
        case 2:
            cout << "node with data " << q.dequeue() << " deleted" << endl;
            break;
        case 3:
            q.PrintTheQueue();
            break;
        case 4:
            system("clear");
            break;
        default:
            cout << "invalid choice " << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}