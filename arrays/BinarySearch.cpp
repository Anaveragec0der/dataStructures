#include <iostream>
using namespace std;
int BinarySearch(int *p, int l, int h, int key)
{
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (p[mid] == key)
        {
            return mid;
        }
        else if (key < p[mid])
        {
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return -1;
}
int recBinarySearch(int *p, int l, int h, int key)
{
    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (p[mid] == key)
        {
            return mid;
        }
        else if (key > p[mid])
        {
            return recBinarySearch(p, mid + 1, h, key);
        }
        else
        {
            return recBinarySearch(p, l, mid - 1, key);
        }
    }
    return -1;
}
int main()
{
    int arr[15] = {4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43};
    int res = recBinarySearch(arr, 0, 14, 15);
    cout << "the element is found at index " << res << endl;
    return 0;
}