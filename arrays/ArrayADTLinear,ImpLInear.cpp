#include <iostream>
using namespace std;
class LsIls //LINEAR SEARCH ,IMPROVED LINEAR SEARCH
{
    int *p;
    int length;

public:
    void getarray(int len)
    {
        length=len;
        p = new int[length];
        cout << "enter elements in the array " << endl;
        for (int i = 0; i < length; i++)
        {
            cin >> p[i];
        }
        displayarr();
    }
    void displayarr()
    {
        cout<<"the array is "<<endl;
        for (int i = 0; i < length; i++)
        {
            cout<<p[i] <<" ";
        }
        cout << endl;
    }
    int LS(int elem)//LINEAR SEARCH ;
    {
        for (int i = 0; i < length; i++)
        {
            if (p[i] == elem)
            {
                return i;
            }
        }
        return -1;
    }
    void swap(int &x, int &y)
    {
        y = x + y;
        x = y - x;
        y = y - x;
    }
    int ILS(int elem)//IMPROVED LINEAR SEARCH 
    {
        for (int i = 0; i < length; i++)
        {
            if (p[i] == elem)
            {
               // swap(p[i], p[i - 1]); //TRANSPOSITIONING METHOD
                 swap(p[i],p[0]);//MOVE TO FRONT/HEAD METHOD
                displayarr();
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    LsIls ar;
    int el;
    cout << "enter the number of elements you want in the array " << endl;
    cin >> el;
    ar.getarray(el);
    cout << "enter the element you want to search in the array " << endl;
    int sr;
    cin >> sr;
    //int res=ar.LS(sr);//INVOKING LINEAR SEARCH 
    int res=ar.ILS(sr);//INVOKING IMPROVED LINEAR SEARCH 
    if (res != -1)
    {
        cout<<"the element found at index "<<res<<endl;
       // ar.displayarr();
    }
    else
    cout<<"the elemnet is not found in the array "<<endl;
    return 0;
}