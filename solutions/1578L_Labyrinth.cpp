// Problem: Labyrinth
// URL: https://codeforces.com/problemset/problem/1578/L
// Rating: 2400
// Tags: binary search, dsu, greedy
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
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF=1e18;
const double eps = 1e-9;

int n, m;
int c[N], f[N];
LL dp[N], sum[N];
struct edge {
	int x, y, w;
	friend bool operator < (const edge a, const edge b) {
		return a.w > b.w;
	}
}e[N];
int find(int x) {
	return f[x] == x ? x: f[x] = find(f[x]);
}
int main()
{
	IO;
	cin >> n >> m;
	repn(i, 1, n) cin >> c[i], f[i] = i, sum[i] = c[i], dp[i]=INF;
	repn(i, 1, m) cin >> e[i].x >> e[i].y >> e[i].w;
	sort(e + 1, e + m + 1);
	repn(i, 1, m) {
		int x = e[i].x, y = e[i].y, w = e[i].w;
		int fx = find(x), fy = find(y);
		if (fx != fy) {
			LL cur = w;
			if (sum[fx] > sum[fy]) swap(fx, fy);
			if (sum[fx] > w) dp[fx] = 0;
			else {
				if (sum[fy] > w) {
					dp[fx] = min(w - sum[fx], dp[fy] - sum[fx]);
				}
				else {
					dp[fx] = max(min(w - sum[fx], dp[fy] - sum[fx]), min(w - sum[fy], dp[fx] - sum[fy]));
				}
			}
			f[fy] = fx;
			sum[fx] += sum[fy];
			if (dp[fx] <= 0) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << dp[find(1)] << endl;
	return 0;
}