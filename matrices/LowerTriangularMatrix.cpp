#include <iostream>
using namespace std;
class LtMatrix
{
    int *A;
    int n;

public:
    LtMatrix(int);
    void set(int, int, int);
    int get(int, int);
    void print();
    ~LtMatrix();
};
LtMatrix::LtMatrix(int i)
{
    n = i;
    A = new int[(n*(n+1))/2];
}
void LtMatrix::set(int i, int j, int ele)
{
    if (j<=i)
    {
        A[(i-1)*i/2+j-1] = ele;
    }
    //print(i);
    // for(int i=0;i<j;i++)
    // {
    //     cout<<A[i]<<" ";
    // }
    // cout<<endl;
}
int LtMatrix::get(int i, int j)
{
    
    if (j<=i)
    {
        return (A[(i-1)*i/2+j-1]);
    }
    else
    {
        return 0;
    }
}
void LtMatrix::print()
{
    for (int i = 1; i <=n; i++)//loop begins from 1 as the number the formula for elements has i-1 
    //if we start from zero the first iteration will result in index i & j=-1
    {
        for(int j=1;j<=n;j++)
        {
            if(j<=i)
            {
                cout<<A[(i-1)*i/2+j-1]<<"  ";
            }
            else
            {
                cout<<'0'<<"  ";
            }
        }
        cout << endl;
    }

}
LtMatrix::~LtMatrix()
{
    delete []A;
}
int main()
{
    int r, c;
    cout << "enter the number rows or columns in lower triangular matrix" << endl;
    cin >> r;
    c = r;
    int e;

    LtMatrix Lt(r);
    cout <<"enter the elements in the lower triangular matrix"<< endl;
    for (int i = 1; i <=r; i++)
    {
        for(int j=1;j<=c;j++)
        {

        cin >> e;
        Lt.set(i , j , e);
        }
    cout<<endl;
    }
    Lt.print();
    cout << "enter the row and column number from where you want to get the element from lower triangular matrix " << endl;
    int ro, co;
    cin >> ro >> co;
    if (ro > r || co > c)
    {
        cout << "no such index exists " << endl;
    }
    else
    {
        cout << "the element is " << Lt.get(ro, co) << endl;
    }
    return 0;
}