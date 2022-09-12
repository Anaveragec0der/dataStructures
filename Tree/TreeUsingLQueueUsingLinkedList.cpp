/*
HERE 4 CLASSES IN THE WHOLE ARE USED
1ST----->> IS FOR THE NODES OF THE TREE AS THE TREE IS REPERESNTED IN A LINKED LIST FASHION
2ND----->> IS FOR THE NODES OF THE QUEUE AS THE QUEUE HERE WILL BE CONTAINING THE ADDRESS OF THE NODES OF THE TREE
AND QUEUE ITSELF IS CREATED USING THE LINKED LIST SO A CLASS FOR NODES OF THIS QUEUE IS REQUIRED
3RD----->> IS FOR CREATING THE QUEUE AND IMPLEMENTING VARIOUS FUNCTIONS ON THE QUEUE
4TH----->> IS FOR THE CREATION OF THE TREE AND PERFORMING VARIOUS FUNCTIONS ON THE TREE
*/
#include <iostream>
using namespace std;
class Tnode
{
public:
    Tnode *lchild;
    Tnode *rchild;
    int data;
};
class Qnode
{
public:
    Tnode *data; // AS THE DATA STORED IN THE QUEUE WILL BE THE ADDRESS OF THE NODES OF THE TREE
    Qnode *next; // AS THE QUEUE IS BEING CREATED THROUGH A LINKED LIST
};
class Queue
{
    Qnode *front, *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }
    void enqueue(Tnode *n)
    {
        Qnode *t = new Qnode;
        t->next = nullptr;
        t->data = n;
        if (t == nullptr)
        {
            cout << "queue is full " << endl;
        }
        else if (front == nullptr)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
    Tnode *dequeue()
    {
        Tnode *x = nullptr;
        Qnode *t;
        if (front == nullptr)
        {
            cout << "Queue is empty " << endl;
        }
        else
        {
            x = front->data;
            t = front;
            front = front->next;
            delete (t);
        }
        return x;
    }
    int IsEmpty()
    {
        return front == nullptr ? 1 : 0;
    }
};
class Tree
{
public:
    Tnode *root;

    Tree()
    {
        root = nullptr;
    }
    void CreateTree()
    {
        Tnode *p, *t;
        int data;
        Queue q;
        root = new Tnode;
        cout << "enter the data in root node " << endl;
        cin >> root->data;
        root->lchild = root->rchild = nullptr;
        q.enqueue(root);
        while (!q.IsEmpty())
        {
            p = q.dequeue();
            cout << "enter the left child of " << p->data << " if it does not have a child enter -1" << endl;
            cin >> data;
            if (data != -1)
            {
                t = new Tnode;
                t->data = data;
                t->lchild = t->rchild = nullptr;
                p->lchild = t;
                q.enqueue(t);
            }
            cout << "enter the right child of " << p->data << " if it does not have a child enter -1" << endl;
            cin >> data;
            if (data != -1)
            {
                t = new Tnode;
                t->data = data;
                t->lchild = t->rchild = nullptr;
                p->rchild = t;
                q.enqueue(t);
            }
        }
    }
    Tnode * GetNode()//Will be used to get the value of root if the root is made private data member
    {
        return root;
    }
    void PreOrder(Tnode *n)
    {
        if (n != nullptr)
        {
            cout << n->data << " ";
            PreOrder(n->lchild);
            PreOrder(n->rchild);
        }
    }
    void InOrder(Tnode *n)
    {
        if (n != nullptr)
        {
            InOrder(n->lchild);
            cout << n->data << " ";
            InOrder(n->rchild);
        }
    }
    void PostOrder(Tnode *n)
    {
        if (n != nullptr)
        {
            PostOrder(n->lchild);
            PostOrder(n->rchild);
            cout << n->data << " ";
        }
    }
    int count(Tnode *n)
    {
        if (n != nullptr)
        {
            return count(n->lchild) + count(n->rchild) + 1;
        }
        return 0;
    }
    int Level(Tnode *n)
    {
        int x = 0, y = 0;
        if (n == nullptr)
        {
            return 0;
        }
        x = Level(n->lchild);
        y = Level(n->rchild);
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
    int CountDegree2(Tnode *n)
    {
        int x = 0, y = 0;
        if (n == nullptr)
        {
            return 0;
        }
        x = CountDegree2(n->lchild);
        y = CountDegree2(n->rchild);
        if(n->lchild!=nullptr && n->rchild!=nullptr)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
        return 0;
    }
    int CoutLeafNodes(Tnode *n)
    {
        int x = 0, y = 0;
        if (n == nullptr)
        {
            return 0;
        }
        x = CoutLeafNodes(n->lchild);
        y = CoutLeafNodes(n->rchild);
        if(n->lchild==nullptr && n->rchild==nullptr)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
        return 0;
    }
    int CoutNodesWithDegree1or2(Tnode *n)
    {
        int x = 0, y = 0;
        if (n == nullptr)
        {
            return 0;
        }
        x = CoutNodesWithDegree1or2(n->lchild);
        y = CoutNodesWithDegree1or2(n->rchild);
        if(n->lchild!=nullptr || n->rchild!=nullptr)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
        return 0;
    }
    int CoutNodesWithDegree1(Tnode *n)
    {
        int x = 0, y = 0;
        if (n == nullptr)
        {
            return 0;
        }
        x = CoutNodesWithDegree1(n->lchild);
        y = CoutNodesWithDegree1(n->rchild);
        if((n->lchild==nullptr && n->rchild!=nullptr) ||(n->lchild!=nullptr && n->rchild==nullptr))
        //THIS CONDITION IS SIMILAR TO L XOR R AS LR' + L'R IS BEING IMPLEMENTED HERE 
        //THUS IF WE WANT T0 SHORTEN THIS CONDITON IT CAN BE WRITTEN AS 
        //IF(n->lchild!=nullptr ^ n->rchild!=nullptr)
        {
            return x+y+1;
        }
        else
        {
            return x+y;
        }
        return 0;
    }
};
int main()
{
    Tree t;
    t.CreateTree();
    cout << "The number of nodes in the tree are " << t.count(t.root) << endl;
    cout << "The level of tree is " << t.Level(t.root) << endl;
    // cout<<"The PreOrder Of the tree is "<<endl;
    // t.PreOrder(t.root);
    // cout<<endl;
    // cout<<endl;
    // cout<<"The InOrder Of the tree is "<<endl;
    // t.InOrder(t.root);
    // cout<<endl;
    // cout<<endl;
    // cout<<"The PostOrder Of the tree is "<<endl;
    // t.PostOrder(t.root);
    // cout<<endl;
    // cout<<endl;
    return 0;
} 