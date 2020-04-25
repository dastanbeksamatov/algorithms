/*
Task name: ban
In a state, there are n towns (numbered from 1 to n). Some pairs of towns are
connected with at most one immediate two-way road. The number of these roads is m.
Sometimes, an immediate road between two towns is closed for repair (only one immediate
road at each moment) and there may become impossible to travel between both towns,
because there are no bypass routes. The government uses a computer program to find which
are these important immediate roads and prohibited them to be repaired altogether. Write
program ban, which finds how many roads are in the prohibition list.

*/



#include<iostream>
#include <list>
#define N -1
using namespace std;
class G
{
  int n;
  list<int> *adj;
  void conn_edges(int n, bool visited[], int disc[], int low[], int par[]);
  public:
    G(int n); //constructor
    void addEd(int w, int x);
    void count();
    // counts edge-connectivity of the graph
    int egdges;
};
G::G(int n)
{
   this->n= n;
   adj = new list<int> [n];
   this->egdges = 0;
}
//add edges to the graph
void G::addEd(int w, int x)
{
  adj[x].push_back(w); 
  adj[w].push_back(x); 
}
void G::conn_edges(int w, bool visited[], int dis[], int low[], int par[])
{
  static int t = 0;
  //mark current node as visited
  visited[w] = true;
  dis[w] = low[w] = ++t;
  //Go through all adjacent vertices
  list<int>::iterator i;
  for (i = adj[w].begin(); i != adj[w].end(); ++i) {
    int x = *i; //x is current adjacent
    if (!visited[x]) {
      par[x] = w;
      conn_edges(x, visited, dis, low, par);
      low[w] = min(low[w], low[x]);
      // If the lowest vertex reachable from subtree under x is
      // below w in DFS tree, then w-x is a connection
      if (low[x] > dis[w])
        this->egdges += 1;
      }
      else if (x != par[w])
         low[w] = min(low[w], dis[x]);
   }
}
void G::count()
{
   // Mark all the vertices as unvisited
  bool *visited = new bool[n];
  int *dis = new int[n];
  int *low = new int[n];
  int *par = new int[n];
  for (int i = 0; i < n; i++) {
    par[i] = N;
    visited[i] = false;
  }
  //call the function connections() to find edge
  // connections
  for (int i = 0; i < n; i++)
    if (visited[i] == false)
      conn_edges(i, visited, dis, low, par);
}
int main()
{
  int n, m, x, y;
  cin>>n>>m;
  G g(n+1);
  for(int i=0; i<m; i++){
    cin>>x>>y;
    g.addEd(x, y);
  }
  // count and display edge-connectivity of a graph
  g.count();
  cout<<g.egdges<<endl;
  return 0;
}