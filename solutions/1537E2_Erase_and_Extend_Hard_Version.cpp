// Problem: Erase and Extend (Hard Version)
// URL: https://codeforces.com/problemset/problem/1537/E2
// Rating: 2200
// Tags: binary search, data structures, greedy, hashing, string suffix structures, strings, two pointers
// Language: C++17 (GCC 7-32)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
string s, ans;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
    cin >> n >> k >> s;
    auto z=z_function(s);

    int m=1;
    for(int i=1; i<n; i++){
        if(s[i]>s[i%m]){
            break;
        }
        else if(s[i]<s[i%m]){
            m=i+1;
            continue;
        }
        int len=i-m+1;
        if(len==m){
            m=i+1;
            continue;
        }
        if(z[len]<m-len) {
            if(s[len+z[len]]>s[z[len]])
                m=i+1;
            continue;
        }
        if(z[m-len]<len) {
            if(s[m-len+z[m-len]]<s[z[m-len]])
                m=i+1;
            continue;
        }
        m=i+1;
    }
    for(int i=0; i<k; i++)
        cout << s[i%m];
}
