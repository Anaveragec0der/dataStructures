//NOTE--------------> THIS IS A COPIED CODE FROM THE QNA SECTION OF LETS CODE POLYNOMIAL REPRESENTATION 

#include <iostream>

using namespace std;

class Term
{
public:
    int coeff;
    int exp;
};

class Poly
{
private:
    int n;
    Term *terms;

public:
    Poly() {}
    Poly(int n)
    {
        this->n = n;
        terms = new Term[n];
    }

    void create();
    void Display();
    Poly *add(Poly &p2);
    ~Poly()
    {
        delete[] terms;
    }
};
void Poly::create()
{

    cout << "Enter Terms " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> terms[i].coeff >> terms[i].exp;
    }
}

void Poly::Display()
{
    for (int i = 0; i < n; i++)
    {
        cout << terms[i].coeff << "x" << terms[i].exp << " + ";
    }
}

Poly *Poly ::add(Poly &p2)
{
    int i, j, k;
    Poly *sum = new Poly(n + p2.n);

    // sum->terms = new Term[(n+p2.n)*sizeof(Term)];
    i = j = k = 0;

    while (i < n && j < p2.n)
    {
        if (terms[i].exp > p2.terms[j].exp)
        {
            sum->terms[k++] = terms[i++];
        }
        else if (terms[i].exp < p2.terms[j].exp)

            sum->terms[k++] = p2.terms[j++];
        else
        {
            sum->terms[k].exp = terms[i].exp;

            sum->terms[k++].coeff = terms[i++].coeff + p2.terms[j++].coeff;
        }
    }
    for (; i < n; i++)
    {
        sum->terms[k++] = terms[i];
    }
    for (; j < p2.n; j++)
    {
        sum->terms[k++] = p2.terms[j];
    }

    sum->n = k;
    return sum;
}

int main()
{
    int n, m;
    cout << "Enter no.of terms for 1st Polynomial" << endl;
    cin >> n;
    Poly p1(n);
    p1.create();
    cout << "Enter no.of terms for 2nd Polynomial" << endl;
    cin >> m;
    Poly p2(m);
    p2.create();
    Poly *p3;

    p3 = p1.add(p2);
    cout << endl;
    p1.Display();
    cout << "-------" << endl;
    p2.Display();
    cout << " ------------" << endl;
    p3->Display();
    return 0;
}
