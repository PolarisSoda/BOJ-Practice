#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 2001;

string str;
int SA[LEN],G[LEN],temp[LEN],LCP[LEN],PFX[LEN];
int len,t;

bool comp(int x,int y) {
    if(G[x] == G[y]) return G[x+t] < G[y+t];
    return G[x] < G[y];
}
void GetSuffix(string str) {
    for(int i=0; i<len; i++) {
        SA[i] = i;
        G[i] = str[i] - 'a';
    }
    while(t <= len) {
        G[len] = -1;
        sort(SA,SA+len,comp);
        temp[SA[0]] = 0;
        for(int i=1; i<len; i++) {
            temp[SA[i]] = temp[SA[i-1]];
            if(comp(SA[i-1],SA[i])) temp[SA[i]]++;
        }
        for(int i=0; i<len; i++) G[i] = temp[i];
        t <<= 1;
    }
}

void GetLCP() {
    for(int i=0, k=0; i<len; i++, k=max(k-1,0)) {
        if(G[i] == len-1) continue;
        for(int j=SA[G[i]+1]; str[i+k] == str[j+k]; k++);
        LCP[G[i]] = k;
    }
}

string solve() {
    int N;
    cin >> N >> str;

    len = str.length(), t = 1;
    memset(SA,0,sizeof(SA));
    memset(temp,0,sizeof(temp));
    memset(G,0,sizeof(G));
    memset(LCP,0,sizeof(LCP));
    memset(PFX,0,sizeof(PFX));

    GetSuffix(str);
    GetLCP();

    for(int i=0; i<len; i++) {
        if(i == 0) PFX[i] = len - SA[i];
        else PFX[i] = PFX[i-1] + len - SA[i] - LCP[i-1];
    }
    if(N > PFX[len-1]) return "none";
    else {
        int idx = lower_bound(PFX,PFX+len,N) - PFX;
        return str.substr(SA[idx],len-SA[idx]-PFX[idx]+N);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " " << solve() << "\n";
    return 0;
}