// ARRAY ADT CHECKING IF ARRAY IS ALREADY SORTED OR NOT
// INSERTING ELEMENTS TO ALREADY SORTED ARRAY
// SHIFTING ALL THE NEGATIVE NUMBERS TO THE LEFT SIDE OF THE ARRAY
#include <iostream>
using namespace std;
class A
{
    int *p;
    int size;
    int length;

public:
    void create()
    {
        cout << "enter the size of array " << endl;
        cin >> size;
        p = new int[size];
    }
    void getele(int n)
    {
        length = n;
        cout << "enter number of elements in the array " << endl;
        for (int i = 0; i < length; i++)
        {
            cin >> p[i];
        }
    }
    int getlength()
    {
        return length;
    }
    void displayarr()
    {
        cout << "the array is " << endl;
        for (int i = 0; i < length; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    void swap(int &x, int &y)
    {
        y = x + y;
        x = y - x;
        y = y - x;
    }
    void InsertToSorted(int element)
    {
        if (length == size)
        {
            return;
        }
        int i = length - 1;
        while (i>=0 && p[i] > element)//if we are inserting the smallest element we need to make sure that the index should 
        //not go beyond zero thus i>=0
        {
            p[i + 1] = p[i];
            i--;
        }
        p[i + 1] = element;
    }
    int IsSorted()
    {
        for (int i = 0; i < length - 1; i++) // array[length]= no element ; array[length-1]=last element ;array[lenght -2]=2nd last element
        // here we are running the till second last element as we will compare it with last element by incrementing the value of
        // i in below given algorithm in case if we run loop till length-1 ie till last element
        // we will get an error as there will be no value to compare as i=length will have no value at i =length
        // when we increment value of i with one
        {
            if (p[i] > p[i + 1])
            {
                return -1;
            }
        }
        return 0;
    }
    void NegativeNumbersToleftSide()
    {
        int i = 0;
        int j = length - 1;
        while (i < j)
        {
            while (p[i] < 0) // I IS LOOKING FOR NEGATIVE NUMBERS IN THE ARRAY AS SOON AS IT GETS A +IVE NUMBER THE
            // ITERATION OF I IS NOT DONE AND THUS IT POINTS ON THE INDEX WITH +IVE VALUE
            {
                i++;
            }
            while (p[j] >= 0) // J IS LOOKING FOR NEGATIVE NUMBERS IN THE ARRAY AS SOON AS IT GETS A -VE VALUE THE
            // ITERATION OF J IS STOPPED THUS IT POINTS ON THE INDEX WITH THE NEGATIVE VALUE WAITING TO BE SWAPPED
            {
                j--;
            }
            if (i < j)
            {
                swap(p[i], p[j]);
            }
        }
    }
};
int main()
{
    A arr;
    arr.create();
    cout << "enter the number of elements you want to enter in the array " << endl;
    int ele;
    cin >> ele;
    arr.getele(ele);
    arr.displayarr();
    // arr.InsertToSorted(18);
    // arr.displayarr();
    // int res = arr.IsSorted();
    // if (res == -1)
    //     cout << "the array is not sorted " << endl;
    // else
    //     cout << "array is sorted " << endl;
    cout << "array after shifting all the negative numbers to left side " << endl;
    arr.NegativeNumbersToleftSide();
    arr.displayarr();
    return 0;
}
