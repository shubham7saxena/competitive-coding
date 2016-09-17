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

#define MAXN 100

int t[4*MAXN];
int lazy[4*MAXN]={0};

int merge(int left, int right)
{
	return t[left]+t[right];
}

void build(int a[], int node_number, int p, int r)
{
	if (p==r)
		t[node_number]=a[p];
	else {
		int q=(p+r)/2;
		build(a, 2*node_number, p, q);
		build(a, 2*node_number+1, q+1, r);
		t[node_number] = merge(2*node_number, 2*node_number+1);
	}
}

int query(int a[], int node_number, int sl, int sr, int l, int r)
{
	if (lazy[node_number] != 0) {
		t[node_number] += (sr-sl+1)*lazy[node_number];

		if (sl != sr) {
			lazy[2*node_number] += lazy[node_number];
			lazy[2*node_number+1] += lazy[node_number];
		}
		lazy[node_number] = 0;
	}

	if (sl>sr || r<sl || l>sr)
		return 0;

	if (sl>=l && sr<=r)
		return t[node_number];

	int q=(sl+sr)/2;

	return (query(a, 2*node_number, sl, q, l, r) + query(a, 2*node_number+1, q+1, sr, l, r));
}

void update(int a[], int node_number, int sl, int sr, int l, int r, int value)
{
	if (lazy[node_number] != 0) {
		t[node_number] += (sr-sl+1)*lazy[node_number];

		if(sl != sr) {
			lazy[2*node_number] += lazy[node_number];
			lazy[2*node_number+1] += lazy[node_number];
		}
		lazy[node_number] = 0;
	}

	if (sl>sr || l>sr || r<sl)
		return;

	if (sl>=l && sr<=r) {
		t[node_number] += value*(sr-sl+1);

		if (sl != sr) {
			lazy[2*node_number] += value;
			lazy[2*node_number+1] += value;

		}
		return;
	}

	int q=(sl+sr)/2;
	update(a, 2*node_number, sl, q, l, r, value);
	update(a, 2*node_number+1, q+1, sr, l, r, value);
	t[node_number] = merge(2*node_number, 2*node_number+1);
}

int main()
{
        int a[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        build(a, 1, 0, 9);

        int queries, query_type;
        cin >> queries;
        int l, r;
        for (int i=0; i<queries; i++) {
                cin >> query_type;
                if (query_type == 1) {
                        cin >> l >> r;
                        cout << query(a, 1, 0, 9, l-1, r-1) << endl;
                } else if (query_type == 2) {
                        int index, value;
                        cin >> l >> r >> value;
                        update(a, 1, 0, 9, l-1, r-1, value);
                }
        }
        return 0;
}
