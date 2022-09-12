#include <iostream>
using namespace std;
class node
{
public:
    int data;
    int key;
    node *next;
    // node()
    // {
    //     data = 0;
    //     next = nullptr;
    //     key = 0;
    // }
    // node(int k, int d)
    // {
    //     key = k;
    //     data = d;
    // }
};
class LinkedList
{
public:
    node *head;
    LinkedList()
    {
        head = nullptr;
    }
    // LinkedList(node *n)
    // {
    //     head = n;
    // }

    node *CheckIfNodeExists(int);
    void AppendNode(node *);
    void PrependNode(node *);
    void InsertNodeAfter(int, node *);
    void DeleteNodeByKey(int);
    void UpdateNodeDataByKey(int, int);
    void PrintList();
};
node *LinkedList::CheckIfNodeExists(int k)
{
    node *temp = nullptr;
    node *p = head;
    while (p != nullptr)
    {
        if (p->key == k)
        {
            temp = p;
        }
        p = p->next;
    }
    return temp;
}
void LinkedList::AppendNode(node *n)
{
    if (CheckIfNodeExists(n->key) != nullptr)
    {
        cout << "The node already exists with the value " << n->key << "please append node with different key " << endl;
    }
    else
    {
        if (head == nullptr)
        {
            head = n;
            cout << "node appended " << endl;
        }
        else
        {
            node *p = head;
            while (p->next != nullptr)
            {
                p = p->next;
            }
            p->next = n;
            cout << "node appended " << endl;
        }
    }
}
void LinkedList::PrependNode(node *n)
{
    node *p = head;
    if (CheckIfNodeExists(n->key) != nullptr)
    {
        cout << "The node already exists with the value " << n->key << "please prepend node with different key " << endl;
    }
    else
    {
        n->next = head;
        head = n;
        cout << "node prepended " << endl;
    }
}
void LinkedList::InsertNodeAfter(int k, node *n)
{
    node *p = CheckIfNodeExists(k);
    if (p == nullptr)
    {
        cout << "the desired key " << k << " does not exists thus value cannot be inserted " << endl;
    }
    else
    {
        if (CheckIfNodeExists(n->key) != nullptr)
        {
            cout << "The node already exists with the value " << n->key << "please insert node with different key " << endl;
        }
        else
        {
            n->next = p->next;
            p->next = n;
            cout << "node inserted " << endl;
        }
    }
}
void LinkedList::DeleteNodeByKey(int k)
{
    if (head == nullptr)
    {
        cout << "cannot delete as the list is already empty" << endl;
    }
    else if (head != nullptr)
    {
        if (head->key == k)
        {
            head = head->next;
            cout << "Node unlinked with key value" << k << endl;
        }
        else
        {
            node *temp = nullptr;
            node *prevptr = head;
            node *currentptr = head->next;
            while (currentptr != nullptr)
            {
                if (currentptr->key == k)
                {
                    temp = currentptr;
                    currentptr = nullptr;
                }
                else
                {
                    currentptr = currentptr->next;
                    prevptr = prevptr->next;
                }
            }
            if (temp != nullptr)
            {
                prevptr->next = temp->next;
                cout << "node unlinked with key" << k << endl;
            }
            else
            {
                cout << "the node with key " << k << " does not exists" << endl;
            }
        }
    }
}
void LinkedList::UpdateNodeDataByKey(int k, int d)
{
    node *p = CheckIfNodeExists(k);
    if (p != nullptr) 
    {
        p->data = d;
        cout << "node updated succesfully " << endl;
    }
    else
    {
        cout << "no node exists with the key value " << k;
    }
}
void LinkedList::PrintList()
{
    if (head == nullptr)
    {
        cout << "the list is empty " << endl;
    }
    else
    {
        node *p = head;
        while (p != nullptr)
        {
            cout << "(" << p->key << " , " << p->data << ")"
                 << "-->";
            p = p->next;
        }
    }
}
int main()
{
    LinkedList l;
    int option;
    int keyindex;
    int key, data;
    do
    {
        cout << "\n What operations to perform? Select an option number .Enter 0 to exit" << endl;
        cout << "1. Append node " << endl;
        cout << "2. Prepend node " << endl;
        cout << "3. Insert node after given key " << endl;
        cout << "4. delete node by key " << endl;
        cout << "5. Update node data by key " << endl;
        cout << "6. print the list " << endl;
        cout << "7. clear screen " << endl;
        cin >> option;
        node *n = new node;
        switch (option)
        {
        case 0:

            break;
        case 1:
            cout << "Append node \n enter the key and data of the node to be appended " << endl;
            cin >> key;
            cin >> data;
            n->data = data;
            n->key = key;
            l.AppendNode(n);
            break;
        case 2:
            cout << "prepend node \n enter the key and data of the node to be prepended " << endl;
            cin >> key;
            cin >> data;
            n->data = data;
            n->key = key;
            l.PrependNode(n);
            break;
        case 3:
            cout << "insert node after the given key enter the key and the data " << endl;
            cin >> keyindex;
            cin >> key;
            cin >> data;
            n->key = key;
            n->data = data;
            l.InsertNodeAfter(keyindex, n);
            break;
        case 4:
            cout << "delete the node by the give key " << endl;
            cin >> keyindex;
            l.DeleteNodeByKey(keyindex);
            break;
        case 5:
            cout << "Update node data by key " << endl;
            cin >> keyindex;
            cin >> data;
            l.UpdateNodeDataByKey(keyindex, data);
            break;
        case 6:
            l.PrintList();
            break;
        case 7:
            cout << "clear the screen" << endl;
            system("clear");
            break;
        default:
            cout << "enter valid choice " << endl;
        }

    } while (option != 0);

    return 0;
}