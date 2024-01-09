// Problem: Tenzing and Triangle
// URL: https://codeforces.com/problemset/problem/1842/E
// Rating: 2300
// Tags: data structures, dp, geometry, greedy, math
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

const int N = 210000;
const int M = 610000;
const int mod = 1e9+7;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n, k;
LL A; 
struct Point {
    int x, y;
    LL c;
    bool operator < (const Point& R) const {
        if (y - R.y == 0)
            return  x - R.x < 0;
        return y - R.y > 0;
    }
}p[N]; 

struct node {
	int len;
	LL num;
	void init(LL val) {
		num = val;
		len = 1;
	}
}tr[M];
struct tag {
	LL num;
	void clear() {
		num = 0;
	}
}lz[M];

node operator + (node a, node b) {
	node res;
	res.num = max(a.num, b.num);
	res.len = a.len + b.len;
	return res;
}

node operator + (tag a, node b) {
	node res = b;
	//if (a.cnt == 0) return res;  // !!!
	res.num += a.num;
	return res;
}

tag operator + (tag a, tag b) {
	tag res = b;
	res.num += a.num;
	return res;
}

void update(int k) {
	tr[k] = tr[LC] + tr[RC];
}
void pushdown(int k) {
	tr[LC] = lz[k] + tr[LC], tr[RC] = lz[k] + tr[RC];
	lz[LC] = lz[k] + lz[LC], lz[RC] = lz[k] + lz[RC];
	lz[k].clear();
}

void build(int k, int l, int r) {
	lz[k].clear();
	if (l == r) {
		tr[k].init((l + 1) * A);    // !!!
		return;
	}
	int mid = (l + r) / 2;
	build(LC, l, mid);
	build(RC, mid + 1, r);
	update(k);
}
void change(int k, int l, int r, int a, int b, tag c) {
	if (l == a && r == b) {
		tr[k] = c + tr[k];
		lz[k] = c + lz[k];
		return;
	}
	pushdown(k);
	int mid = (l + r) / 2;
	if (b <= mid) change(LC, l, mid, a, b, c);
	else if (a > mid) change(RC, mid + 1, r, a, b, c);
	else change(LC, l, mid, a, mid, c), change(RC, mid + 1, r, mid + 1, b, c);
	update(k);
}
node ask(int k, int l, int r, int a, int b) {
	if (l == a && r == b) return tr[k];
	int mid = (l + r) / 2;
	pushdown(k);
	if (b <= mid) return ask(LC, l, mid, a, b);
	else if (a > mid) return ask(RC, mid + 1, r, a, b);
	else return ask(LC, l, mid, a, mid) + ask(RC, mid + 1, r, mid + 1, b);
}

LL f[N];
int main()
{
	IO;
	cin >> n >> k >> A;
	k += 2; 
	LL ans = 0;
	repn(i, 1, n) {
		cin >> p[i].x >> p[i].y >> p[i].c;
		p[i].x ++; p[i].y ++;
		ans += p[i].c;
	}
	sort(p + 1, p + n + 1);
	build(1, 0, k);
	int pos = 1;
	repn(i, 1, k - 1) {
		while (pos <= n && p[pos].y == k - i) {
			tag cur; cur.num = p[pos].c;
			change(1, 0, k, 0, p[pos].x - 1, cur);
			pos ++;
		}
		if (i > 1) {
			node cur = ask(1, 0, k, 0, i - 2);
			f[i] = max(f[i], cur.num - i * A);
		}
		f[i] = max(f[i], f[i - 1]);
		tag cur; cur.num = f[i];
		change(1, 0, k, i, i, cur);
	}
	ans -= f[k - 1];
	cout << ans << "\n";
	return 0;
}