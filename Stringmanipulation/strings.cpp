#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
// CHECKING IF THE STRING DOES NOT HAVE ANY SPECIAL CHARACTERS
int valid(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 48 && s[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}
// REVERSING A STRING
void reversestr(char *p)
{
    char t;
    int j;
    for (j = 0; p[j] != '\0'; j++)
    {
    }
    j = j - 1; // For making j point on character at last index
    for (int i = 0; i < j; i++, j--)
    {
        t = p[j];
        p[j] = p[i];
        p[i] = t;
    }
    cout << "the reversed string is " << p << endl;
}

// comparing the strings
void compare(char *s, char *s1)
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
        cout << "equal strings " << endl;
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

// CHCEKING IF STRING IS PALINDROME OR NOT
int palindrome(char *s)
{
    int i, j;
    for (j = 0; s[j] != '\0'; j++)
    {
    };
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            return 0;
        }
    }
    return 1;
}

// CHECKING FOR DUPLICATE ELEMENTS
void CheckForDuplicates(char *s)
{
    int *alpha = new int[26]{0};
    for (int i = 0; s[i] != '\0'; i++)
    {
        alpha[s[i] - 97] += 1;
    }
    for (int j = 0; j < 26; j++)
    {
        if (alpha[j] > 1)
        {
            cout << "alphabet " << char(j + 97) << " is repeated " << alpha[j] << " times " << endl;
        }
    }
}
// FOR FINDING LENGTH OF STRING
int FindLengthOfString(char *st)
{
    int len = 0;
    for (int i = 0; st[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

// CHECKING IF THE STRING IS ANAGRAM (THE STRING CONTAINS SAME ALPHABETS )
//(NOTE----> STRING SHOULD BE EITHER IN LOWER OR UPPER CASE THIS FUNCTION WORKS IF STRING IS IN LOWER CASE)
void CheckingAnagram(char *s1, char *s2)
{
    int l1, l2;
    l1 = l2 = 0;
    l1 = FindLengthOfString(s1);
    l2 = FindLengthOfString(s2);
    int i = 0;
    int j = 0;
    int *alpha = new int[26]{0};
    if (l1 != l2)
    {
        cout << "strings are not anagram" << endl;
    }
    else
    {

        for (i = 0; s1[i] != '\0'; i++)
        {
            alpha[s1[i] - 97] += 1;
        }
        for (j = 0; s2[j] != '\0'; j++)
        {
            alpha[s2[j] - 97] -= 1;
            if (alpha[s2[j] - 97] < 0)
            {
                cout << "not anagram " << endl;
                break;
            }
        }
        if (s2[j] == '\0')
        {
            cout << "strings are anagram " << endl;
        }
    }
}

// FINDING ALL POSSIBLE COMBINATIONS OF A GIVEN STRING
void perm(char *s, int k)
{
    int flag[10] = {0};
    char res[10];
    int i;
    if (s[k] == '\0')
    {
        res[k] = '\0';
        cout << res << endl;
    }
    else
    {
        for (i = 0; s[i] != '\0'; i++)
        {
            if (flag[i] == 0)
            {
                res[k] = s[i];
                flag[i] = 1;
                perm(s, k + 1);
                flag[i] = 0;
            }
        }
    }
}

int main()
{
    // char str[]="WeLcOme";
    char str1[] = "Hello How Are You";
    char str2[] = "Anil123";
    // string str3="hello how are you";
    //  for(int i=0;str[i]!='\0';i++)//CONEVRTING LOWER TO UPPER AND UPPER TO LOWER CASE
    //  {
    //      if(str[i]>='A' && str[i]<='Z')
    //      {
    //          str[i]=str[i]+32;
    //      }
    //      else if (str[i]>='a' && str[i]<='z')
    //      {
    //          str[i]-=32;
    //
    //      }
    //      }
    int v, c;
    v = c = 0;
    for (int i = 0; str1[i] != '\0'; i++) // CHECKING FOR VOWELS AND CONSONANTS

    {
        if (str1[i] == 'a' || str1[i] == 'A' || str1[i] == 'e' || str1[i] == 'E' || str1[i] == 'i' || str1[i] == 'I' || str1[i] == 'O' || str1[i] == 'o' || str1[i] == 'u' || str1[i] == 'U')
        {
            v++;
        }
        else if ((str1[i] >= 'A' && str1[i] <= 'Z') || (str1[i] >= 'a' && str1[i] <= 'z'))
        {
            c++;
        }
    }
    cout << str1 << endl;
    cout << "vowels are " << v << " consonants are " << c << endl;

    int words = 0;

    // COUNTING NUMBER OF WORDS IN STRING
    for (int i = 0; str1[i] != '\0'; i++)
    {
        if (str1[i] == ' ' && str1[i - 1] != ' ')
        {
            words++;
        }
    }
    cout << "total number of words are " << words << endl;

    // CHECKING FOR STRING TO BE VALID OR NOT(NOTE----> CHECKING IF STRING DOES NOT HAS ANY SPECIAL CHARACTERS )
    if (valid(str2))
    {
        cout << "string is valid " << endl;
    }
    else
    {
        cout << "invalid string " << endl;
    }

    // REVERSING A STRING
    reversestr(str1);

    // comparing the string   (NOTE----> THIS FUNCTION WILL WORK ONLY IF THE THE STRING IS COMPLETELY)
    //(IN UPPERCASE OR COMPLETELY IN LOWER CASE )
    char s[] = "paint";
    char s1[] = "painter";
    compare(s, s1);

    // CHECKING STRING TO BE PALINDROME
    char s2[] = "racecar";
    if (palindrome(s2)) //(NOTE -----> THIS FUNCTION WILL ONLY WORK IF THE STRING IS EITHER COMPLETELY )
    //(IN LOWER CASE OR IN UPPER CASE )
    {
        cout << "string is palindrome " << endl;
    }
    else
    {
        cout << "string is not palindrome " << endl;
    }

    // CHECKING IF THE STRING HAS ANY DUPLICATE ALPHABETS (NOTE----> THIS FUNCTION WILL ONLY WORK IF STRING IS)
    //(IN LOWER CASE)
    char s3[] = "finding";
    CheckForDuplicates(s3);

    // CHECKING IF THE STRINGS ARE ANAGRAM OR NOT
    //(NOTE-----> THE STRINGS SHOULD BE IN LOWER CASE FOR THIS FUNCTION TO WORK )
    char s4[] = "medical";
    char s5[] = "decimal";
    CheckingAnagram(s4, s5);

    //char per[] = "ABC";
    //perm(per, 0);
    return 0;
}