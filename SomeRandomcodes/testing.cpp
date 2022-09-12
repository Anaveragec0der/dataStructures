// THIS IS TESTING FOR WHAT HAPPENS IF WE ARE TRYING TO INSERT ELEMENT IN ALREADY FILLED ARRAY(EXPECTING ARRAY INDEX OUT OF BOUND ERROR)




//THE ELEMENTS ARE BEING INSERTED IN THE ARRAY DESPITE THEM EXCEEDING THE LIMIT OF THE ARRAY ?
//THE NO ARRAY OUT OF INDEX ERROR  
//REASON NOT KNOWN YET ????????? 

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
    void insert(int index, int element)
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
};


int main(){
    A arr;
    arr.create();
    cout<<"enter the number of elements you want to insert in the array "<<endl;
    int ele;
    cin>>ele;
    arr.getele(ele);
    cout<<"length of array is "<<arr.getlength()<<endl;
    arr.displayarr();
    arr.insert(2,999);
    arr.displayarr();
    cout<<"length of array is "<<arr.getlength()<<endl;
       
     return 0;
}