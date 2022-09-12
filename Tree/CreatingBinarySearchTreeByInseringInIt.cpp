// THIS CODE IS FOR CREATING THE BINARY SEARCH TREE USING INSERT FUNCTION 
// ALSO CONTAINS INORDER TRAVERSAL OF A BINARY SEARCH TREE 
// ALSO CONTAINS SEARCHING FOR ANY VALUE IN A BINARY SEARCH TREE 
// ALSO CONTAINS CREATING BINARY TREE USING PREORDER (USES STACK)
#include<iostream>
using namespace std;
class BSTnode;
class BST_Tree;
class StackNode
{
    public:
    StackNode *next;
    BSTnode *data;
};
class Stack
{
    public:
    StackNode *top;
    Stack()
    {
        top=nullptr;
    }
    void push(BSTnode *n)
    {
        StackNode *t=new StackNode;
        if(t==nullptr)
        {
            cout<<"stack overflow "<<endl;
        }
        else
        {
            t->next=top;
            t->data=n;
            top=t;
        }
    }
    BSTnode *pop()
    {
        BSTnode *d;
        StackNode *temp;
        if(top==nullptr)
        {
            cout<<"stack underflow "<<endl;
        }
        else
        {
            temp=top;
            d=top->data;
            top=top->next;
            delete (temp);
        }
        return d;
    }
    BSTnode * AtTop()
    {
        return top!=nullptr?top->data:nullptr;
    }
    int isempty()
    {
        return top==nullptr?1:0;
    }
};

class BSTnode
{
    public:
    BSTnode *lchild;
    int data;
    BSTnode *rchild;
};
class BST_Tree
{
    public:
    BSTnode *root;

    BST_Tree()
    {
        root=nullptr;
    }
    void Insert(int key)
    {
        BSTnode *iteratorpointer,*tailpointer,*temp;// TEMP IS USED TO CREATE THE TEMPORARY NODES FOR INSERTION, ITERATOR POINTER IS 
        //USED FOR ITERATING FROM ONE NODE TO ANOTHER, TAIL POINTER IS FOR FOLLOWING THE ITERATOR POINTER 
        iteratorpointer=root;
        //AS WE ARE CREATING A BINARY TREE USING INSERTION THIS CONDITION IS FOR INSERTING ROOT NODE IN THE TREE
        if(root==nullptr)
        {
            temp=new BSTnode;//CREATING THE FIRST NODE 
            temp->lchild=temp->rchild=nullptr;
            temp->data=key;
            root=temp;//MAKING ROOT POINT ON THE ONLY CREATED NODE
            return;//AS AFTER CREATING FIRST NODE WE WANT TO RETURN THE FUNCTION
            //WE DONT WANT REST OF THE FUNCTION TO CONTINUE 
        }
        //ONLY THE UNIQUE VALUES CAN BE INSERTED IN THE BINARY SEARCH TREE HENCE IN THIS PART WE FIRST SEARCH FOR KEY VALUE
        //IF A NODE WITH THE GIVEN KEY VALUE ALREADY EXISTS THE NODE CANNOT BE INSERTED AND WE RETURN THE FUNCTION
        //BUT IF THE NODE DOES NOT EXISTS THAT MEANS THAT AT THE END OF WHILE LOOP THE ITERATORPOINTER WILL BE POINTING 
        //ON NULL AS WE ARE SEARCHING FOT THE NODE WITH GIVEN KEY VALUE AND THE SEARCH WILL BE UNSUCCESFULL WHICH WILL MEAN
        //THE TAIL POINTER WILL BE POINTING TO THE NODE WHOSE LEFT OR RIGHT CHILD WILL HAVE TO BE INSERTED
        while(iteratorpointer!=nullptr)
        {
            tailpointer=iteratorpointer;
            if(iteratorpointer->data>key)
            {
                iteratorpointer=iteratorpointer->lchild;
            }
            else if(iteratorpointer->data<key)
            {
                iteratorpointer=iteratorpointer->rchild;
            }
            else
            {
                return;
            }
        }
            //NOW AS THE SEARCH IS UNSUCCESFULL WE WILL CREATE A NEW NODE AND MAKE THE NODE POINTED BY THE 
            //TAILPOINTER POINT ON THIS NEWLY CREATED NODE AS ITS RIGHT OR LEFT CHILD 
            //DEPENDING IF THE DATA VALUE IS LESS OR GREATER IN THE NODE POINTED BY TAIL POINTER 
            temp=new BSTnode;
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
    void InOrder(BSTnode *n)
    {
        if(n!=nullptr)
        {
            InOrder(n->lchild);
            cout<<n->data<<" "<<flush;
            InOrder(n->rchild);
        }
    }
    BSTnode *Search(int key)
    {
        BSTnode *n=root;
        while(n!=nullptr)
        {
            if(n->data==key)
            {
                return n;
            }
            else if(n->data>key)
            {
                n=n->lchild;
            }
            else
            {
                n=n->rchild;
            }
        }
        return nullptr;
    }
    BSTnode *Delete(BSTnode * p,int key)
    {
        BSTnode *q;
        if(p==nullptr)
        {
            return nullptr;
        }
        if(p->lchild==nullptr && p->rchild==nullptr)
        {
            if(p==root)
            {
                root=nullptr;
            }    
            delete p;
            return nullptr;
        }
        if(key<p->data)
        {
            p->lchild=Delete(p->lchild,key);
        }
        else if(key>p->data)
        {
            p->rchild=Delete(p->rchild,key);
        }
        else
        {
            if(Height(p->lchild)>Height(p->rchild))
            {
                q=Inpre(p->lchild);
                p->data=q->data;
                p->lchild=Delete(p->lchild,q->data);
            }
            else
            {
                q=Insuc(p->rchild);
                p->data=q->data;
                p->rchild=Delete(p->rchild,q->data);                
            }
        }
        return p;
    }
    int Height(BSTnode *n)
    {
        int x=0,y=0;
        if(n==nullptr)
        {
            return 0;
        }
        x=Height(n->lchild);
        y=Height(n->rchild);
        return x>y?x+1:y+1;
    }
    BSTnode *Inpre(BSTnode *n)
    {
        while(n!=nullptr && n->rchild!=nullptr)
        {
            n=n->rchild;
        }
        return n;
    }
    BSTnode *Insuc(BSTnode *n)
    {
        while(n!=nullptr && n->lchild!=nullptr)
        {
            n=n->lchild;
        }
        return n;
    }
    void createPre(int *pre,int size)
    {
        int i=0;
        root=new BSTnode;
        root->data=pre[i++];
        root->lchild=root->rchild=nullptr;
        Stack stk;      
        BSTnode *t,*p;
        p=root;
        while(i<size)
        {
            if(pre[i]<p->data)
            {
                t=new BSTnode;
                t->data=pre[i++];
                t->lchild=t->rchild=nullptr;
                p->lchild=t;
                stk.push(p);
                p=t;
            }
            else
            {
                if(pre[i]>p->data && pre[i]<(stk.isempty()?INT32_MAX:stk.AtTop()->data))
                {
                    t=new BSTnode;
                    t->data=pre[i++];
                    t->lchild=t->rchild=nullptr;
                    p->rchild=t;
                    p=t;
                }
                else
                {
                    p=stk.AtTop();
                    stk.pop();
                }
            }
        }
    }
};

int main(){
    BST_Tree t;
    // t.Insert(10);
    // t.Insert(5);
    // t.Insert(20);
    // t.Insert(8);
    // t.Insert(30);
    // t.Delete(t.root,5);
    // t.InOrder(t.root);
    // cout<<endl;
    // BSTnode *temp;
    // temp=t.Search(69);
    // if(temp!=nullptr)
    // {
    //     cout<<"the data "<<temp->data<<" is present at "<<temp<<endl;
    // }
    // else
    // {
    //     cout<<"the value does not exists in the tree"<<endl;
    // }
    int A[]={30,20,10,15,25,40,50,45};
    t.createPre(A,8);
    t.InOrder(t.root);
    cout<<endl;
     return 0;
}
