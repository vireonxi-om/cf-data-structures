// Problem: Box Fitting
// URL: https://codeforces.com/problemset/problem/1498/B
// Rating: 1300
// Tags: binary search, bitmasks, data structures, greedy
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, w;
multiset<int> s;

void solve(){
    scanf("%d%d", &n, &w);
    s.clear();
    int num;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        s.insert(num);
    }
    int t=0;
    while(!s.empty()){
        int now=w;
        while(!s.empty() && (*s.begin())<=now){
            auto it=s.upper_bound(now);
            it--;
            now-=(*it);
            s.erase(it);
        }
        t++;
    }
    printf("%d\n", t);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}


