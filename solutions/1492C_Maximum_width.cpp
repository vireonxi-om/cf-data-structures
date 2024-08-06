// Problem: Maximum width
// URL: https://codeforces.com/problemset/problem/1492/C
// Rating: 1500
// Tags: binary search, data structures, dp, greedy, two pointers
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, m, a[210000], b[210000];
char s[210000], t[210000];

int main(){
    scanf("%d%d", &n, &m);
    scanf("%s%s", s+1, t+1);
    for(int i=1; i<=m; i++){
        for(int j=a[i-1]+1; j<=n; j++){
            if(s[j]==t[i]){
                a[i]=j; break;
            }
        }
    }
    b[m+1]=n+1;
    for(int i=m; i>=1; i--){
        for(int j=b[i+1]-1; j>=1; j--){
            if(s[j]==t[i]){
                b[i]=j; break;
            }
        }
    }
    int ans=0;
    for(int i=1; i<m; i++){
        ans=max(ans, b[i+1]-a[i]);
    }
    printf("%d\n", ans);
}
