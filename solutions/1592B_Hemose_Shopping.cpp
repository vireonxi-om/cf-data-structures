// Problem: Hemose Shopping
// URL: https://codeforces.com/problemset/problem/1592/B
// Rating: 1200
// Tags: constructive algorithms, dsu, math, sortings
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

const int N = 110000;
const int M = 1100000;
const int mod = 1000000007;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;
const int maxn = 100010;

int n, x, a[N], b[N];

void solve(){
    scanf("%d%d", &n, &x);
    repn(i, 1, n){ scanf("%d", &a[i]); b[i] = a[i];}
    sort(b + 1, b + n + 1);
    int l = n - x + 1, r = x;
    bool can = true;
    if (l <= r) {
        repn(i, l, r) {
            if (b[i] != a[i]){ can = false; break;}
        }
    }
    if(can) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
// maintenance note (3): add edge-case comment to this file — 2026-08-25
