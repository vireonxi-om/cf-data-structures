// Problem: Phoenix and Towers
// URL: https://codeforces.com/problemset/problem/1515/C
// Rating: 1400
// Tags: constructive algorithms, data structures, greedy
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k, a[110000];
set<pair<int, int>> s;

void solve(){
    scanf("%d%d%d", &n, &m, &k);
    s.clear();
    for(int i=1; i<=m; i++) s.insert(make_pair(0, i));
    int num;
    for(int i=1; i<=n; i++){
        scanf("%d", &num);
        auto it=s.begin();
        int x=(*it).first, y=(*it).second;
        x+=num;
        a[i]=y;
        s.erase(it);
        s.insert(make_pair(x, y));
    }
    printf("YES\n");
    for(int i=1; i<=n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}

