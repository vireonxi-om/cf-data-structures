// Problem: Card Deck
// URL: https://codeforces.com/problemset/problem/1492/B
// Rating: 1100
// Tags: data structures, greedy, math
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[110000], m[110000];
vector<int> ans;

void solve(){
    scanf("%d", &n);
    ans.clear();
    a[0]=0;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        m[i]=max(m[i-1], a[i]);
        if(m[i]==a[i]) ans.push_back(i);
    }
    int t=ans.size()-1;
    int last=n+1;
    while(t>=0){
        for(int i=ans[t]; i<last; i++) printf("%d ", a[i]);
        last=ans[t];
        t--;
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
