#include <bits/stdc++.h> 
using namespace std; 
  
void add_edge(vector<int> adj[], int src, int dest) 
{ 
    adj[src].push_back(dest); 
    adj[dest].push_back(src); 
} 

// bool Dijkstra(vector<int> adj[], int src, int dest, int v, 
                            // int pred[], int dist[]) {
  
// }

bool BFS(vector<int> adj[], int src, int dest, int v, 
                            int pred[], int dist[]) 
{ 
    list<int> queue; 
    bool visited[v]; 

    for (int i = 0; i < v; i++) { 
        visited[i] = false; 
        dist[i] = INT_MAX; 
        pred[i] = -1; 
    } 
    visited[src] = true; 
    dist[src] = 0; 
    queue.push_back(src); 
  
    // standard BFS algorithm 
    while (!queue.empty()) { 
        int u = queue.front(); 
        queue.pop_front(); 
        for (int i = 0; i < adj[u].size(); i++) { 
            if (visited[adj[u][i]] == false) { 
                visited[adj[u][i]] = true; 
                dist[adj[u][i]] = dist[u] + 1; 
                pred[adj[u][i]] = u; 
                queue.push_back(adj[u][i]); 
                
                if (adj[u][i] == dest) 
                   return true; 
            } 
        } 
    } 
  
    return false; 
} 
  
int printShortestDistance(vector<int> adj[], int s,  
                                    int dest, int v) 
{ 
    int pred[v], dist[v]; 
  
    if (BFS(adj, s, dest, v, pred, dist) == false) 
    { 
        return 0; 
    } 
  
    // vector path stores the shortest path 
    vector<int> path; 
    int crawl = dest; 
    path.push_back(crawl); 
    while (pred[crawl] != -1) { 
        path.push_back(pred[crawl]); 
        crawl = pred[crawl]; 
    } 
    return dist[dest] + 1; 
} 
int main() {
    int n, m, x, y;
    // no. of vertices 
    cin>>n>>m;  
    vector<int> adj[n+1]; 
    for (int i=0; i<m; i++){
      cin>>x>>y;
      add_edge(adj, x, y);
    } 
    int source = 1, dest = n; 
    cout<<printShortestDistance(adj, source, dest, n)<<endl; 
    return 0; 
} 