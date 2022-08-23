// Problem: Robot Collisions
// URL: https://codeforces.com/problemset/problem/1525/C
// Rating: 2000
// Tags: data structures, greedy, implementation, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, t[310000], p[310000];
vector<pair<pair<int, int>, int>> r[2];
set<pair<int, int>> s[2];

void solve(){
    scanf("%d%d", &n, &m);
    r[0].clear(); r[1].clear();
    s[0].clear(); s[1].clear();
    for(int i=1; i<=n; i++) scanf("%d", &p[i]);
    char c;
    for(int i=1; i<=n; i++){
        scanf("%c", &c);
        scanf("%c", &c);
        if(c=='R'){
            if(p[i]%2) r[1].push_back(make_pair(make_pair(p[i], i), 1));
            else r[0].push_back(make_pair(make_pair(p[i], i), 1));
        }
        else{
            if(p[i]%2) s[1].insert(make_pair(p[i], i));
            else s[0].insert(make_pair(p[i], i));
        }
    }
    int tot;
    for(int i=0; i<=1; i++){
        sort(r[i].begin(), r[i].end());
        auto item =r[i].end();
        if(!r[i].empty()){
            item--;
            for(; item>=r[i].begin(); item--){
                auto x=(*item);
                int rval=x.first.first;
                auto it=s[i].upper_bound(make_pair(rval, 0));
                if(it==s[i].end()) continue;
                tot=((*it).first-rval)/2;
                t[(*it).second]=tot; t[x.first.second]=tot;
                r[i][item-r[i].begin()].second=0; s[i].erase(it);
            }
        }
        auto it1=s[i].begin(), it2=s[i].begin();
        if(it2!=s[i].end()) it2++;
        while(it1!=s[i].end() && it2!=s[i].end()){
            tot=((*it1).first+(*it2).first)/2;
            t[(*it1).second]=tot; t[(*it2).second]=tot;
            it1++; it1++; it2++;
            if(it2!=s[i].end()) it2++;
        }
        if(it1!=s[i].end()) r[i].push_back(make_pair(make_pair(-(*it1).first, (*it1).second), 1));
        s[i].clear();
        for(auto x:r[i]){
            if(x.second) s[i].insert(make_pair(-x.first.first, x.first.second));
        }
        it1=s[i].begin(), it2=s[i].begin();
        if(it2!=s[i].end()) it2++;
        while(it1!=s[i].end() && it2!=s[i].end()){
            tot=m+((*it1).first+(*it2).first)/2;
            t[(*it1).second]=tot; t[(*it2).second]=tot;
            it1++; it1++; it2++;
            if(it2!=s[i].end()) it2++;
        }
        if(it1!=s[i].end()) t[(*it1).second]=-1;
    }
    for(int i=1; i<=n; i++) printf("%d ", t[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}