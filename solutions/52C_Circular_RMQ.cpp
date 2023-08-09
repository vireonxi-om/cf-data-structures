// Problem: Circular RMQ
// URL: https://codeforces.com/problemset/problem/52/C
// Rating: 2200
// Tags: data structures
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
const int M = 11000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, m, a[N];
LL t[4 * N], lz[4 * N];

void pushdown(int k) {
	lz[LC] += lz[k];
	t[LC] += lz[k];
	lz[RC] += lz[k];
	t[RC] += lz[k];
	lz[k] = 0;
}
void update(int k) {
	t[k] = min(t[LC], t[RC]);
}
void build(int k, int l, int r) {
	if (l == r) {
		t[k] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(LC, l, mid);
	build(RC, mid + 1, r);
	update(k);
}
void change(int k, int l, int r, int a, int b, int val) {
	if (l == a && r == b) {
		lz[k] += val;
		t[k] += val;
		return;
	}
	if (lz[k] != 0) pushdown(k); 
	int mid = (l + r) / 2;
	if (b <= mid) change(LC, l, mid, a, b, val);
    else if (a > mid) change(RC, mid + 1, r, a, b, val);
    else {
    	change(LC, l, mid, a, mid, val);
		change(RC, mid + 1, r, mid + 1, b, val);
	}
	update(k);
}
LL ask(int k, int l, int r, int a, int b) {
	if (l == a && r == b) return t[k];
	if (lz[k] != 0) pushdown(k);
	int mid = (l + r) / 2;
	if (b <= mid) return ask(LC, l, mid, a, b);
    else if (a > mid) return ask(RC, mid + 1, r, a, b);
    else return min(ask(LC, l, mid, a, mid), ask(RC, mid + 1, r, mid + 1, b));
}

vector<int> parse(string s) {
    stringstream ss(s);
    int x;
    vector<int> v;
    while (ss >> x){
        v.pb(x);
    }
    return v;
}

int main() {
    IO;
    cin >> n;
    repn(i, 1, n) cin >> a[i];
    build(1, 1, n);
    cin >> m;
	string s;
	getline(cin, s);
    repn(i, 1, m) {
    	getline(cin, s);
        auto qu = parse(s);
        //repn(i, 1, 4 * n) cout << t[i] << " ";
    	//cout << "\n";
    	if (qu.size() == 3) {
    		int l = qu[0] + 1, r = qu[1] + 1, val = qu[2];
    		if (l <= r) change(1, 1, n, l, r, val);
    		else {
    			change(1, 1, n, 1, r, val);
    			change(1, 1, n, l, n, val);
			}
		}
		else {
			int l = qu[0] + 1, r = qu[1] + 1;
			LL res;
    		if (l <= r) res = ask(1, 1, n, l, r);
    		else {
    			res = ask(1, 1, n, 1, r);
    			res = min(res, ask(1, 1, n, l, n));
			}
			cout << res << "\n";
		}
		
	}
    return 0;
}




