// Problem: Valiant's New Map
// URL: https://codeforces.com/problemset/problem/1731/D
// Rating: 1700
// Tags: binary search, brute force, data structures, dp, two pointers
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

const int N = 210000;
const int M = 110000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;



void solve() {
	int m, n;
	cin >> n >> m;
	vector<vector<int>> a(n+1, vector<int>(m+1, 0)), s(n+1, vector<int>(m+1, 0));
	repn(i, 1, n) {
		repn(j, 1, m) cin >> a[i][j];
	}
	int l = 1, r = min(n, m);
	while (l < r) {
		bool can = false;
		int mid = (l + r + 1) / 2;
		repn(i, 1, n) {
			repn(j, 1, m) {
				if (a[i][j] >= mid) s[i][j] = 0;
				else s[i][j] = 1;
			} 
		}
		repn(i, 1, n) {
			repn(j, 1, m) {
				s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
			} 
		}
		repn(i, mid, n) {
			repn(j, mid, m) {
				int cur = s[i][j] - s[i - mid][j] - s[i][j - mid] + s[i - mid][j - mid];
				if (cur == 0) can = true;
			}
		}
		if (can) l = mid;
		else r = mid - 1;
	}
	cout << l << "\n";
}

int main() {
    IO;
    int t;
	cin >> t;
	repn(i, 1, t) solve(); 
    return 0;
}




