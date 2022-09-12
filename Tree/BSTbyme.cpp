#include<iostream>
using namespace std;
class bstnode
{
    public:
    bstnode *lchild;
    int data;
    bstnode *rchild;
};
class BST
{
    public:
    bstnode *root;
    BST()
    {
        root=nullptr;
    }
    void insert(int key)
    {
        bstnode *temp,*iteratorpointer,*tailpointer;
        if(root==nullptr)
        {
            temp=new bstnode;
            temp->data =key;
            temp->lchild=temp->rchild=nullptr;
            root =temp;
            return;
        }
        iteratorpointer=root;
        while(iteratorpointer!=nullptr)
        {
            tailpointer=iteratorpointer;
            if(iteratorpointer->data==key)
            {
                return;
            }
            else if(key<iteratorpointer->data)
            {
                iteratorpointer=iteratorpointer->lchild;
            }
            else
            {
                iteratorpointer=iteratorpointer->rchild;
            }
        }
        temp=new bstnode;
        temp->data=key;
        temp->lchild=temp->rchild=nullptr;
        if(key<tailpointer->data)
        {
            tailpointer->lchild=temp;
        }
        else
        {
            tailpointer->rchild=temp;
        }
    }
    void inorder(bstnode *n)
    {
        if(n!=nullptr)
        {
            inorder(n->lchild);
            cout<<n->data<<" ";
            inorder(n->rchild);
        }
    }
    bstnode* search(int key)
    {
        bstnode *temp=root;
        while(temp!=nullptr)
        {
            if(key<temp->data)
            {
                temp=temp->lchild;
            }
            else if(key>temp->data)
            {
                temp=temp->rchild;
            }
            else
            {
                return temp;
            }
        }
        return nullptr;
    }
    bstnode * Delete(bstnode *n ,int key)
    {
        bstnode *q;
        if(n==nullptr)
        {
            return nullptr;
        }
        if(n->lchild==nullptr && n->rchild==nullptr)
        {
            if(n==root)
            {
                root =nullptr;
            }
            delete n;
            return nullptr;
        }
        if(key<n->data)
        {
            n->lchild=Delete(n->lchild,key);
        }
        else if(key>n->data)
        {
            n->rchild=Delete(n->rchild,key);
        }
        else
        {
            if(height(n->lchild)>height(n->rchild))
            {
                q=inpre(n->lchild);
                n->data=q->data;
                n->lchild=Delete(n->lchild,q->data);
            }
            else
            {
                if(height(n->rchild)>height(n->lchild))
                {
                    q=insuc(n->rchild);
                    n->data=q->data;
                    n->rchild=Delete(n->rchild,q->data);
                }
            }
        }
        return n;
    }
    int height(bstnode *n)
    {
        int x=0,y=0;
        x=height(n->lchild);
        y=height(n->rchild);
        if(n==nullptr)
        {
            return 0;
        }
        if(x>y)
        {
            return x+1;
        }
        else
        {
            return y+1;
        }
    }
    bstnode *inpre(bstnode *n)
    {
        while(n!=nullptr && n->rchild!=nullptr)
        {
            n=n->rchild;
        }
        return n;
    }
    bstnode *insuc(bstnode *n)
    {
        while(n!=nullptr && n->lchild!=nullptr)
        {
            n=n->lchild;
        }
        return n;
    }
    
};
int main(){
    
     return 0;
}