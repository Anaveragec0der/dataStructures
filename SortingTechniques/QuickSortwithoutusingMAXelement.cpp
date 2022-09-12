#include <iostream>
#include <string>
using namespace std;
int partition(int *a, int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (a[i] <= pivot && i<h);
        do
        {
            j--;
        } while (a[j] > pivot);
 
        if (i < j)
            swap(a[i], a[j]);
 
    } while (i < j);
 
    swap(a[l], a[j]);
 
    return j;
}
void quick(int *a, int l, int h)
{
    if (l < h)
    {
        int j = partition(a, l, h);
        quick(a, l, j);
        quick(a, j + 1, h);
    }
}
int main()
{
    int a[] = {3, 5, 12, 7, 10, 2, 15};
    quick(a, 0, 6);
    for (size_t i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}