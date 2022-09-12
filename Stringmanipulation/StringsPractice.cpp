#include <iostream>
#include <string>
#include<cstring>
using namespace std;

int len(char *s)
{
    int length = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

char *ToUpper(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
    }
    return s;
}

char *ToLower(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }
    return s;
}

void VowelsAndConsonants(char *s)
{
    int v, c;
    v = c = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
        {
            v++;
        }
        else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            c++;
        }
    }
}

int ValidateString(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= 48 && s[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}

void ReverseString(char *s)
{
    char temp;
    int i, j;
    for (i = 0; s[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (int j = 0; j < i; j++, i--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    cout << "the string is" << endl;
   char *temp1= ToLower(s);
   cout<<temp1<<endl;

}
int PalindromeString(char *s)
{
    int i, j;
    for (i = 0; s[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; j < i; j++, i--)
    {
        if (s[j] != s[i])
        {
            return 0;
        }
    }
    return 1;
}

void Comparestring(char *s, char *s1) // first string compared to second string
{
    int i, j;
    for (i = 0, j = 0; s[i] != '\0' && s1[j] != '\0'; i++, j++)
    {
        if (s[i] != s1[j])
        {
            break;
        }
    }
    if (s[i] == s1[j])
    {
        cout << "equal string " << endl;
    }
    else if (s[i] < s1[j])
    {
        cout << "smaller string " << endl;
    }
    else
    {
        cout << "larger string " << endl;
    }
}
void FindDuplicates(char *s)
{
    int i, j;
    int *H = new int[26]{0};
    for (i = 0; s[i] != 0; i++)
    {
        H[s[i] - 'A'] += 1;
    }
    for (j = 0; j < 26; j++)
    {
        if (H[j] > 1)
        {
            cout << "the word " << char(j + 'A') << " is repeated " << H[j] << " times" << endl;
        }
    }
}

void StringsAnagram(char *s, char *s1)
{
    int i, j;
    int l1 = len(s);
    int l2 = len(s1);
    int *H = new int[26]{0};
    if (l1 != l2)
    {
        cout << "strings are not anagram" << endl;
    }
    else
    {
        for (i = 0; s[i] != 0; i++)
        {
            H[s[i] - 'A'] += 1;
        }
        for (j = 0; s1[j] != 0; j++)
        {
            H[s1[j] - 'A'] -= 1;
            if (H[s1[j] - 'A'] < 0)
            {
                cout << "strings are not anagram" << endl;
                break;
            }
        }
        if (s1[j] == '\0')
        {
            cout << "strings are anagram" << endl;
        }
    }
}
int main()
{
    string str,str1;
    cout<<"enter first string "<<endl;
    getline(cin,str);
    cout<<"enter second string "<<endl;
    getline(cin,str1);
    int len,len1;
    len=len1=0;
    char s[len+1];
    char s1[len1+1];
    strcpy(s,str.c_str());
    strcpy(s1,str1.c_str());
    char *us;
    us = ToUpper(s);
    char *us1 = ToUpper(s1);
    ReverseString(us);
    if (PalindromeString(us))
    {
        cout << "string is palindrome " << endl;
    }
    else
    {
        cout << "string is not palindrome " << endl;
    }
    if (ValidateString(us))
    {
        cout << "valid string" << endl;
    }
    else
    {
        cout << "Invalid string" << endl;
    }
    Comparestring(us, us1); // FIRST STRING COMPARED TO SECOND STRING
    FindDuplicates(us);
    StringsAnagram(us, us1);
    return 0;
}