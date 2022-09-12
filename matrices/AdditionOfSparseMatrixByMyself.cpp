#include<iostream>
using namespace std;
class element 
{
    public:
    int i;
    int j;
    int x;
};
class sparse
{
    public:
    int m;
    int n;
    int num;
    element *e;
    void create(int r,int c, int nzero);
    void display();
    friend sparse * add(sparse *,sparse *);
};
void sparse::create(int r,int c,int nzero)
{
    m=r;
    n=c;
    num=nzero;
    e=new element[num];
    cout<<"enter the index of non zero elements and the non zero element "<<endl;
    for(int i=0;i<num;i++)
    {
        cin>>e[i].i>>e[i].j>>e[i].x;
    }
}
void sparse::display()
{
    int k=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==e[k].i && j==e[k].j)
            {
                cout<<e[k++].x<<" ";
            }
            else
            {
                cout<<"0"<<" ";
            }
        }
        cout<<endl;
    }
}
sparse *add(sparse *s1,sparse *s2)
{
    int i,j,k;
    i=j=k=0;
    sparse *sum;
    sum =new sparse;
    sum->m=s1->m;
    sum->n=s1->n;
    sum->e=new element[s1->num+s2->num];
    while(i<s1->num && j<s2->num)
    {
    if(s1->e[i].i<s2->e[j].i)
    {
        sum->e[k++]=s1->e[i++];
    }
    else if(s1->e[i].i>s2->e[j].i)
    {
        sum->e[k++]=s2->e[j++];
    }
    else
    {
        if(s1->e[i].j<s2->e[j].j)
        {
            sum->e[k++]=s1->e[i++];
        }
        else if(s1->e[i].j>s2->e[j].j)
        {
            sum->e[k++]=s2->e[j++];
        }
        else
        {
            sum->e[k]=s1->e[i];
            sum->e[k++].x=s1->e[i++].x+s2->e[j++].x;
        }
    }
    }
    for(;i<s1->num;i++)
    {
        sum->e[k++]=s1->e[i++];
    }
    for(;j<s2->num;j++)
    {
        sum->e[k++]=s1->e[j++];
    }
    sum->num=k;
    return sum;
}

int main(){
    sparse s1;
    cout<<"enter the number of rows columns and non zero elements in first sparse matrix "<<endl;
    int r1,c1,nz1;
    cin>>r1>>c1>>nz1;
    s1.create(r1,c1,nz1);
    s1.display();
    cout<<endl;
    sparse s2;
    cout<<"enter the number of rows columns and non zero elements in second sparse matrix "<<endl;
    int r2,c2,nz2;
    cin>>r2>>c2>>nz2;
    s2.create(r2,c2,nz2);
    s2.display();
    cout<<endl;
    if(r1!=r2 || c1!=c2)
    {
        cout<<"the matrices cannot not be added "<<endl;
    }
    else
    {
    sparse *res=add(&s1,&s2);
    res->display();
    }
     return 0;
}