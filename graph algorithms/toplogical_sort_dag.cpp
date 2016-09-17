#include<bits/stdc++.h>
 
using namespace std;

#define mod 1000000000
#define loop(i,a,b) for(int i=a;i<b;i++)
#define all(c) (c).begin(),(c).end()
#define nl cout<<"\n"
#define sz(a) (int)(a).size()
#define len(a) (int)a.length()
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 2000000000;

ll gcd(ll a, ll b) { int temp; while(b > 0) { temp = a%b; a = b; b = temp; } return a; }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }
ll modpow(ll a, ll n) { ll p = 1; while(n) { if (n%2) p = p*a%mod; n/=2; a = a*a%mod; } return p; }

class Graph
{
    int V;
    list<int> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::topologicalSortUtil(int v, bool visited[], 
                                stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
    Stack.push(v);
}
void Graph::topologicalSort()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();
 
    return 0;
}