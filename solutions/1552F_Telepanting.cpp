// Problem: Telepanting
// URL: https://codeforces.com/problemset/problem/1552/F
// Rating: 2200
// Tags: binary search, data structures, dp, sortings
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
const LL p = 998244353;

struct tele {
    LL x, y, st;
} t[N];

int n;
LL sum;
priority_queue<pair<LL, LL>> l;

int main(){
    scanf("%d", &n);
    repn(i, 1, n) scanf("%lld%lld%lld", &t[i].x, &t[i].y, &t[i].st);
    LL ans = (t[n].x + 1) % p;
    pern(i, 1, n){
        while (!l. empty()) {
            if (l.top().first <= t[i].x) break;
            sum -= l.top().second; sum = (sum + p) % p;
            l.pop();
        }
        LL now = sum;
        if (t[i].st) now ++;
        now %= p;
        LL tot = (now * (t[i].x - t[i].y)) % p;
        l.push(make_pair(t[i].y, now));
        sum += now; sum %= p;
        ans += tot; ans %= p;
    }
    printf("%lld\n", ans);
    return 0;
}
// maintenance note (2): add edge-case comment to this file — 2026-08-23
