// Problem: Li Hua and Array
// URL: https://codeforces.com/problemset/problem/1797/E
// Rating: 2300
// Tags: brute force, data structures, dsu, math, number theory, two pointers
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
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, m;

namespace NT {
	const int N = 5100000;
	int prim[N], primm, valid[N], miu[N], phi[N];
	void linear_sieve() {
		// calculate: miu, phi, prim
		miu[1] = phi[1] = 1;
		rep(i, 2, N) {
			if (!valid[i]) prim[++primm] = i, miu[i] = -1, phi[i] = i - 1;
			for (int j = 1; j <= primm && i * prim[j] < N; j++) {
				valid[i * prim[j]] = 1;
				if (i % prim[j] == 0) {
					miu[i * prim[j]] = 0;
					phi[i * prim[j]] = phi[i] * prim[j];
					break;
				}
				else {
					miu[i * prim[j]] = -miu[i];
					phi[i * prim[j]] = phi[i] * (prim[j] - 1);
				}
			}
		}
	}
	vector<int> get_primes(int x) {
		// get all prime factor of x, return in increasing order
		// time: O(sqrt(x))
		vector<int> ans;
		for (int i = 2; i * i <= x; i++) {
	        if (x % i == 0) {
	            ans.push_back(i);
	            while (x % i == 0) x /= i;
	        }
	        if (x == 1) break;
	    }
	    if (x > 1) ans.push_back(x);
	    return ans;
	}
	LL cal_coprime_under_m(vector<int> &prime, LL m) {
		// calculate the number of value y, s.t. gcd(x, y) == 1, 1 <= y <= m
		// algo: mobius inversion
		// time: O(2^|prime|)
	    LL ans = 0;
	    int np = prime.size();
	    rep(s, 0, 1 << np) {
	        int cnt = 0, mul = 1;
	        rep(i, 0, np) {
	            if (s >> i & 1) cnt++, mul *= prime[i];
	        }
	        if (cnt & 1) ans -= m / mul;
	        else ans += m / mul;
	    }
	    return ans;
	}
}

int v[N];
int lowbit(int x) {
	return x & -x;
}
void add(int x, int y) {
	for (int i = x; i < N; i += lowbit(i)) v[i] += y; 
}
int get(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += v[i];
	return res;
} 

int a[N];

PII mn[M], mx[M];
void update(int k) {
	mn[k] = min(mn[LC], mn[RC]); 
	mx[k] = max(mx[LC], mx[RC]);
}
void build(int k, int l, int r) {
	if (l == r) {
		mn[k] = mx[k] = mp(a[l], l);
		return;
	}
	int mid = (l + r) / 2;
	build(LC, l, mid);
	build(RC, mid + 1, r);
	update(k);
}
void change(int k, int l, int r, int a, int b) {
	if (mx[k].fi == 1) return;
	if (l == r) {
		mn[k].fi = mx[k].fi = NT::phi[mn[k].fi];
		add(l, 1);
		return;
	}
	int mid = (l + r) / 2;
	if (b <= mid) change(LC, l, mid, a, b);
	else if (a > mid) change(RC, mid + 1, r, a, b);
	else change(LC, l, mid, a, mid), change(RC, mid + 1, r, mid + 1, b);
	update(k); 
} 
PII ask(int k, int l, int r, int a, int b) {
	if (l == a && r == b) return mn[k];
	int mid = (l + r) / 2;
	if (b <= mid) return ask(LC, l, mid, a, b);
	else if (a > mid) return ask(RC, mid + 1, r, a, b);
	else return min(ask(LC, l, mid, a, mid), ask(RC, mid + 1, r, mid + 1, b));
}
const int L = 5100000;
vector<PII> sum[L];
 
int main() { 
	IO;
	NT::linear_sieve();
	cin >> n >> m;
	rep(i, 1, L) sum[i].pb(mp(0, 0));
	repn(i, 1, n) {
		cin >> a[i];
		int num = a[i];
		int cnt = 0;
		while (1) {
			sum[num].pb(mp(i, cnt + sum[num][sum[num].size() - 1].se));
			if (num == 1) break;
			num = NT::phi[num];
			cnt ++;
		}
	}
	int tp, l, r;
	build(1, 1, n);
	repn(i, 1, m) {
		cin >> tp >> l >> r;
		if (tp == 1) change(1, 1, n, l, r); 
		else {
			PII res = ask(1, 1, n, l, r);
			int pos = res.se, num = res.fi;
			while (1) {
				int it1 = lower_bound(sum[num].begin(), sum[num].end(), mp(l, 0)) - sum[num].begin();
				int it2 = lower_bound(sum[num].begin(), sum[num].end(), mp(r + 1, 0)) - sum[num].begin();
				it1 --; it2 --;
				int len = it2 - it1;
				if (len == r - l + 1) {
					int cur = sum[num][it2].se - sum[num][it1].se;
					cur -= get(r) - get(l - 1);
					cout << cur << "\n";
					break;
				}
				num = NT::phi[num];
			}
			
		}
	}
	return 0;
}

/*
5 2
8 1 6 3 7
1 1 3
2 3 4

*/

// maintenance note (1): minor readability pass on this file — 2026-08-20
