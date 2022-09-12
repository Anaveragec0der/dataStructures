//NOTE-----> THE CODE DOES N0T CONTAINS TRIDIAGONAL MATRIX AND TOPELITZ MATRIX


#include <iostream>
using namespace std;
class AllMatrix
{
public:
    int *A, n;

    void inD(int r)
    {
        n = r;
        A = new int[r];
    }
    void inLt(int r)
    {
        n = r;
        A = new int[r * (r + 1) / 2];
    }
    void inUt(int r)
    {
        n = r;
        A = new int[r * (r + 1) / 2];
    }
    void inSym(int r)
    {
        n = r;
        A = new int[r * (r + 1) / 2];
    }
    void setD(int, int, int); // WORKS
    void setLt(int, int, int);// WORKS
    void setUt(int, int, int);// WORKS
    void setSym(int, int, int);// WORKS
    int getD(int, int);// WORKS
    void PrintD();// WORKS
    int getLt(int, int);// WORKS
    void PrintLt();// WORKS
    int getUt(int, int);// WORKS
    void PrintUt();// WORKS
    int getSym(int, int);// WORKS
    void PrintSym();// WORKS
};
void AllMatrix::setD(int i, int j, int x)
{
    if (i == j)
    {
        A[i - 1] = x;
    }
}
void AllMatrix::setLt(int i, int j, int x) // ROW MAJOR APPROACH
{
    if (j <= i)
    {
        A[i * (i - 1) / 2 + (j - 1)] = x;
    }
}
void AllMatrix::setUt(int i, int j, int x) // COLUMN MAJOR APPROACH
{
    if (i <= j)
    {
        A[j * (j - 1) / 2 + (i - 1)] = x;
    }
}
void AllMatrix::setSym(int i, int j, int x)
{
    if (i >= j)
    {
        A[i * (i - 1) / 2 + (j - 1)] = x;
    }
}
int AllMatrix::getD(int i, int j)
{
    if (i == j)
    {
        return A[i - 1];
    }
    else
        return 0;
}
int AllMatrix::getLt(int i, int j) // ROW MAJOR APPROACH
{
    if (j <= i)
    {
        return (A[i * (i - 1) / 2 + (j - 1)]);
    }
    else
        return 0;
}
int AllMatrix::getUt(int i, int j) // COLUMN MAJOR APPROACH
{
    if (i <= j)
    {
        return (A[j * (j - 1) / 2 + (i - 1)]);
    }
    else
        return 0;
}
int AllMatrix::getSym(int i, int j)
{
    if (j <= i)
    {
        return (A[i * (i - 1) / 2 + (j - 1)]);
    }
    else
    {
        return (A[j * (j - 1) / 2 + (i - 1)]);
    }
}
void AllMatrix::PrintD()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                cout << A[i - 1] << " ";
            }
            else
            {
                cout << "0"
                     << " ";
            }
        }
        cout << endl;
    }
}
void AllMatrix::PrintLt()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= i)
            {
                cout << A[i * (i - 1) / 2 + j - 1] << " ";
            }
            else
            {
                cout << "0"
                     << " ";
            }
        }
        cout << endl;
    }
}
void AllMatrix::PrintUt()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i <= j)
            {
                cout << A[j * (j - 1) / 2 + i - 1] << " ";
            }
            else
            {
                cout << "0"
                     << " ";
            }
        }
        cout << endl;
    }
}
void AllMatrix::PrintSym()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= i)
            {
                cout << A[i * (i - 1) / 2 + j - 1] << " ";
            }
            else
            {
                cout << A[(j * (j - 1) / 2 + i - 1)] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    AllMatrix Am;
    Am.inSym(5);
    int el;

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> el;
            Am.setSym(i, j, el);
        }
    }
    Am.PrintSym();
    cout << Am.getSym(3, 4) << endl;
    //  cout<<"matrix is stored as "<<endl;
    // for(int i=0;i<4*(4+1)/2;i++)
    // {
    //     cout<<Am.A[i]<<" ";
    // }
    // Am.inUt(4);
    // for(int i=1;i<=4;i++)
    // {
    //     for(int j=1;j<=4;j++)
    //     {
    //         cin>>el;
    //         Am.setUt(i,j,el);
    //     }
    // }
    // Am.PrintUt();

    return 0;
}