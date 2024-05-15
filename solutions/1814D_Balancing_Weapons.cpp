// Problem: Balancing Weapons
// URL: https://codeforces.com/problemset/problem/1814/D
// Rating: 2500
// Tags: binary search, brute force, data structures, math, two pointers
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
typedef long double LD;

const int N = 210000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, k, f[3100], b[3100], p[3100];
vector<int> a[3100];
LL d[3100];

void solve() {
	cin >> n >> k;
	repn(i, 1, n) cin >> f[i];
	repn(i, 1, n) {
		cin >> d[i];
		d[i] *= f[i];
	}
	int ans = n;
	repn(i, 1, n) {
		repn(j, 1, n) b[j] = 0;
		repn(j, 0, 2 * k) {
			a[j].clear();
			p[j] = 0;
		}
		LL l = max((LL)1, d[i] - k), r = d[i] + k, pt = d[i] - k;
		int cnt = 0, tot = 0;
		repn(j, 1, n) {
			if (d[j] >= l && d[j] <= r) {
				p[d[j] - pt] ++;
			} 
			if (f[j] <= k || j == i) {
				cnt ++; 
				continue; 
			}
			if (f[j] > r) continue;
			LL st = r / f[j] * f[j]; 
			if (st < l) continue;
			while (st - f[j] >= l) st -= f[j];
			while (st <= r) {
				a[st - pt].pb(j);
				st += f[j];
			}
		}
		int p1 = 0, p2 = -1; 
		while (p2 < k) {
			p2 ++;
			for (auto x : a[p2]) {
				if (b[x] == 0) cnt ++;
				b[x] ++;
			}
			tot += p[p2];
		}
		if (cnt == n) ans = min(n - tot, ans);
		while (p2 < 2 * k) {
			p2 ++; 
			for (auto x : a[p2]) {
				if (b[x] == 0) cnt ++;
				b[x] ++;
			}
			for (auto x : a[p1]) {
				if (b[x] == 1) cnt --;
				b[x] --;
			}
			tot += p[p2];
			tot -= p[p1];
			p1 ++;
			if (cnt == n) ans = min(n - tot, ans);
		}
	}
	cout << ans << "\n";
} 

int main() {
	IO; 
	int t;
	cin >> t;
	repn(i, 1, t) solve(); 
	return 0;
}


