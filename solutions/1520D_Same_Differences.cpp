// Problem: Same Differences
// URL: https://codeforces.com/problemset/problem/1520/D
// Rating: 1200
// Tags: data structures, hashing, math
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[210000];
ll sum[210000];

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){ scanf("%d", &a[i]); a[i]-=i;}
    sort(a+1, a+n+1);
    int cnt=1; ll ans=0;
    for(int i=2; i<=n; i++){
        if(a[i]!=a[i-1]){
            ans+=sum[cnt-1];
            cnt=1;
        }
        else cnt++;
    }
    ans+=sum[cnt-1];
    printf("%lld\n", ans);
}

int main(){
    for(int i=1; i<=200010; i++) sum[i]=sum[i-1]+i;
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}


