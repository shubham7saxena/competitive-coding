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
    list< ii > *adj;
 
public:
    Graph(int V);  
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<ii> [V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src)
{

    priority_queue< ii, vii , greater<ii> > pq;

    vi dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        list< ii >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}
 
// Driver program to test methods of graph class
int main()
{
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.shortestPath(0);
 
    return 0;
}