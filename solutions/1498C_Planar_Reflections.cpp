// Problem: Planar Reflections
// URL: https://codeforces.com/problemset/problem/1498/C
// Rating: 1600
// Tags: brute force, data structures, dp
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, k;
ll ans, a[1100], b[1100];
const int M=1000000007;

void solve(){
    scanf("%d%d", &n, &k);
    if(k==1) ans=1;
    else ans=1+n;
    for(int i=2; i<=n; i++) a[i]=1;
    a[1]=0; b[1]=0;
    for(int i=2; i<=n; i++) b[i]=a[i]+b[i-1];
    for(int i=3; i<=k; i++){
        if(i%2==0){
            for(int j=1; j<=n; j++) a[j]=b[j];
            b[1]=0;
            for(int j=2; j<=n; j++){ b[j]=b[j-1]+a[j-1]; b[j]%=M;}
            ans+=b[n];
            ans%=M;
        }
        else{
            for(int j=1; j<=n; j++) a[j]=b[j];
            b[n]=0;
            for(int j=n-1; j>=1; j--){ b[j]=b[j+1]+a[j+1]; b[j]%=M;}
            ans+=b[1];
            ans%=M;

        }
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}


