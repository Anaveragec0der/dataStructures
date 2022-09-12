#include<iostream>
using namespace std;
class AVLnode
{
    public:
    AVLnode *lchild;
    int data;
    int height;
    AVLnode *rchild;
};
class AVL
{
    public:
    AVLnode *root;
    AVL()
    {
        root=nullptr;
    }
    AVLnode *Rinsert(AVLnode *n,int key)
    {
        if(n==nullptr)
        {
            AVLnode *t=new AVLnode;
            t->data=key;
            t->lchild=t->rchild=nullptr;
            t->height=1;
            return t;
        }
        if(key<n->data)
        {
            n->lchild=Rinsert(n->lchild,key);
        }
        else
        {
            n->rchild=Rinsert(n->rchild,key);
        }
        n->height=NodeHeight(n);
        if(BalanceFactor(n)==2 && BalanceFactor(n->lchild)==1)
        {
            LLrotation(n);
        }
        return n;
    }
    int NodeHeight(AVLnode *p)
    {
        int hls,hrs;
        if(p!=nullptr && p->lchild!=nullptr)
        {
            hls=p->lchild->height;
        }
        else 
        {
            hls=0;
        }
        if(p!=nullptr && p->rchild!=nullptr)
        {
            hrs=p->rchild->height;
        }
        else
        {
            hrs=0;
        }
        return hrs>hls?hrs+1:hls+1;
    }
    int BalanceFactor(AVLnode *p)
    {
        int hls,hrs;
        if(p!=nullptr && p->lchild!=nullptr)
        {
            hls=p->lchild->height;
        }
        else 
        {
            hls=0;
        }
        if(p!=nullptr && p->rchild!=nullptr)
        {
            hrs=p->rchild->height;
        }
        else
        {
            hrs=0;
        }
        return hls-hrs;
    }
    AVLnode *LLrotation(AVLnode *p)
    {
        AVLnode *pl,*plr,*pll;
        pl=p->lchild;
        plr=pl->rchild;
        pll=pl->lchild;

        p->lchild=plr;
        pl->rchild=p;
        pl->lchild=pll;
        p->height=NodeHeight(p);
        pl->height=NodeHeight(pl);
        if(root==p)
        {
            root=pl;
        }
        return pl;
    }
    AVLnode *RRrotation(AVLnode *p)
    {
        AVLnode *pr,*prl,*prr;
        pr=p->rchild;
        prl=pr->lchild;
        prr=pr->rchild;

        pr->lchild=p;
        p->rchild=prl;
        pr->rchild=prr;
        
        p->height=NodeHeight(p);
        pr->height=NodeHeight(pr);
        if(root==p)
        {
            root=pr;
        }
        return pr;
    }
    AVLnode *LRrotation(AVLnode *p)
    {
        AVLnode *pl,*plr;
        pl=p->lchild;
        plr=pl->rchild;

        p->lchild=plr->rchild;
        pl->rchild=plr->lchild;
        plr->rchild=p;
        plr->lchild=pl;
        p->height=NodeHeight(p);
        pl->height=NodeHeight(pl);
        plr->height=NodeHeight(plr);
        if(root==p)
        {
            root=pl;
        }
        return pl;
    }
    AVLnode *RLrotation(AVLnode *p)
    {
        AVLnode *pr,*prl;
        pr=p->rchild;
        prl=pr->lchild;

        pr->lchild=prl->rchild;
        p->lchild=prl->lchild;
        prl->lchild=p;
        prl->rchild=pr;
        
        pr->height=NodeHeight(pr);
        p->height=NodeHeight(p);
        prl->height=NodeHeight(prl);
        if(root==p)
        {
            root=pr;
        }
        return pr;
    }
    AVLnode *Delete(AVLnode *p,int key)
    {
        AVLnode *q;
        if(p==nullptr)
        {
            return nullptr;
        }
        if(p->lchild==nullptr &&p->rchild==nullptr)
        {
            if(root==p)
            {
                root =nullptr;
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
            if(NodeHeight(p->lchild)>NodeHeight(p->rchild))
            {
                q=Inpre(p->lchild);
                p->data=q->data;
                p->lchild=Delete(p->lchild,q->data);
            }
            else
            {
                q=Insucc(p->rchild);
                p->data=q->data;
                p->rchild=Delete(p->rchild,q->data);
            }

            p->height=NodeHeight(p);
            
            if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
            {
                return LLrotation(p);
            }
            else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
            {
                return LRrotation(p);
            }
            else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
            {
                return RRrotation(p);
            }
            else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
            {
                return RLrotation(p);
            }
            else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==0)
            {
                return LLrotation(p);
            }
            else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==0)
            {
                return RRrotation(p);
            }
        }
        return p;
    }
    AVLnode *Inpre(AVLnode *p)
    {
        while(p!=nullptr && p->rchild!=nullptr)
        {
            p=p->rchild;
        }
        return p;
    }
    AVLnode *Insucc(AVLnode *p)
    {
        while(p!=nullptr && p->lchild!=nullptr)
        {
            p=p->lchild;
        }
        return p;
    }
    void inorder(AVLnode *n)
    {
        if(n!=nullptr)
        {
            inorder(n->lchild);
            cout<<n->data<<" "<<flush;
            inorder(n->rchild);
        }
    }
};
int main(){
    // AVL t1,t2;
    // t1.root=t1.Rinsert(t1.root,30);
    // t1.Rinsert(t1.root,20);
    // t1.Rinsert(t1.root,10);
    // t1.inorder(t1.root);
    // cout<<endl;
    
    // t2.root=t2.Rinsert(t2.root,10);
    // t2.Rinsert(t2.root,20);
    // t2.Rinsert(t2.root,20);
    // t2.inorder(t2.root);
    // cout<<endl;
    AVL tree;
    tree.root=tree.Rinsert(tree.root,10);
    tree.Rinsert(tree.root,20);
    tree.Rinsert(tree.root,30);
    tree.Rinsert(tree.root,25);
    tree.Rinsert(tree.root,27);
    tree.Rinsert(tree.root,28);
    tree.Rinsert(tree.root,5);
    tree.inorder(tree.root);
    cout<<endl;
    tree.Delete(tree.root,28);
    tree.inorder(tree.root);
    cout<<endl;
     return 0;
}