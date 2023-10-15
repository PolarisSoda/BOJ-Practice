#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int LEN = 90001;

int SA[LEN],G[LEN],temp[LEN],LCP[LEN],t;
ll PFX[LEN];

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

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string str;
    int Q;
    cin >> str >> Q;
    int len = str.length();
    GetSuffix(str,len);
    GetLCP(str,len);

    for(int i=0; i<len; i++) {
        if(i == 0) PFX[i] = len - SA[i];
        else PFX[i] = PFX[i-1] + len - SA[i] - LCP[i-1];
    }
    for(int i=0; i<Q; i++) {
        ll K;
        cin >> K;
        if(K > PFX[len-1]) cout << "-1\n";
        else {
            int idx = lower_bound(PFX,PFX+len,K) - PFX;
            cout << str.substr(SA[idx],len-SA[idx]-PFX[idx]+K) << "\n";
        }
    }
    return 0;
}