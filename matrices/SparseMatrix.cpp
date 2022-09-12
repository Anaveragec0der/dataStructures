#include<iostream>
using namespace std;
class Elements
{
    public:
    int i,j,x;
};
class Sparse
{
    int m,n,num;
    Elements *ele;
    public:
    void create()
    {
        int i;
        cout<<"enter the dimensions of sparse matrix"<<endl;
        cin>>m>>n;
        cout<<"enter number of non zero elements"<<endl;
        cin>>num;
        ele=new Elements[num];
        for(i=0;i<num;i++)
        {
            cout<<"enter the index and the element "<<endl;
            cin>>ele[i].i>>ele[i].j>>ele[i].x;
        }
    }
    void display()
    {
        int k=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==ele[k].i && j==ele[k].j)//CHECKING WHAT INDEXES DOES THE COORDINATE LIST CONTAINS 
                {
                    cout<<ele[k++].x<<" ";
                }
                else
                {
                    cout<<"0"<<" ";
                }
            }
            cout<<endl;
        }
    }
};
int main(){
    Sparse s;
    s.create();
    s.display();
     return 0;
}