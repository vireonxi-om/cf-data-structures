// Problem: Potions (Easy Version)
// URL: https://codeforces.com/problemset/problem/1526/C1
// Rating: 1500
// Tags: brute force, data structures, dp, greedy
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[2100], dp[2100][2100];

int main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%lld", &a[i]);
    }
    for(int i=0; i<=n; i++) for(int j=1; j<=n; j++) dp[i][j]=-1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dp[i-1][j]>=0) dp[i][j]=max(dp[i][j], dp[i-1][j]);
            if(dp[i-1][j-1]>=0) dp[i][j]=max(dp[i][j], dp[i-1][j-1]+a[i]);
        }
    }
    int cnt=0;
    for(int i=0; i<=n; i++){
        if(dp[n][i]>=0) cnt=i;
    }
    printf("%d\n", cnt);
    return 0;
}


