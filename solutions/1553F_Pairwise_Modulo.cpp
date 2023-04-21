// Problem: Pairwise Modulo
// URL: https://codeforces.com/problemset/problem/1553/F
// Rating: 2300
// Tags: data structures, math
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


int n, m;
LL a[N], p[N], b[N];
LL sum[M], cnt[M], lz[M], lz1[M];


void update(int k) {
    sum[k] = (sum[LC] + sum[RC]);
}
void pushdown(int k, int l, int r) {
    if (lz[k]) {
        int mid = (l + r) / 2;
        sum[LC] = (sum[LC] + (LL)(mid - l + 1) * lz[k]);
        lz[LC] = (lz[LC] + lz[k]);
        sum[RC] = (sum[RC] + (LL)(r - mid) * lz[k]);
        lz[RC]= (lz[RC] + lz[k]);
        lz[k] = 0;
    }
}
void change(int k, int l, int r, int a, int b, int c) {
    if (l == a && r == b) {
        sum[k] = (sum[k] + (LL)(r - l + 1) * c);
        lz[k] = (lz[k] + c);
        return;
    }
    int mid = (l + r) / 2;
    pushdown(k, l, r);
    if (b <= mid) change(LC, l, mid, a, b, c);
    else if (a > mid) change(RC, mid + 1, r, a, b, c);
    else change(LC, l, mid, a, mid, c), change(RC, mid + 1, r, mid + 1, b, c);
    update(k);
}
LL ask(int k, int l, int r, int a, int b) {
    if (l == a && r == b) return sum[k];
    int mid = (l + r) / 2;
    pushdown(k, l, r);
    LL res = 0;
    if (b <= mid) res = ask(LC, l, mid, a, b);
    else if (a > mid) res = ask(RC, mid + 1, r, a, b);
    else res = (ask(LC, l, mid, a, mid) + ask(RC, mid + 1, r, mid + 1, b));
    update(k);
    return res;
}


void update1(int k) {
    cnt[k] = (cnt[LC] + cnt[RC]);
}
void pushdown1(int k, int l, int r) {
    if (lz1[k]) {
        int mid = (l + r) / 2;
        cnt[LC] = (cnt[LC] + (LL)(mid - l + 1) * lz1[k]);
        lz1[LC] = (lz1[LC] + lz1[k]);
        cnt[RC] = (cnt[RC] + (LL)(r - mid) * lz1[k]);
        lz1[RC]= (lz1[RC] + lz1[k]);
        lz1[k] = 0;
    }
}
void change1(int k, int l, int r, int a, int b, int c) {
    if (l == a && r == b) {
        cnt[k] = (cnt[k] + (LL)(r - l + 1) * c);
        lz1[k] = (lz1[k] + c);
        return;
    }
    int mid = (l + r) / 2;
    pushdown1(k, l, r);
    if (b <= mid) change1(LC, l, mid, a, b, c);
    else if (a > mid) change1(RC, mid + 1, r, a, b, c);
    else change1(LC, l, mid, a, mid, c), change1(RC, mid + 1, r, mid + 1, b, c);
    update1(k);
}
LL ask1(int k, int l, int r, int a, int b) {
    if (l == a && r == b) return cnt[k];
    int mid = (l + r) / 2;
    pushdown1(k, l, r);
    LL res = 0;
    if (b <= mid) res = ask1(LC, l, mid, a, b);
    else if (a > mid) res = ask1(RC, mid + 1, r, a, b);
    else res = (ask1(LC, l, mid, a, mid) + ask1(RC, mid + 1, r, mid + 1, b));
    update1(k);
    return res;
}

int main(){
    scanf("%d", &n);
    LL ans = 0;
    m = 310000;
    repn(i, 1, n){
        scanf("%lld", &a[i]);
        if (i > 1) b[i - 1] = b[i - 2] + a[i - 1];
        ans += b[i - 1];
        ans += a[i] * (i - 1);
        ans -= ask(1, 1, m, a[i], a[i]);
        repn(t, 1, m) {
            if (a[i] * t > m) break;
            change(1, 1, m, a[i] * t, min(m, (int)a[i] * (t + 1) - 1), a[i] * t);
        }
        repn(t, 1, m) {
            if (a[i] * t > m) break;
            LL now = ask1(1, 1, m, a[i] * t, min(m, (int)a[i] * (t + 1) - 1));
            ans -= a[i] * t * now;
        }
        change1(1, 1, m, a[i], a[i], 1);
        p[i] = ans;
    }
    repn(i, 1, n) printf("%lld ", p[i]);
    printf("\n");
    return 0;
}

