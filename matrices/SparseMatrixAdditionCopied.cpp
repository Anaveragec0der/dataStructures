#include <stdio.h>

#include <iostream>
using namespace std;
#include <stdlib.h>

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
    int m;
    int n;
    int num;
    Element *e;

public:
    Sparse()
    {
        this->m = 3;
        this->n = 3;
        this->num = 3;
        e = new Element[this->num];
    }
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        e = new Element[num];
    }
    ~Sparse() { delete[] e; }
    void create();
    void Display();
    friend Sparse *add(Sparse *s1, Sparse *s2);
};

void Sparse::create()
{
    for (int i = 0; i < num; i++)
    {
        cin >> e[i].i;
        cin >> e[i].j;
        cin >> e[i].x;
    }
}
void Sparse::Display()
{
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == e[k].i && j == e[k].j)
            {
                cout << e[k].x << " ";
                k++;
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

Sparse *add(Sparse *s1, Sparse *s2)
{
    int i, j, k;
    i = j = k = 0;
    Sparse *sum;
    sum = new Sparse;//OBJECT ITSELF IS A POINTER AND THATS WHY WHEN WE WRITE RETURN TYPE AS CLASS NAME * IT BECOMES POINTER OF 
    //POINTER AND THUS A POINTER OF POINTER DOES NOT REQUIRE & FOR RETURNING ITS ADDRESS
    sum->m = s1->m;
    sum->n = s1->n;
    sum->e = new Element[s1->num + s2->num];

    while (i < s1->num && j < s2->num)
    {
        if (s1->e[i].i < s2->e[j].i)
        {
            sum->e[k++] = s1->e[i++];
        }
        else if (s1->e[i].i > s2->e[j].i)
        {
            sum->e[k++] = s2->e[j++];
        }
        else
        {
            if (s1->e[i].j < s2->e[j].j)
            {
                sum->e[k++] = s1->e[i++];
            }
            else if (s1->e[i].j > s2->e[j].j)
            {
                sum->e[k++] = s2->e[j++];
            }
            else
            {
                sum->e[k] = s1->e[i]; // this line was missing
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    for (; i < s1->num; i++)
    {
        sum->e[k++] = s1->e[i++];
    }
    for (; j < s2->num; j++)
    {
        sum->e[k++] = s2->e[j++];
    }
    sum->num = k;
    return sum;
}

int main()
{
    Sparse s1(5, 5, 5);
    Sparse s2(5, 5, 5);
    s1.create();
    s2.create();
    cout << "\n";
    s1.Display();
    cout << "\n";
    s2.Display();
    cout << "\n";
    Sparse *answer = add(&s1, &s2);
    answer->Display();
    return 0;
}