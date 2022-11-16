// Problem: Minimum Grid Path
// URL: https://codeforces.com/problemset/problem/1499/C
// Rating: 1500
// Tags: brute force, data structures, greedy, math
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n;
ll a[110000];

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    ll min0=a[2], sum0=a[2], min1=a[1], sum1=a[1], cnt0=1, cnt1=1;
    ll ans=(a[1]+a[2])*n;
    for(int i=3; i<=n; i++){
        if(i%2==0){
            sum0+=a[i];
            min0=min(min0, a[i]);
            cnt0++;
        }
        else{
            sum1+=a[i];
            min1=min(min1, a[i]);
            cnt1++;
        }
        ans=min(ans, (n-cnt0)*min0+(n-cnt1)*min1+sum0+sum1);
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
