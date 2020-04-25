
// C++ program to print all the cycles 
// in an undirected graph 
#include <bits/stdc++.h> 
using namespace std; 
  
// variables to be used 
// in both functions 
  
// Function to mark the vertex with 
// different colors for different cycles 
void dfs_cycle(int u, int p, int color[], 
               int mark[], int par[], int& cyclenumber, vector<int> cycles[], vector<int> graph[]) 
{ 
  
    // already (completely) visited vertex. 
    if (color[u] == 2) { 
        return; 
    } 
  
    // seen vertex, but was not completely visited -> cycle detected. 
    // backtrack based on parents to find the complete cycle. 
    if (color[u] == 1) { 
  
        cyclenumber++; 
        int cur = p; 
        mark[cur] = cyclenumber; 
  
        // backtrack the vertex which are 
        // in the current cycle thats found 
        while (cur != u) { 
            cur = par[cur]; 
            mark[cur] = cyclenumber; 
        } 
        return; 
    } 
    par[u] = p; 
  
    // partially visited. 
    color[u] = 1; 
  
    // simple dfs on graph 
    for (int v : graph[u]) { 
  
        // if it has not been visited previously 
        if (v == par[u]) { 
            continue; 
        } 
        dfs_cycle(v, u, color, mark, par, cyclenumber, cycles, graph); 
    } 
  
    // completely visited. 
    color[u] = 2; 
} 
  
// add the edges to the graph 
void addEdge(int u, int v, vector<int> graph[]) 
{ 
    graph[u].push_back(v); 
    graph[v].push_back(u); 
} 
  
// Function to print the cycles 
void printCycles(int edges, int mark[], int& cyclenumber, vector<int> cycles[]) 
{ 
  
    // push the edges that into the 
    // cycle adjacency list 
    for (int i = 1; i <= edges; i++) { 
        if (mark[i] != 0) 
            cycles[mark[i]].push_back(i); 
    } 
  
    // print all the vertex with same cycle 
    int max = cycles[0].size();
    for (int i = 1; i <= cyclenumber; i++) { 
        // Print the i-th cycle 
        if(cycles[i].size() > max){
            max = cycles[i].size();
        }
    } 
    cout<<max<<endl;
} 
  
// Driver Code 
int main() 
{ 
  
    // add edges 
    int n, m, x, y;
    cin>>n>>m;
    vector<int> graph[n]; 
    vector<int> cycles[n]; 
    for(int i=0; i<m; i++){
        cin>>x>>y;
        addEdge(x, y, graph);
    }
  
    // arrays required to color the 
    // graph, store the parent of node 
    int color[n+1]; 
    int par[n+1]; 
  
    // mark with unique numbers 
    int mark[n+1]; 
  
    // store the numbers of cycle 
    int cyclenumber = 0; 
    int edges = m; 
  
    // call DFS to mark the cycles 
    dfs_cycle(1, 0, color, mark, par, cyclenumber, cycles, graph); 
  
    // function to print the cycles 
    printCycles(edges, mark, cyclenumber, cycles); 
} 
