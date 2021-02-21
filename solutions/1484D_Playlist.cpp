// Problem: Playlist
// URL: https://codeforces.com/problemset/problem/1484/D
// Rating: 1900
// Tags: data structures, dsu, implementation
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[110000];
set<int> r;
set<pair<int, int>> b;
vector<int> ans;

int gcd(int x, int y){
    return y==0? x: gcd(y, x%y);
}

void solve(){
    scanf("%d", &n);
    r.clear(); b.clear(); ans.clear();
    for(int i=1; i<=n; i++){  scanf("%d", &a[i]); r.insert(i);}
    for(int i=1; i<n; i++){
        if(gcd(a[i], a[i+1])==1){
            b.insert(make_pair(i, i+1));
        }
    }
    if(gcd(a[n], a[1])==1) b.insert(make_pair(n, 1));
    int now=(*r.begin());
    while(!b.empty()){
        //printf("now: %d\n", now);
        //for(auto x: b) printf("%d %d   ", x.first, x.second); printf("\n");
        auto it=b.lower_bound(make_pair(now, -1));
        if(it==b.end()){
            now=(*r.begin());
            continue;
        }
        //printf("it: %d %d\n", (*it).first, (*it).second);
        auto nxt=r.upper_bound((*it).second);
        r.erase((*it).second);
        ans.push_back((*it).second);
        //for(auto x: ans) printf("%d ", x); printf("\n");
        if(nxt!=r.end()){
            now=(*nxt);
        }
        else{
            if(r.empty()) break;
            else now=(*r.begin());
        }
        b.erase(make_pair((*it).second, now));
        if(gcd(a[(*it).first], a[now])==1){
            b.insert(make_pair((*it).first, now));
        }
        b.erase(it);
    }
    printf("%d ", ans.size());
    for(auto x: ans) printf("%d ", x); printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

