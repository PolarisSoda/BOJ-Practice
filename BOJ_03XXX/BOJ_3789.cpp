#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 200001;

int SA[LEN],G[LEN],temp[LEN],LCP[LEN],t;

bool comp(int x,int y) {
    if(G[x] == G[y]) return G[x+t] < G[y+t];
    return G[x] < G[y];
}
void GetSuffix(string str,int len) {
    for(int i=0; i<len; i++) {
        SA[i] = i;
        G[i] = str[i];
    }
    for(t=1; t <=len; t<<=1) {
        G[len] = -1;
        sort(SA,SA+len,comp);
        temp[SA[0]] = 0;
        for(int i=1; i<len; i++) {
            temp[SA[i]] = temp[SA[i-1]];
            if(comp(SA[i-1],SA[i])) temp[SA[i]]++;
        }
        for(int i=0; i<len; i++) G[i] = temp[i];
    }
}

void GetLCP(string str,int len) {
    for(int i=0, k=0; i<len; i++, k=max(k-1,0)) {
        if(G[i] == len-1) continue;
        for(int j=SA[G[i]+1]; str[i+k] == str[j+k]; k++);
        LCP[G[i]] = k;
    }
}
void solve() {
    string str;
    int L;
    cin >> L >> str;

    str = str + str;
    int len = L<<1;

    GetSuffix(str,len);
    GetLCP(str,len);

    int ans = -1;
    string prev;
    for(int i=0; i<len; i++) {
        if(SA[i] < L) {
            if(ans == -1) {
                ans = SA[i];
                prev = str.substr(SA[i],L);
            } else {
                string now = str.substr(SA[i],L);
                if(prev == now) ans = SA[i];
                else break;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) solve();
}