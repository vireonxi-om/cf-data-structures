// Problem: Even Path
// URL: https://codeforces.com/problemset/problem/1252/C
// Rating: 1600
// Tags: data structures, implementation
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k << 1
#define RC k << 1 | 1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = 1e9;
const LL INF = 1e18;
const double eps = 1e-9;

int n, q, a[N], b[N];
set<int> sr, sc;
int main() {
	IO;
	cin >> n >> q;
	repn(i, 1, n) cin >> a[i];
	repn(i, 1, n) cin >> b[i];
	int cl = 1, cr;
	while (cl <= n) {
		cr = cl;
		while (cr + 1 <= n && (a[cl] % 2 == a[cr + 1] % 2)) cr++;
		sr.insert(cr);
		cl = cr + 1;
	}
	cl = 1;
	while (cl <= n) {
		cr = cl;
		while (cr + 1 <= n && (b[cl] % 2 == b[cr + 1] % 2)) cr++;
		sc.insert(cr);
		cl = cr + 1;
	} 
	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int flag = 0;
		if (sr.lower_bound(x1) != sr.lower_bound(x2)) flag = 1;
		if (sc.lower_bound(y1) != sc.lower_bound(y2)) flag = 1;
		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}