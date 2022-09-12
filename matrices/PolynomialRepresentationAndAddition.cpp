
//WORKS WITHOUT OPERATOR OVERLOADING USES FRIEND FUNCTION SIMILAR TO THE CONCEPT OF SPARSE MATRIX ADDITION

#include <iostream>
#include <math.h>
using namespace std;
class term
{
public:
    int coeff;
    int exp;
};
class poly
{
public:
    int n;
    term *t;
    void CreatePoly(int);
    int EvaluatePoly(int);
    void PolyDisplay();
    friend poly *add(poly *, poly *);
};
void poly::CreatePoly(int num)
{
    n = num;
    t = new term[n];
    for (int i = 0; i < n; i++)
    {
        cout << "enter " << i + 1 << "st term" << endl;
        cin >> t[i].coeff >> t[i].exp;
    }
}
int poly::EvaluatePoly(int val)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + (t[i].coeff) * (pow(val, t[i].exp));
    }
    return sum;
}
void poly::PolyDisplay()
{
    for (int i = 0; i < n; i++)
    {
        cout << t[i].coeff << "x^" << t[i].exp << " + ";
    }
    cout << endl;
}
poly *add(poly *p1, poly *p2)
{
    poly *p3 = new poly;
    p3->t = new term[p1->n + p2->n];
    int i, j, k;
    i = j = k = 0;
    while (i < p1->n && j < p2->n)
    {
        if (p1->t[i].exp > p2->t[j].exp)
        {
            p3->t[k++] = p1->t[i++];
        }
        else if (p1->t[i].exp < p2->t[j].exp)
        {
            p3->t[k++] = p2->t[j++];
        }
        else
        {
            p3->t[k] = p1->t[i];
            p3->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
    }
    for (; i < p1->n; i++)
    {
        p3->t[k++] = p1->t[i++];
    }
    for (; j < p2->n; j++)
    {
        p3->t[k++] = p2->t[j++];
    }
    p3->n = k;
    return p3;
}
int main()
{
    poly P1;
    int term1;
    cout << "enter the terms in first polynomial " << endl;
    cin >> term1;
    P1.CreatePoly(term1);
    P1.PolyDisplay();
    cout << "--------------" << endl;
    poly P2;
    int term2;
    cout << "enter the terms in second polynomial " << endl;
    cin >> term2;
    P2.CreatePoly(term2);
    P2.PolyDisplay();
    cout << "---------------" << endl;
    poly *P3 = add(&P1, &P2);
    cout << "The sum of polynomial equation is " << endl;
    P3->PolyDisplay();
    // cout<<"Enter the value of X for which the polynomial should be evaluated "<<endl;
    // int x;
    // cin>>x;
    // cout<<"the result is "<<p.EvaluatePoly(x)<<endl;
    return 0;
}