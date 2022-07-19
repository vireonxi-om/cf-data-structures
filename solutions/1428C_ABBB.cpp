// Problem: ABBB
// URL: https://codeforces.com/problemset/problem/1428/C
// Rating: 1100
// Tags: brute force, data structures, greedy, strings
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
char s[210000];

void solve(){
    scanf("%s", &s);
    int l=strlen(s), cnt=0;
    for(int i=l-1; i>=0; i--){
        if(s[i]=='B') cnt++;
        else if(cnt>0){
            cnt--;
            l-=2;
        }
    }
    if(cnt>=2) l-=(cnt-cnt%2);
    printf("%d\n", l);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
