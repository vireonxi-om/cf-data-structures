// Problem: Integers Have Friends
// URL: https://codeforces.com/problemset/problem/1549/D
// Rating: 1800
// Tags: binary search, data structures, math, two pointers
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
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;

int n, ans, cur;
LL a[N], b[N], g[M], c[N][25];

LL gcd(LL a, LL b) {
    return b==0? a:gcd(b, a%b);
}

void update(int k) {
    g[k] = gcd(g[LC], g[RC]);
}

void build(int k, int l, int r) {
    if (l == r) {
        g[k] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(LC, l, mid);
    build(RC, mid + 1, r);
    update(k);
}

LL ask(int k, int l, int r, int a, int b) {
    if (l == a && r == b) return g[k];
    int mid = (l + r) / 2;
    LL res;
    if (b <= mid) res = ask(LC, l, mid, a, b);
    else if (a > mid) res = ask(RC, mid + 1, r, a, b);
    else res = gcd(ask(LC, l, mid, a, mid), ask(RC, mid + 1, r, mid + 1, b));
    return res;
}


void solve(){
    scanf("%d", &n);
    ans = 0;
    repn(i, 1, n) scanf("%lld", &b[i]);
    if (n == 1) {
        printf("1\n");
        return;
    }
    rep(i, 1, n) a[i] = abs(b[i+1] - b[i]);
    n --;
    build(1, 1, n);
    repn(i, 1, n) repn(j, 0, 20) c[i][j] = 1;
    repn(i, 1, n) {
        repn(now, 0, 20) {
            if (i + (1 << now) > n) break;
            c[i][now] = ask(1, 1, n, i, i + (1 << now));
        }
    }
    ans = 0;
    repn(i, 1, n) {
        LL r = a[i];
        if (r == 1) continue;
        int pos = i;
        pern(now, 0, 20) {
            if (pos + (1 << now) > n) continue;
            LL nr = gcd(r, c[pos][now]);
            if (nr == 1) continue;
            r = nr; pos += (1 << now);
        }
        ans = max(ans, pos - i + 1);
    }
    printf("%d\n", ans + 1);
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
