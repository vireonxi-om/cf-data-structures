// Problem: Skyline Photo
// URL: https://codeforces.com/problemset/problem/1484/E
// Rating: 2100
// Tags: data structures, dp
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
int n, h[310000];
ll b[310000], d[1500000], d2[1500000];


ll cal2(int l, int r, int k, int x, int y){
    if(l==x && r==y) return d2[k];
    int mid=(l+r)/2;
    if(y<=mid) return cal2(l, mid, 2*k, x, y);
    else if(x>mid) return cal2(mid+1, r, 2*k+1, x, y);
    else return max(cal2(l, mid, 2*k, x, mid),cal2(mid+1, r, 2*k+1, mid+1, y));
}

void upd2(int l, int r, int k, int pos, ll val){
    if(l==r){ d2[k]=val; return;}
    int mid=(l+r)/2;
    if(mid<pos){ upd2(mid+1, r, 2*k+1, pos, val);}
    else{ upd2(l, mid, 2*k, pos, val);}
    d2[k]=max(d2[2*k], d2[2*k+1]);
}

ll cal(int l, int r, int k, int x, int y){
    if(l==x && r==y) return d[k];
    int mid=(l+r)/2;
    if(y<=mid) return cal(l, mid, 2*k, x, y);
    else if(x>mid) return cal(mid+1, r, 2*k+1, x, y);
    else return max(cal(l, mid, 2*k, x, mid),cal(mid+1, r, 2*k+1, mid+1, y));
}

void update(int l, int r, int k, int pos, ll val){
    if(l==r){ d[k]=val; return;}
    int mid=(l+r)/2;
    if(mid<pos){ update(mid+1, r, 2*k+1, pos, val);}
    else{ update(l, mid, 2*k, pos, val);}
    d[k]=max(d[2*k], d[2*k+1]);
}

int main(){
    for(int i=1; i<1500000; i++) {d[i]=-1e18; d2[i]=0;}
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &h[i]);
    for(int i=1; i<=n; i++) scanf("%lld", &b[i]);
    for(int i=1; i<=n; i++){
        int j=cal2(1, n, 1, 1, h[i]);
        upd2(1, n, 1, h[i], i);
        ll ans;
        if(j==0){
            if(i==1) ans=b[i];
            else ans=max((ll)0, cal(1, n, 1, 1, i-1))+b[i];
        }
        else{
            ans=cal(1, n, 1, j, i-1)+b[i];
            ans=max(ans, cal(1, n, 1, j, j));
        }
        update(1, n, 1, i, ans);
    }
    ll ans=cal(1, n, 1, n, n);
    printf("%lld\n", ans);
}
