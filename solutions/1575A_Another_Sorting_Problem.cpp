// Problem: Another Sorting Problem
// URL: https://codeforces.com/problemset/problem/1575/A
// Rating: 1100
// Tags: data structures, sortings, strings
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

const int N = 1100000;
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, m;
string s[N];
int idx[N], rk[N];
int main()
{
	IO;
	cin >> n >> m;
	repn(i, 1, n) cin >> s[i], idx[i] = i, rk[i] = 1;
	repn(i, 1, m) {
		int head = 1;
		int cur = 0, pos = 0;
		while (head <= n) {
			vector<PII> v;
			v.pb(mp(s[idx[head]][i - 1] - '0', idx[head]));
			int tail = head;
			while (tail <= n && rk[idx[tail + 1]] == rk[idx[head]]) {
				tail++;
				v.pb(mp(s[idx[tail]][i - 1] - '0', idx[tail]));
			}
			sort(all(v));
			if (i % 2 == 0) reverse(all(v));
			rk[v[0].se] = ++cur;
			pos++;
			idx[pos] = v[0].se;
			rep(j, 1, v.size()) {
				if (v[j].fi != v[j - 1].fi) cur++;
				rk[v[j].se] = cur;
				pos++;
				idx[pos] = v[j].se;
			}
			head = tail + 1;
		}
	}
	repn(i, 1, n) {
		cout << idx[i];
		if (i != n) cout << " ";
		else cout << "\n";
	}
	return 0;
}// maintenance note (6): add editorial link comment to this file — 2026-09-02
