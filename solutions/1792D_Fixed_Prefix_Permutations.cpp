// Problem: Fixed Prefix Permutations
// URL: https://codeforces.com/problemset/problem/1792/D
// Rating: 1700
// Tags: binary search, bitmasks, data structures, hashing, math, sortings
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

const int N = 510000;
const int M = 51000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, m, trie[N][11], pos, root, a[M][11], p[11]; 

int newnode() {
	pos++;
	memset(trie[pos], 0, sizeof(trie[pos]));
	return pos; 
} 
void solve(){
	pos = 0; root = newnode();
	cin >> n >> m;
	repn(i, 1, n){
		int cur = 1;
		repn(j, 1, m) {
			cin >> a[i][j];
			p[a[i][j]] = j;
		} 
		repn(j, 1, m) {
			if (trie[cur][p[j]] == 0) {
				trie[cur][p[j]] = newnode();
			}
			cur = trie[cur][p[j]];
		}
	}
	repn(i, 1, n) {
		int ans = 0, cur = root;
		repn(j, 1, m) {
			if (trie[cur][a[i][j]] == 0) break;
			ans = j;
			cur = trie[cur][a[i][j]];
		}
		cout << ans << " ";
	}		
	cout << "\n";
}

int main() {
	IO;
	int t;
	cin >> t;
	repn(i, 1, t) solve();
	return 0;
}



// maintenance note (5): small formatting cleanup on this file — 2026-08-30
