// Problem: GCD of an Array
// URL: https://codeforces.com/problemset/problem/1493/D
// Rating: 2100
// Tags: brute force, data structures, hashing, implementation, math, number theory, sortings, two pointers
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
const int N=210000;
const int M=19000100;
const ll mod=1e9+7;

int root[N],n,q,nu[N],pos;
int mn[M],ch[M][2];
ll ans=1;

void change(int k, int l, int r, int x, int t){
    if(l==r){
        mn[k]+=t;
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid) change(ch[k][0]?ch[k][0]:ch[k][0]=++pos, l, mid, x, t);
    else change(ch[k][1]?ch[k][1]:ch[k][1]=++pos, mid+1, r, x, t);
    mn[k]=min(mn[ch[k][0]], mn[ch[k][1]]);
}

void work(int p, int num){
    for(int i=2; i<=sqrt(num); i++){
        if(num%i) continue;
        int cnt=0;
        while(num%i==0){
            num/=i;
            cnt++;
        }
        change(root[i], 1, n, p, cnt);
        for(int j=nu[i]+1; j<=mn[root[i]]; j++){ ans*=i; ans%=mod;}
        nu[i]=mn[root[i]];
    }
    if(num>1){
        change(root[num], 1, n, p, 1);
        for(int j=nu[num]+1; j<=mn[root[num]]; j++){ ans*=num; ans%=mod;}
        nu[num]=mn[root[num]];
    }
}

int main(){
    scanf("%d %d",&n,&q);
    for(int i=1; i<N; i++) root[i]=++pos;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        work(i,x);
    }
    while (q--)
    {
        int pos,x;
        scanf("%d %d",&pos,&x);
        work(pos,x);
        printf("%I64d\n",ans);
    }
    return 0;
}