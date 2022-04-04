// Problem: Guess the K-th Zero (Hard version)
// URL: https://codeforces.com/problemset/problem/1520/F2
// Rating: 2200
// Tags: binary search, constructive algorithms, data structures, interactive
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, t, k, num;
vector<pair<int, int>> a;

void solve(){
    auto it=lower_bound(a.begin(), a.end(), make_pair(k, 0));
    int r=(*it).second;
    auto it1=it; it1--;
    int l=(*it1).second, ans;
    l=max(1, l);
    while(l<=r){
        int mid=(l+r)/2;
        printf("? %d %d\n", 1, mid);
        fflush(stdout);
        scanf("%d", &num);
        if(mid-num==k) ans=mid;
        if(mid-num>=k) r=mid-1;
        else l=mid+1;
    }
    while(it!=a.end()){
        (*it).first--;
        it++;
    }
    printf("! %d\n", ans);
    fflush(stdout);
}

int main(){
    scanf("%d%d%d", &n, &t, &k);
    a.push_back(make_pair(0, 0));
    for(int i=1; i<=n; i+=10){
        printf("? %d %d\n", 1, i);
        fflush(stdout);
        scanf("%d", &num);
        a.push_back(make_pair(i-num, i));
        if(i<n && i+10>n) i=n-10;
    }
    solve();
    for(int i=2; i<=t; i++){
        scanf("%d", &k);
        solve();
    }
    return 0;
}


