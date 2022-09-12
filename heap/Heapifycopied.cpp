#include <iostream>

using namespace std;

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int Delete(int *A, int n)
{
    int val = A[0];
    A[0] = A[n];
    A[n] = val;
    int i = 0;
    int j = 2 * i + 1;

    while (j < n - 1)
    {
        if (j < n - 2 && A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j])
        {
            swap(A[i], A[j]);//USING A PREDEFINED FUNCTION swap;
            i = j;
            j = 2 * j + 1;
        }
        else
            break;
    }
    return val;
}
void Heapify(int A[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        int j = 2 * i + 1;
        while (j <= n - 1)
        { // changes
            if (j + 1 < n && A[j] < A[j + 1])
            { // changes
                j = j + 1;
            }
            if (A[i] < A[j])
            {
                //swap(A[i],A[j]);USING A PREDEFINED FUNCTION swap
                swap(A,i,j);
                i = j;
                j = 2 * i + 1;
            }
            else
            {
                break;
            }
        }
    }
}

template <class T>
void Print(T &vec, int n, string s)
{
    cout << s << ": [" << flush;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << flush;
        if (i < n - 1)
        {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int main()
{

    int A[] = {5, 10, 30, 20, 35, 40, 15};
    Print(A, sizeof(A) / sizeof(A[0]), "A");

    Heapify(A, sizeof(A) / sizeof(A[0]));
    Print(A, sizeof(A) / sizeof(A[0]), "Heapified A");
    cout<<"heap sort "<<endl;
    for(int i=6;i>1;i--)
    Delete(A,i);
    Print(A,sizeof(A)/sizeof A[0],"A");
    cout << endl;

    int B[] = {5, 10, 30, 20};
    Print(B, sizeof(B) / sizeof(B[0]), "B");

    Heapify(B, sizeof(B) / sizeof(B[0]));
    Print(B, sizeof(B) / sizeof(B[0]), "Heapified B");

    return 0;
}