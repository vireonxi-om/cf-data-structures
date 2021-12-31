// Problem: Number of Pairs
// URL: https://codeforces.com/problemset/problem/1538/C
// Rating: 1300
// Tags: binary search, data structures, math, two pointers
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll l, r, num;
vector<ll> a;

void solve(){
    scanf("%d%lld%lld", &n, &l, &r);
    a.clear();
    for(int i=1; i<=n; i++){
        scanf("%lld", &num);
        a.push_back(num);
    }
    sort(a.begin(), a.end());
    ll x, y, tot=0;
    for(auto t: a){
        x=max((ll)0, l-t); y=max((ll)0, r-t);
        auto it1=lower_bound(a.begin(), a.end(), x), it2=upper_bound(a.begin(), a.end(), y);
        ll ans=it2-it1;
        if(x<=t && y>=t) ans--;
        tot+=ans;
    }
    printf("%lld\n", tot/2);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
