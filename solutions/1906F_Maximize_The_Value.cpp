// Problem: Maximize The Value
// URL: https://codeforces.com/problemset/problem/1906/F
// Rating: 2100
// Tags: data structures, sortings
// Language: C++17 (GCC 7-32)
#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k<<1
#define RC k<<1|1
#define IO cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n) - 1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<LL, LL> PLL;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-9;

mt19937_64 Rand((unsigned long long)new char);
#define rand Rand

int n, m, q;
struct query {
	int id, l, r, op;
	friend bool operator < (query a, query b) {
		return a.op < b.op;
	}
};
vector<query> f[N];
struct operations {
	int l, r, x;
}ops[N];
LL ans[N];

struct node {
	LL sum, pre, suf, mx, vmx;
}tr[M];
node operator + (node a, node b) {
	node res;
	res.vmx = max(a.vmx, b.vmx);
	res.sum = a.sum + b.sum;
	res.pre = max(a.pre, a.sum + b.pre);
	res.suf = max(b.suf, b.sum + a.suf);
	res.mx = max({a.mx, b.mx, a.suf + b.pre});
	return res;
}
void update(int k) {
	tr[k] = tr[LC] + tr[RC];
}
void change(int k, int l, int r, int a, LL b) {
	if (l == r) {
		tr[k] = {b, max(b, 0LL), max(b, 0LL), max(0LL, b), b};
		return;
	}
	int mid = (l + r) / 2;
	if (a <= mid) change(LC, l, mid, a, b);
	else change(RC, mid + 1, r, a, b);
	update(k);
}
node ask(int k, int l, int r, int a, int b) {
	if (l == a && r == b) return tr[k];
	int mid = (l + r) / 2;
	if (b <= mid) return ask(LC, l, mid, a, b);
	else if (a > mid) return ask(RC, mid + 1, r, a, b);
	else return ask(LC, l, mid, a, mid) + ask(RC, mid + 1, r, mid + 1, b);
}
int main() {
	IO;
	cin >> n >> m;
	repn(i, 1, m) {
		cin >> ops[i].l >> ops[i].r >> ops[i].x;
		f[ops[i].l].pb({i, 0, 0, 0});
		f[ops[i].r + 1].pb({i, 0, 0, 1});
	}
	cin >> q;
	repn(i, 1, q) {
		query p;
		int x;
		cin >> x >> p.l >> p.r;
		p.op = 2;
		p.id = i;
		f[x].pb(p);
	}
	repn(i, 1, n) {
		sort(all(f[i]));
		for (auto p: f[i]) {
			int op = p.op;
			if (op == 0) change(1, 1, m, p.id, ops[p.id].x);
			else if (op == 1) change(1, 1, m, p.id, 0);
			else {
				node res = ask(1, 1, m, p.l, p.r);
				if (res.vmx < 0) ans[p.id] = res.vmx;
				else ans[p.id] = res.mx;
			}
		}
	}
	repn(i, 1, q) cout << ans[i] << "\n";
	return 0;
}// maintenance note (8): note time complexity in this file — 2026-09-07
