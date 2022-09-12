#include <iostream>
using namespace std;
class DiagonalMatrix
{
    int *A;
    int n;

public:
    DiagonalMatrix(int);
    void set(int, int, int);
    int get(int, int);
    void print();
    ~DiagonalMatrix();
};
DiagonalMatrix::DiagonalMatrix(int i)
{
    n = i;
    A = new int[n];
}
void DiagonalMatrix::set(int i, int j, int ele)
{
    if (i == j)
    {
        A[i - 1] = ele;
    }
    //print(i);
}
int DiagonalMatrix::get(int i, int j)
{
    
    if (i == j)
    {
        return A[i - 1];
    }
    else
    {
        return 0;
    }
}
void DiagonalMatrix::print()
{
    for (int i = 0; i <n; i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                cout<<A[i]<<"  ";
            }
            else
            {
                cout<<'0'<<"  ";
            }
        }
        cout << endl;
    }

}
DiagonalMatrix::~DiagonalMatrix()
{
    delete []A;
}
int main()
{
    int r, c;
    cout << "enter the number rows or columns in a diagonal matrix" << endl;
    cin >> r;
    c = r;
    int j = 0;
    DiagonalMatrix D(r);
    cout << "enter the elements in primary diagonal" << endl;
    for (int i = 0; i < r; i++)
    {

        int e;
        cout << "enter " << i + 1 << "," << j + 1 << " element" << endl;
        cin >> e;
        D.set(i + 1, i + 1, e);
        j++;
    }
    D.print();
    cout << "enter the row and column number from where you want to get the element from diagonal matrix " << endl;
    int ro, co;
    cin >> ro >> co;
    if (ro > r || co > c)
    {
        cout << "no such index exists " << endl;
    }
    else
    {
        cout << "the element is" << D.get(ro, co) << endl;
    }
    return 0;
}