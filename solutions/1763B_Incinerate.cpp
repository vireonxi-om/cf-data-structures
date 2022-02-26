// Problem: Incinerate
// URL: https://codeforces.com/problemset/problem/1763/B
// Rating: 1200
// Tags: binary search, brute force, data structures, implementation, math, sortings
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 110000;
const int M = 11000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, h[N], p[N], k;
vector<PII> a;

void solve() {
	a.clear();
	cin >> n >> k;
	int mh = 0;
	repn(i, 1, n){
		cin >> h[i];
		mh = max(mh, h[i]);
	} 
	repn(i, 1, n){
		cin >> p[i];
		a.pb(mp(p[i], h[i]));
	} 
	sort(all(a));
	int now = 0;
	for (auto x:a) {
		if (k <= 0) break;
		if (now + k >= x.se) continue;
		while (now < x.se && k > 0) {
			now += k;
			k -= x.fi;
		} 
	}
	if (mh > now + k && mh > now) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
    IO;
    int t;
    cin >> t;
    repn(i, 1, t) solve();
    return 0;
}




