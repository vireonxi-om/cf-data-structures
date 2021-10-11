// Problem: Omkar and Medians
// URL: https://codeforces.com/problemset/problem/1536/D
// Rating: 2000
// Tags: data structures, greedy, implementation
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[210000];
set<int> s;

void solve(){
    s.clear();
    scanf("%d", &n);
    bool can, yes=true;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        s.insert(a[i]);
        if(i>1){
            can=false;
            auto it=s.find(a[i]);
            if((*it)==a[i-1]) can=true;
            if(it!=s.begin()){
                it--;
                if((*it)==a[i-1]) can=true;
            }
            it=s.find(a[i]);
            if(it!=s.end()){
                it++;
                if(it!=s.end() && (*it)==a[i-1]) can=true;
            }
            if(!can) yes=false;
        }
    }
    if(yes) printf("YES\n");
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}


