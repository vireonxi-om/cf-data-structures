// Problem: Addition Robot
// URL: https://codeforces.com/problemset/problem/1252/K
// Rating: 2100
// Tags: data structures, math, matrices
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

int n, m;
string s;
struct matrix {
	LL a[2][2];
	friend matrix operator + (matrix a, matrix b) {
		matrix res;
		memset(res.a, 0, sizeof(res.a));
		res.a[0][0] = (a.a[0][0] * b.a[0][0] + a.a[0][1] * b.a[1][0]) % mod;
		res.a[0][1] = (a.a[0][0] * b.a[0][1] + a.a[0][1] * b.a[1][1]) % mod;
		res.a[1][0] = (a.a[1][0] * b.a[0][0] + a.a[1][1] * b.a[1][0]) % mod;
		res.a[1][1] = (a.a[1][0] * b.a[0][1] + a.a[1][1] * b.a[1][1]) % mod;
		return res;
	}
	void swp() {
		swap(a[0][0], a[1][1]);
		swap(a[1][0], a[0][1]);
	}	
}tr[M];
int lz[M];
void update(int k) {
	tr[k] = tr[LC] + tr[RC];
}
void build(int k, int l, int r) {
	if (l == r) {
		if (s[l - 1] == 'A') {
			tr[k].a[0][0] = tr[k].a[1][0] = tr[k].a[1][1] = 1;
			tr[k].a[0][1] = 0;
		}
		else {
			tr[k].a[0][0] = tr[k].a[0][1] = tr[k].a[1][1] = 1;
			tr[k].a[1][0] = 0;
		}
		return;
	}
	int mid = (l + r) / 2;
	build(LC, l, mid);
	build(RC, mid + 1, r);
	update(k);
}
void pushdown(int k) {
	if (lz[k]) {
		lz[LC] ^= 1, lz[RC] ^= 1;
		tr[LC].swp(), tr[RC].swp();
		lz[k] = 0;
	}
}
void change(int k, int l, int r, int a, int b) {
	if (l == a && r == b) {
		tr[k].swp();
		lz[k] ^= 1;
		return;
	}
	int mid = (l + r) / 2;
	pushdown(k);
	if (b <= mid) change(LC, l, mid, a, b);
	else if (a > mid) change(RC, mid + 1, r, a, b);
	else change(LC, l, mid, a, mid), change(RC, mid + 1, r, mid + 1, b);
	update(k);
}
matrix ask(int k, int l, int r, int a, int b) {
	if (l == a && r == b) return tr[k];
	int mid = (l + r) / 2;
	pushdown(k);
	matrix res;
	if (b <= mid) res = ask(LC, l, mid, a, b);
	else if (a > mid) res = ask(RC, mid + 1, r, a, b);
	else res = ask(LC, l, mid, a, mid) + ask(RC, mid + 1, r, mid + 1, b);
	update(k);
	return res;
}
int main() {
	IO;
	cin >> n >> m;
	cin >> s;
	build(1, 1, n);
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r;
			cin >> l >> r;
			change(1, 1, n, l, r);
		}
		else {
			int l, r, a, b;
			cin >> l >> r >> a >> b;
			matrix res = ask(1, 1, n, l, r);
			LL ansa = (LL)a * res.a[0][0] + (LL) b * res.a[1][0];
			LL ansb = (LL)a * res.a[0][1] + (LL) b * res.a[1][1];
			ansa %= mod;
			ansb %= mod;
			cout << ansa << " " << ansb << "\n";
		}
	}
	return 0;
}