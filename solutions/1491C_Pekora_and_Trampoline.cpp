// Problem: Pekora and Trampoline
// URL: https://codeforces.com/problemset/problem/1491/C
// Rating: 1700
// Tags: brute force, data structures, dp, greedy, implementation
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[5100], b[5100];

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        b[i]=a[i];
    }
    int pos=1;
    ll cnt=0;
    while(pos<=n){
        cnt+=a[pos]-1;
        int t=0, i=pos+2;
        for(; i<=min(n, pos+b[pos]); i++){
            t++;
            if(a[i]-t<1){ t-=(a[i]-1); a[i]=1;}
            else { a[i]-=t; t=0;}
        }
        while(t && i<=n){
            if(a[i]-t<1){ t-=(a[i]-1); a[i]=1;}
            else { a[i]-=t; t=0;}
            i++;
        }
        pos++;
    }
    printf("%lld\n", cnt);
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
