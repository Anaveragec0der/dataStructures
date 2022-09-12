#include <iostream>
#define I INT32_MAX
#define V 8
using namespace std;

void PrintMST(int out_matrix[][V-2], int cam[V][V]){
    cout << "\nMinimum Spanning Tree Edges (w/ cost)\n" << endl;
    int sum {0};
    for (int i {0}; i<V-2; i++){
        int c = cam[out_matrix[0][i]][out_matrix[1][i]];
        cout << "[" << out_matrix[0][i] << "]---[" << out_matrix[1][i] << "] cost: " << c << endl;
        sum += c;
    }
    cout << endl;
    cout << "Total cost of MST: " << sum << endl;
}
void Prims_Algorithm(int cam[V][V],int n)
{
    int u,v;
    int min=I;
    int near[V];
    int out_matrix[2][V-2]{0};
    for(int i=1;i<V;i++)
    {
        near[i]=I;
        for(int j=i;j<V;j++)
        {
            if(min>cam[i][j])
            {
                min=cam[i][j];
                u=i;
                v=j;
            }
        }
    }
    out_matrix[0][0]=u;
    out_matrix[1][0]=v;
    near[u]=near[v]=0;
    for(int i=1;i<V;i++)
    {
        // if(near[i]!=0 && cam[i][u]<cam[i][v])
        // {
        //     near[i]=u;
        // }
        // else
        // {
        //     near[i]=v;
        // }

        if (near[i] != 0){
            if (cam[i][u] < cam[i][v]){ 
                near[i] = u;
            } else {
                near[i] = v;
            }
        }
 
    }
    for(int i=1;i<n-1;i++)
    {
        int k;
        min=I;
        for(int j=1;j<V;j++)
        {
            if(near[j]!=0 && cam[j][near[j]]<min)
            {
                k=j;
                min=cam[j][near[j]];
            }
        }
        out_matrix[0][i]=k;
        out_matrix[1][i]=near[k];
        near[k]=0;
        for(int j=1;j<V;j++)
        {
            if(near[j]!=0 && cam[j][k]<cam[j][near[j]])
            {
                near[j]=k;
            }
        }
    }
    PrintMST(out_matrix,cam);
}
int main(){
     int cost [V][V] {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
 
    int n = sizeof(cost[0])/sizeof(cost[0][0]) - 1;
    Prims_Algorithm(cost,n);
 
     return 0;
}