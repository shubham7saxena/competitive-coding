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

class UF    {
    ll *id, cnt, *sz;
public:
    // Create an empty union find data structure with N isolated sets.
    UF(ll N){
        max = 1;
        cnt = N;
        id = new ll[N];
        sz = new ll[N];
        for(ll i=0; i<N; i++)  {
            id[i] = i;
            sz[i] = 1;
        }
    }
    ~UF()   {
        delete [] id;
        delete [] sz;
    }
    // Return the id of component corresponding to object p.
    ll find(ll p) {
        ll root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {     //path compression
            ll newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
    // Replace sets containing x and y with their union.
    void merge(ll x, ll y)    {
        ll i = find(x);
        ll j = find(y);
        if (i == j) return;
        
        // make smaller root point to larger one
        if(sz[i] < sz[j]){           // union by rank
            id[i] = j; 
            sz[j] += sz[i]; 
        } 
        else { 
            id[j] = i; 
            sz[i] += sz[j]; 
        }
        cnt--;
    }
    // Are objects x and y in the same set?
    bool connected(ll x, ll y)    {
        return find(x) == find(y);
    }
    // Return the number of disjoint sets.
    int count() {
        return cnt;
    }
};
int main(){

}