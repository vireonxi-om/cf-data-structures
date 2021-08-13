// Problem: Longest Array Deconstruction
// URL: https://codeforces.com/problemset/problem/1575/L
// Rating: 2100
// Tags: data structures, divide and conquer, dp, sortings
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
const int M = 1100000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const double eps = 1e-9;

int n, a[N], mx, ans;
map<int, int> v[N];
inline int lowbit(int x) {
	return x & -x;
}
void add(int x, int delta, int y) {
	for (int i = x; i < N; i += lowbit(i)) {
		if (v[i].size() == 0) {
			v[i][delta] = y;
		}
		else {
			if (v[i].count(delta)) {
				int val = v[i][delta];
				if (val >= y);
				else {
					v[i][delta] = y;
					while (1) {
						auto p = v[i].upper_bound(delta);
						if (p == v[i].end() || (*p).se > y) break;
						v[i].erase((*p).fi);
					}
				}
			}
			else {
				v[i][delta] = y;
				if (v[i].lower_bound(delta) == v[i].begin()) {
					while (1) {
						auto p = v[i].upper_bound(delta);
						if (p == v[i].end() || (*p).se > y) break;
						v[i].erase((*p).fi);
					}
				}
				else {
					auto it = v[i].lower_bound(delta);
					it--;
					if ((*it).se >= y) v[i].erase(delta);
					else {
						while (1) {
							auto p = v[i].upper_bound(delta);
							if (p == v[i].end() || (*p).se > y) break;
							v[i].erase((*p).fi);
						}
					}
				}
			}
		}
	}
}
int get(int x, int y) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) {
		auto p = v[i].upper_bound(y);
		if (p == v[i].begin());
		else {
			p--;
			res = max(res, (*p).se);
		}
	}
	return res;
}
int main()
{
	IO;
	cin >> n;
	add(1, 0, 1);
	repn(i, 1, n) {
		cin >> a[i];
		a[i]++;
		int now = get(a[i] - 1, i - a[i] + 1);
		ans = max(ans, now);
		if (now) add(a[i], i - a[i] + 1, now + 1);
	}
	cout << ans << endl;
	return 0;
}