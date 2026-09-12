// Problem: Diluc and Kaeya
// URL: https://codeforces.com/problemset/problem/1536/C
// Rating: 1500
// Tags: data structures, dp, hashing, number theory
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, ans[510000];
char a[510000];
set<pair<pair<int, int>, int>> s;

int gcd(int x, int y){
    return y==0? x: gcd(y, x%y);
}

void solve(){
    s.clear();
    scanf("%d%s", &n, a+1);
    int d=0, k=0, num1, num2;
    for(int i=1; i<=n; i++){
        if(a[i]=='D') d++;
        else k++;
        if(d==0){ num1=0; num2=1;  }
        else if(k==0){ num1=1; num2=0;  }
        else{
            num1=d; num2=k;
            num1/=gcd(d, k); num2/=gcd(d, k);
        }
        s.insert(make_pair(make_pair(num1, num2), i));
        auto it=s.lower_bound(make_pair(make_pair(num1, num2), i));
        if(it==s.begin()) ans[i]=1;
        else {
            it--;
            if((*it).first.first==num1 && (*it).first.second==num2){
                ans[i]=ans[(*it).second]+1;
            }
            else ans[i]=1;
        }
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}


// maintenance note (10): note time complexity in this file — 2026-09-12
