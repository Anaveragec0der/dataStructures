#include <iostream>
using namespace std;




//CANNOT BE COMPLETED WITH HELP OF LOOPS YET





// class UN
// {
//      int *f;
//      int length;
//      static int i;

// public:
//      void create(int fl)
//      {
//           length = fl;
//           f = new int[length];
//           cout << "enter elements in first array array " << endl;
//           for (int i = 0; i < length; i++)
//           {
//                cin >> f[i];
//           }
//      }
//      void display()
//      {

//           for (int i = 0; i < length; i++)
//           {
//                cout << f[i] << " ";
//           }
//           cout << endl;
//      }

//      int *Union(int *p, int len)
//      {
//           int *t;
//           int tl = len + length;
//           t = new int[tl];
//           for (int i = 0; i < length; i++)
//           {
//                t[i] = f[i];
//           }
//           for (int i = 0; i < len; i++)
//           {
//                if(p[i]!=t[i])
//                {
//                     t[length++]=p[i];
//                }
//           }
//           return t;
//      }
// };
// int UN::i=10// to intialize static variable with any userdefined value
void merge(int*g,int length)
{
     int *first;
     cout<<"enter number of elements in the array "<<endl;
     int len;
     cin>>len;
     first=new int[len];
     cout<<"enter elements in the array "<<endl;
     for(int i=0;i<len;i++)
     {
          cin>>first[i];
     }     
     int tlength=length+len;
     int *temp;
     temp=new int[tlength];
     for(int i=0;i<length;i++)
     {
          temp[i]=first[i];
     }
   //  for(int i=0;i<length;i++)
     //{
        for(int j=0;j<len;j++)
          {
               static int i;
          if(g[i]==first[j])
          {
               i++;
          }
          else{
               temp[length++] = g[i++];
          }
          }
  //   }
     cout<<"the merged array is "<<endl;
     for(int i=0;i<tlength;i++)
     {
          cout<<temp[i]<<" ";
     }
     cout<<endl;
}
int main()
{
     // UN n;
     // int flength;
     // cout << "enter the number of elements in first array " << endl;
     // cin >> flength;
     // n.create(flength);
     // cout << "the first array is " << endl;
     // n.display();
     // cout << "enter number of elements in second array " << endl;
     // int slength;
     // cin >> slength;
     // int arr[slength];
     // cout << "enter elements in the array " << endl;
     // for (int i = 0; i < slength; i++)
     // {
     //      cin >> arr[i];
     // }
     // cout << "the second array is " << endl;
     // for (int i = 0; i < slength; i++)
     // {
     //      cout << arr[i] << " ";
     // }
     // cout << endl;
     // int *res = n.Union(arr, slength);
     // int tlength = flength + slength;
     // cout << "array after union is " << endl;
     // for (int i = 0; i < tlength; i++)
     // {
     //      cout << res[i] << " ";
     // }
     // cout << endl;
     int arr[5]={12,4,7,2,5};
     merge(arr,5);
     return 0;
}