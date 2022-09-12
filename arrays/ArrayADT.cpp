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
    //Utility functtion to find the index of any element in the array
    int linearSearch(int *arr,int ele)
    {
        int res=-1;
        for(int i=0;i<length;i++)
        {
            if(arr[i]==ele)
            {
                res=i;
                return res;
            }
        }
        return res;
    }
    // USED IN REVERSING THE ARRAY WITHOUT USING THE SECOND ARRAY
    void swap(int &x, int &y)
    {
        y = x + y;
        x = y - x;
        y = y - x;
    }
    void append(int);
    void insert(int, int);
    int del(int);
    void deletingSpecificElement(int ele);
    int get(int);
    void set(int, int);
    int max();
    int min();
    int sum();
    double average();
    void reverse();                          //reversing using one auxillary array
    void reverse2();                        //reversing without using auxillary array
    void NegativeOnLeftside();             //SWAPPING NEGATIVE NUMBERS ON THE LEFT SIDE
    void merge(int *g, int len);          //(ONLY AND ONLY FOR SORTED ARRAYS )
    void unionn(int *g, int len);        //(ONLY AND ONLY FOR SORTED ARRAYS )
    void intersection(int *g, int len); //INTERSECTION ONLY AND ONLY FOR SORTED ARRAY
    void difference(int *g, int len);  //DIFFERENCE ONLY AND ONLY FOR SORTED ARRAYS
    int CheckIfSorted();
};

// APPENDING ELEMENT IN THE ARRAY
void A::append(int element)
{
    if (length < size) // CHCECKING IF THE VALUE TO BE INSERTED IS NOT EXCEEDING THE LIMIT OF ARRAY
    {
        p[length] = element;
        length++;
    }
}

// INSERTING AT ANY INDEX
void A::insert(int index, int element)
{
    if (index >= 0 && index <= length) // CONDITION SHOULD BE CHECKED TILL INDEX LESS THAN EQUAL TO LENGTH BECAUSE THE THE USER MIGHT WANT TO INSERT ELEMENT
    // AT THE END
    {
        for (int i = length; i > index; i--) // THE LOOP SHOULD RUN TILL i GREATER THAN INDEX BECAUSE THE ELEMENT AT i-1 IS ALREADY BEING
        // SHIFTED IN BELOW CONDITION
        {
            p[i] = p[i - 1];
        }
        p[index] = element;
        length++;
    }
}

// DELETING A ELEMENT IN THE ARRAY WITH GIVEN INDEX
int A::del(int index)
{
    int x = p[index];
    if (index >= 0 && index < length) // CONDITION SHOULD BE CHECKED IF THE INDEX IS LESS THAN THE LENGTH OF THE ARRAY AS THERE IS NO ELEMENT
    // AT INDEX==LENGTH
    {
        for (int i = index; i < length - 1; i++) // LOOP SHOULD RUN TILL i<LENGTH-1 AS THERE IS NO ELEMENT AT i==LENGTH AND THE ELEMENT AND WHEN
            // i REACHES LENGTH-2 THE ELEMNENT AT LENGTH-1 WILL BE SHIFTED TO INDEX LENGTH-2 BY THE CONDITION GIVEN BELOW
            p[i] = p[i + 1];
        length--;
        return x;
    }
    return 0;
}

//DELETING A SPECIFIC ELEMENT FROM THE ARRAY
void A::deletingSpecificElement(int ele)
{
    if(linearSearch(p,ele)!=-1)
    {
        del(linearSearch(p,ele));
    }
    else
    {
        cout<<ele<<"cannot be deleted as it is not present in the array"<<endl;
    }
}

// GETTING ELEMENT AT THE GIVEN INDEX
int A::get(int index)
{
    if (index < length && index >= 0)
        return p[index];
    else
        return 0;
}

// SETTING ELEMENT AT GIVEN INDEX
void A::set(int ele, int index)
{
    if (index < length && index >= 0)
    {
        p[index] = ele;
    }
}

// FINDING LARGEST ELEMENT IN THE ARRAY
int A::max()
{
    int maxm = p[0];
    for (int i = 0; i < length; i++)
    {
        if (maxm < p[i])
        {
            maxm = p[i];
        }
    }
    return maxm;
}

// FINDING SMALLEST NUMBER IN THE ARRAY
int A::min()
{
    int minm = p[0];
    for (int i = 0; i < length; i++)
    {
        if (minm > p[i])
        {
            minm = p[i];
        }
    }
    return minm;
}

// FINDING THE SUM OF ELEMENTS IN THE ARRAY
int A::sum()
{
    int s = 0;
    for (int i = 0; i < length; i++)
    {
        s += p[i];
    }
    return s;
}

// FINDING THE AVERAGE OF SUM OF ELEMENTS IN THE ARRAY
double A::average()
{
    double ss = sum();
    double avg = ss / length;
    return avg;
}

// REVERSING THE ARRAY BY USING AUXILLARY ARRAY
void A::reverse()
{
    int *p1;
    int j;
    p1 = new int[length];
    for (int i = length - 1, j = 0; i >= 0; i--, j++)
    {
        p1[j] = p[i];
    }
    for (int i = 0; i < length; i++)
    {
        p[i] = p1[i];
    }
    displayarr();
}

// REVERSING THE ARRAY WITHOUT USING THE SECOND ARRAY (AUXILLARY ARRAY)
void A::reverse2()
{
    int j;
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        swap(p[i], p[j]);
    }
    displayarr();
}

// MERGING THE ARRAYS
void A::merge(int *g, int len)
{
    int *t;
    int tl = length + len;
    t = new int[tl];
    int i, j, k;
    i = j = k = 0;
    while (i < length && j < len)
    {
        if (p[i] < g[j])
        {
            t[k++] = p[i++];
        }
        else
        {
            t[k++] = g[j++];
        }
    }
    for (; i < length; i++)
    {
        t[k++] = p[i];
    }
    for (; j < len; j++)
    {
        t[k++] = g[j];
    }
    cout << "merged arrays is " << endl;
    for (int a = 0; a < tl; a++)
    {
        cout << t[a] << " ";
    }
    cout << endl;
}

// UNION OF THE ARRAYS (ONLY AND ONLY FOR SORTED ARRAYS )
void A::unionn(int *g, int len)
{
    int *t;
    int tl = length + len;
    t = new int[tl];
    int i, j, k;
    i = j = k = 0;
    while (i < length && j < len)
    {
        if (p[i] < g[j])
        {
            t[k++] = p[i++];
        }
        else if (g[j] < p[i])
        {
            t[k++] = g[j++];
        }
        else
        {
            t[k++] = p[i++];
            j++;
        }
    }
    for (; i < length; i++)
    {
        t[k++] = p[i];
    }
    for (; j < len; j++)
    {
        t[k++] = g[j];
    }
    cout << "union of array is " << endl;
    for (int a = 0; a < k; a++)
    {
        cout << t[a] << " ";
    }
    cout << endl;
}

void A::intersection(int *g, int len)
{
    int *t;
    int tl = length + len;
    t = new int[tl];
    int i, j, k;
    i = j = k = 0;
    while (i < length && j < len)
    {
        if (p[i] < g[j])
        {
            i++;
        }
        else if (g[j] < p[i])
        {
            j++;
        }
        else if (g[j] == p[i])
        {
            t[k++] = p[i++];
            j++;
        }
    }
    cout << "intersection of array is " << endl;
    for (int a = 0; a < k; a++)
    {
        cout << t[a] << " ";
    }
    cout << endl;
}

// DIFFERENCE OF TWO ARRAYS (ONLY AND ONLY FOR SORTED ARRAYS)
void A::difference(int *g, int len)
{
    int *t;
    int tl = length + len;
    t = new int[tl];
    int i, j, k;
    i = j = k = 0;
    while (i < length && j < len)
    {
        if (p[i] < g[j])
        {
            t[k++] = p[i++];
        }
        else if (g[j] < p[i])
        {
            j++;
        }
        else if (p[i] == g[j])
        {
            i++;
            j++;
        }
    }
    for (; i < length; i++)
    {
        t[k++] = p[i];
    }
    cout << "difference of array is " << endl;
    for (int a = 0; a < k; a++)
    {
        cout << t[a] << " ";
    }
    cout << endl;
}

void A::NegativeOnLeftside()
{
    int i = 0;           // i looks for positive numbers
    int j = length - 1; // j looks for negative numbers
    while (i < j)
    {
        while (p[i] < 0)
        {
            i++;
        }
        while (p[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(p[i], p[j]);
        }
    }
    for (int x = 0; x < length; x++)
    {
        cout << p[x] << " ";
    }
    cout << endl;
}

// Check if the array is sorted or not
int A::CheckIfSorted()
{
    for (int i = 0; i < length - 1; i++)
    {
        if (p[i] > p[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    A arr;
    int e;
    arr.create();
    cout << "enter the number of elements you want to insert in the array " << endl;
    cin >> e;
    arr.getele(e);
    arr.displayarr();
    /*cout << "length of array is " << arr.getlength() << endl;
    arr.append(99);
    arr.displayarr();
    cout << "length of array is " << arr.getlength() << endl;
    arr.insert(4, 999);
    arr.displayarr();
    cout << "length of array is " << arr.getlength() << endl;
    cout<<"the element deleted is "<<arr.del(4)<<endl;
    arr.displayarr();
    cout << "length of array is " << arr.getlength() << endl;*/
    // cout << "element at index 3 is " << arr.get(3) << endl;
    // arr.displayarr();
    // arr.set(999, 6);
    // arr.displayarr();
    // cout << "the largest number in the array is " << arr.max() << endl;
    // cout << "the smallest number in the array is " << arr.min() << endl;
    // cout << "sum of the elements of the array is " << arr.sum() << endl;
    // cout << "the average of the sum of the elements of the array is " << arr.average() << endl;
    // arr.reverse2();
    // int B[5] = {3,6,7,15,20};
    // arr.merge(B, 5);
    // arr.unionn(B,5);
    // arr.intersection(B,5);
    // arr.difference(B,5);
    // arr.NegativeOnLeftside();
    // int res2 =arr.CheckIfSorted();
    // if (res2==0)
    // {
    //     cout<<"array is unsorted "<<endl;
    // }
    // else{
    //     cout<<"array is sorted "<<endl;
    // }
    int elementToBeDeleted;
    cout<<"enter the element that should be deleted "<<endl;
    cin>>elementToBeDeleted;
    arr.deletingSpecificElement(elementToBeDeleted);
    arr.displayarr();
    return 0;
}