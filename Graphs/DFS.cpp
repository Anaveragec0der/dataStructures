#include<iostream>
using namespace std;
void DFS(int vertex ,int A[][8],int n)
{
    static int visited[8]{0};//WE ARE MAKING THE ARRAY STATIC AS WE  WANT IT TO BE AVAILABLE IN EVERY
    // RECURSIVE  CALL
    if(visited[vertex]==0)
    {
        cout<<vertex<<" ,"<<flush;
        visited[vertex]=1;
        for(int v=1;v<n;v++)
        {
            if(A[vertex][v]==1 && visited[v]==0)
            {
                DFS(v,A,n);
            }
        }
    }
}
int main(){
  int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 1 -> " << flush;
    DFS(1, A, 8);
 
    
    
     return 0;
}