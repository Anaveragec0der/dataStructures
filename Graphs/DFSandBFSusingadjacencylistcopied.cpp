// Number of vertices = n = 7
// Number of edges = 9
// Type of graph = directed = 'd'
// 1 2
// 1 3
// 2 4
// 3 2
// 3 6
// 4 5
// 5 3
// 5 7
// 6 7
// For starting index 5
// expected output : 5 3 2 4 6 7
// actual output :   5 3 2 4
 
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#define AND &&
#define endl "\n"
using namespace std;
 
class Node
{
    public:
        int data;
        Node *next;
};
 
Node** create(int vertices)           // returning pointer of adjacency list
{
    Node **adj = new Node *[vertices+1];
    for(int i = 0; i <= vertices; i++)
        adj[i] = NULL;
    return adj;
}
 
void place(Node **adj, int x, int y)   // placing x-y in the adjacency list
{
    Node *temp = new Node;
    temp->data = y;
    temp->next = NULL;
 
    if(!adj[x])
        adj[x] = temp;
    else
    {
        Node *ptr = adj[x];
        while(ptr->next)
            ptr = ptr->next;
        ptr->next = temp;
    }
}
 
void DFS(Node **adj, int i, int n)
{
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
 
    stack<int> stk;
    stk.push(i);
    cout << i << " ";
    visited[i] = true;
 
    Node *ptr = adj[i];
    while(!stk.empty())
    {
        while(ptr)
        {
            if(!visited[ptr->data])
            {
                cout << ptr->data << " ";
                visited[ptr->data] = true;
                stk.push(ptr->data); //changes
                i = ptr->data;
                break;
            }
            ptr = ptr->next;
        }
        
        if(!ptr){  //condition changed
            stk.pop();
            if(stk.empty()){
                break;
            }
            i = stk.top();
            
        }
        ptr = adj[i];
        
        
        
    }
    cout << endl;
}
 
int main()
{
    cout << "Enter the number of vertices in the graph with 1-base indexing: ";
    int n; cin >> n;
    Node **adj = create(n);
 
    char ch = 'x';
    do{
        cout << "Is the graph directed(d) or undirected(u): ";
        cin >> ch;
    }while(ch != 'd' AND ch != 'u');
 
    cout << "Enter the number of edges: ";
    int edges; cin >> edges;
    cout << "Now enter these " << edges << " edges in the form of (st en)" << endl;
    
    int x, y;
    while(edges--)
    {
        cin >> x >> y;
        place(adj, x, y);
        // additional condition for undirected graph
        if(ch == 'u')
            place(adj, y, x);
    }
 
    cout << "How many DFS traversals? ";
    int t; cin >> t;
    while(t--)
    {
        cout << "Enter the starting vertex: ";
        int start; cin >> start;
        cout << "DFS traversal: ";
        DFS(adj, start, n);
    }
 
    return 0;
}