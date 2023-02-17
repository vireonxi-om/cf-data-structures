// Problem: Decomposition
// URL: https://codeforces.com/problemset/problem/1766/E
// Rating: 2300
// Tags: binary search, brute force, data structures, divide and conquer, dp, two pointers
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

const int N = 310000;
const int M = 11000000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-10;
const long long INF = (long long)1e18;

int n, a[N];
long long dp[N][4][4][4], nxt[4][4][4];

int main() {
    IO;
    int n; 
    cin >> n;
    repn(i, 1, n) cin >> a[i];
    long long ans = 0;
    repn(i, 1, n) {
        dp[i - 1][0][0][0] += 1;
        if (a[i] == 0) {
            repn(q1, 0, 3) {
                repn(q2, 0, 3) {
                    repn(q3, 0, 3) {
                        dp[i][q1][q2][q3] = dp[i - 1][q1][q2][q3];
                        if (q1) ans += dp[i][q1][q2][q3];
                        if (q2) ans += dp[i][q1][q2][q3];
                        if (q3) ans += dp[i][q1][q2][q3];
                    }
                }
            }
            ans += (long long)i * (n - i + 1);
            continue;
        }
        repn(q1, 0, 3) {
            repn(q2, 0, 3) {
                repn(q3, 0, 3) {
                    int t1 = q1, t2 = q2, t3 = q3;
                    if (a[i] == 1) {
                        if (q1 != 2) t1 = 1;
                        else if (q2 != 2) t2 = 1;
                        else if (q3 != 2) t3 = 1;
                    }
                    else if (a[i] == 2) {
                        if (q1 != 1) t1 = 2;
                        else if (q2 != 1) t2 = 2;
                        else if (q3 != 1) t3 = 2;          
                    }
                    else {
                        t1 = 3;
                    }
                    dp[i][t1][t2][t3] += dp[i - 1][q1][q2][q3];
                }
            }
        }
        repn(q1, 0, 3) {
            repn(q2, 0, 3) {
                repn(q3, 0, 3) {
                    if (q1) ans += dp[i][q1][q2][q3];
                    if (q2) ans += dp[i][q1][q2][q3];
                    if (q3) ans += dp[i][q1][q2][q3];
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}



