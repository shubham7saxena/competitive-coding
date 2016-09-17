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

int main(){
    
}