#include <iostream>
 
using namespace std;
 
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};
class nodeQ
{
public:
    Node *data;
    nodeQ *next;
};
class queue
{
    nodeQ *front, *rear;
 
public:
    queue();
    ~queue();
    void enqueue(Node *x);
    Node *dequeue();
    bool isempty() { return front == nullptr; }
};
queue::queue()
{
    front = rear = nullptr;
}
queue::~queue()
{
    nodeQ *t;
    while (front)
    {
        t = front;
        front = front->next;
        delete t;
    }
}
void queue::enqueue(Node *x)
{
    nodeQ *t = new nodeQ;
    t->data = x;
    t->next = nullptr;
    if (front == nullptr)
    {
        front = rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }
}
Node *queue::dequeue()
{
    Node *x = nullptr;
    nodeQ *t;
    if (front == nullptr)
    {
        cout << "queue empty" << endl;
    }
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        delete t;
    }
    return x;
}
 
class tree
{
    Node *root;
 
public:
    tree() { root = nullptr; }
    // ~tree()
    // {
    //     postDel(root);
    // }
    // void postDel(Node* p)
    // {
    //     postDel(p->lchild);
    //     postDel(p->rchild);
    //     delete(p);
    // }
    void createTree();
    void preorder(Node *p);
    void inorder(Node *p);
    void postorder(Node *p);
    Node *getRoot() { return root; }
};
 
void tree::createTree()
{
    int x;
    Node *t, *p;
    queue q;
    root = new Node;
    cout << "Enter the value of root: ";
    cin >> root->data;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);
 
    while (!q.isempty())
    {
        p = q.dequeue();
        cout << "Enter the left child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter the right child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
void tree::preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void tree::inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}
void tree::postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}
int main()
{
    tree t;
    t.createTree();
 
    cout << "preorder: ";
    t.preorder(t.getRoot());
    cout << endl;
 
    cout << "inorder: ";
    t.inorder(t.getRoot());
    cout << endl;
 
    cout << "postorder: ";
    t.postorder(t.getRoot());
    cout << endl;
 
    return 0;
}