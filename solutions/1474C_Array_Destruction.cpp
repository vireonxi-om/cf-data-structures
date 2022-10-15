// Problem: Array Destruction
// URL: https://codeforces.com/problemset/problem/1474/C
// Rating: 1700
// Tags: brute force, constructive algorithms, data structures, greedy, implementation, sortings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, a[2100], b[2100], used[2100], result;
vector<pair<int, int>> ans;

void solve(){
    scanf("%d", &n);
    for(int i=1; i<=2*n; i++){
        scanf("%d", &a[i]);
        b[i]=a[i];
    }
    sort(b+1, b+2*n+1);
    bool yes=false;
    for(int i=1; i<2*n; i++){
        ans.clear();
        for(int j=1; j<=2*n; j++) used[j]=0;
        result=b[i]+b[2*n];
        used[i]=1; used[2*n]=1;
        ans.push_back(make_pair(b[i], b[2*n]));
        int now=b[2*n], pos=2*n;
        bool can=true;
        while(pos>=1){
            while(used[pos]==1){
                if(pos<=1) break;
                else pos--;
            }
            //printf("%d %d %d\n", i, pos, now);
            if(pos<=1) break;
            used[pos]=1;
            auto next=lower_bound(b+1, b+2*n+1, now-b[pos]);
            while(used[next-b] && next<=b+2*n) next++;
            if(next==b+2*n+1 || (*next)!=now-b[pos]){ can=false; break;}
            else{

                used[pos]=1; used[next-b]=1;
                now=b[pos];
                ans.push_back(make_pair((*next), b[pos]));
            }
        }
        if(can){ yes=true; break;}
    }
    if(yes){
        printf("YES\n");
        printf("%d\n", result);
        for(auto x:ans) printf("%d %d\n", x.first, x.second);
    }
    else printf("NO\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
