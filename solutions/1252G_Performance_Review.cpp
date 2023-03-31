// Problem: Performance Review
// URL: https://codeforces.com/problemset/problem/1252/G
// Rating: 2100
// Tags: data structures
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

int n, m, q;
int a[N], b[N], base;
vector<int> g[N];
int lz[M], mn[M];
void update(int k) {
	mn[k] = min(mn[LC], mn[RC]);
}
void pushdown(int k) {
	if (lz[k] != 0) {
		lz[LC] += lz[k], lz[RC] += lz[k];
		mn[LC] += lz[k], mn[RC] += lz[k];
		lz[k] = 0;
	}
}
void build(int k, int l, int r) {
	if (l == r) {
		mn[k] = a[l - 1] - b[l];
		return;
	}
	int mid = (l + r) / 2;
	build(LC, l, mid);
	build(RC, mid + 1, r);
	update(k);
}
void change(int k, int l, int r, int a, int b, int c) {
	if (l == a && r == b) {
		lz[k] += c;
		mn[k] += c;
		return;
	}
	int mid = (l + r) / 2;
	pushdown(k);
	if (b <= mid) change(LC, l, mid, a, b, c);
	else if (a > mid) change(RC, mid + 1, r, a, b, c);
	else change(LC, l, mid, a, mid, c), change(RC, mid + 1, r, mid + 1, b, c);
	update(k);
}
int main() {
	IO;
	cin >> n >> m >> q;
	repn(i, 1, n) {
		int x;
		cin >> x;
		if (i == 1) base = x;
		else if (x < base) a[0]++;
	}
	repn(i, 1, m) {
		a[i] = a[i - 1];
		b[i] = b[i - 1];
		int k;
		cin >> k;
		b[i] += k;
		while (k--) {
			int x;
			cin >> x;
			g[i].pb(x);
			if (x < base) a[i]++;
		}
	}
	build(1, 1, m);
	while (q--) {
		int d, pos, z;
		cin >> d >> pos >> z;
		int old = g[d][pos - 1];
		if (old < base) {
			if (z < base);
			else if (d != m) change(1, 1, m, d + 1, m, -1);
		}
		else {
			if (z > base);
			else if (d != m) change(1, 1, m, d + 1, m, 1);
		}
		g[d][pos - 1] = z;
		if (mn[1] < 0) cout << "0\n";
		else cout << "1\n";
	}
	return 0;
}