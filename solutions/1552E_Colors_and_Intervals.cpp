// Problem: Colors and Intervals
// URL: https://codeforces.com/problemset/problem/1552/E
// Rating: 2300
// Tags: constructive algorithms, data structures, greedy, sortings
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
const int M = 650;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const LL INF = 1e15;

int n, k;
int ans[110], t[11000], col[110][110], cnt[110];

struct intv {
    int a, b, id;
    friend bool operator < (intv x, intv y) {
        if(x.b < y.b) return true;
        else return false;
    }
} p[11000];

int main(){
    scanf("%d%d", &n, &k);
    int num;
    repn(i, 1, n * k) {
        scanf("%d", &num);
        col[num][++cnt[num]] = i;
    }
    int now = 0;
    repn(i, 1, n){
        repn(j, 2, k) {
            p[++now].a = col[i][j-1];
            p[now].b = col[i][j];
            p[now].id = i;
        }
    }
    sort(p + 1, p + n * (k - 1) + 1);
    int r = (n + k - 2) / (k - 1);
    repn(i, 1, n * (k - 1)) {
        if (ans[p[i].id]) continue;
        int a = p[i].a, b = p[i].b, c = p[i].id;
        bool yes=true;
        repn(j, a, b) {
            if (t[j] >= r) yes = false;
        }
        if(yes) {
            ans[c] = i;
            repn(j, a, b) t[j]++;
        }
    }
    repn(i, 1, n) {
        printf("%d %d\n", p[ans[i]].a, p[ans[i]].b);
    }
    return 0;
}
