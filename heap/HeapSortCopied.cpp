#include <iostream>
using namespace std;
void Swap(int &a ,int &b)
{
    b=a+b;
    a=b-a;
    b=b-a;
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
            Swap(A[i], A[j]);
            //swap(A[i],A[j]);//using a predefined function swap 
            i = j;
            j = 2 * j + 1;
        }
        else
            break;
    }
    return val;
}
void insert(int *A, int n)
{
    int i = n;
    int temp = A[i];
    while (i > 0 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}
int main()
{
    int A[] = {14, 15, 5, 20, 30, 8, 40};
    int i;
    for (i = 1; i < 7; i++)
        insert(A, i);
    for (int i = 6; i > 1; i--)
        Delete(A, i);
    for (int i = 0; i < 7; i++)
        cout << A[i] << " ";
    return 0;
}
