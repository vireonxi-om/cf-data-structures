// Problem: Jeopardy of Dropped Balls
// URL: https://codeforces.com/problemset/problem/1575/J
// Rating: 1500
// Tags: binary search, brute force, dsu, implementation
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

const int N = 1100;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m, k;
int a[N][N];
PII f[N][N];
PII find(int x, int y) {
	if (f[x][y] == mp(x, y)) return mp(x, y);
	return f[x][y] = find(f[x][y].fi, f[x][y].se);
}
void merge(PII a, PII b) {
	PII fx = find(a.fi, a.se);
	PII fy = find(b.fi, b.se);
	if (fx != fy) {
		f[fx.fi][fx.se] = fy;
	}
}
int main()
{
	IO;
	cin >> n >> m >> k;
	repn(i, 1, n) repn(j, 1, m) {
		cin >> a[i][j];
		f[i][j] = mp(i, j);
	}
	repn(i, 1, m) f[0][i] = mp(0, i);
	repn(i, 1, k) {
		int x;
		cin >> x;
		PII now = mp(1, x);
		now = find(now.fi, now.se);
		while (now.fi) {
			if (a[now.fi][now.se] == 1) {
				a[now.fi][now.se] = 2;
				if (now.fi == n) merge(now, mp(0, now.se));
				else merge(now, mp(now.fi + 1, now.se));
				now.se++;
			}
			else if (a[now.fi][now.se] == 3) {
				a[now.fi][now.se] = 2;
				if (now.fi == n) merge(now, mp(0, now.se));
				else merge(now, mp(now.fi + 1, now.se));
				now.se--;
			}
			else {
				a[now.fi][now.se] = 2;
				if (now.fi == n) merge(now, mp(0, now.se)), now.fi = 0;
				else merge(now, mp(now.fi + 1, now.se)), now.fi++;
			}
			now = find(now.fi, now.se);
		}
		cout << now.se;
		if (i != k) cout << " ";
		else cout << "\n";
	}
	return 0;
}