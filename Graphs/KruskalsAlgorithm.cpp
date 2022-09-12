#include<iostream>
#define v 7
#define e 9
using namespace std;
void PrintMCST(int T[][v-1], int A[][e]){
    cout << "\nMinimum Cost Spanning Tree Edges\n" << endl;
    for (int i {0}; i<v-1; i++){
        cout << "[" << T[0][i] << "]-----[" << T[1][i] << "]" << endl;
    }
}
void myunion(int x,int y,int *setar)
{
    if(setar[x]<setar[y])
    {
        setar[x]=setar[x]+setar[y];
        setar[y]=x;
    }
    else
    {
        setar[y]=setar[y]+setar[x];
        setar[x]=y;
    }
}
int find(int x,int *setar)
{
    int y=x;
    while(setar[y]>0)
    {
        y=setar[y];
    }
    return   y;
}
void KruskalsMCST(int cost[3][9])
{
    int output_matrix[2][v-1];
    int set[v+1]{-1,-1,-1,-1,-1,-1,-1,-1};
    int included[e]{0};
    int i=0;
    while(i<v-1)
    {
        int min=INT32_MAX;
        int U,V,k;
        for(int j=0;j<e;j++)
        {
            if(included[j]==0  && min>cost[2][j])
            {
                min=cost[2][j];
                k=j;
                U=cost[0][j];
                V=cost[1][j];
            }
        }
        if(find(U,set)!=find(V,set))
        {
            output_matrix[0][i]=U;
            output_matrix[1][i]=V;
            myunion(find(U,set),find(V,set),set);
            i++;
        }
        included[k]=1;
    }
    PrintMCST(output_matrix,cost);
}
 

int main(){
    int edges[3][9]={{1,1,2,2,3,4,4,5,5},
                     {6,2,3,7,4,7,5,7,6},
                     {5,25,12,10,8,14,16,18,20},};
    KruskalsMCST(edges);   
     return 0;
}