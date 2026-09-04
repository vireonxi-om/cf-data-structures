// Problem: Rating System
// URL: https://codeforces.com/problemset/problem/1845/D
// Rating: 1800
// Tags: binary search, brute force, data structures, dp, dsu, greedy, math, two pointers
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
#define rep(i,a,n) for (int i = a; i < n; i++)
#define repn(i,a,n) for (int i = a; i <= n; i++)
#define per(i,a,n) for (int i = n - 1; i >= a; i--)
#define pern(i,a,n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef pair<int, LL> pii;
template<typename T> void down(T &x, T y) { if (x > y) x = y; }

const int N = 310000;
const int M = 610000;
const int mod = 998244353;
const int inf = (int)1e9;
const LL INF = (LL)1e12 + 5;
const double eps = 1e-9;
const double pi = acos(-1.0);


int n;
LL a[N], p[N], s[N], m[N];


void solve() {
	cin >> n; repn(i, 1, n) cin >> a[i];
	repn(i, 1, n) p[i] = p[i - 1] + a[i];
	s[n + 1] = 0; m[n + 1] = 0;
	pern(i, 1, n) s[i] = s[i + 1] + a[i];
	pern(i, 1, n) m[i] = max(m[i + 1], s[i]);
	LL ans = 0, k = 0;
	repn(i, 1, n) {
		if (a[i] > 0) continue;
		LL cur = p[i - 1] + m[i + 1];
		if (cur > ans) {
			ans = cur; k = p[i - 1];
		}
	}
	cout << k << "\n";
}

int main()
{
	IO;
	int T;
	cin >> T;
	repn(i, 1, T) solve();
	return 0;
}
// maintenance note (7): add edge-case comment to this file — 2026-09-04
