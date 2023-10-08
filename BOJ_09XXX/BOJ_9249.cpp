#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 200002;

string str;
int SA[LEN],G[LEN],temp[LEN],LCP[LEN];
int len,t = 1;

bool comp(int x,int y) {
    if(G[x] == G[y]) return G[x+t] < G[y+t];
    return G[x] < G[y];
}
void GetSuffix(string str) {
    for(int i=0; i<len; i++) {
        SA[i] = i;
        G[i] = str[i];
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
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string A,B;
    cin >> A >> B;
    int al = A.length();
    int ml = min(al,(int)B.length());

    str = A + "A" + B;
    len = str.length();
    GetSuffix(str);
    GetLCP();

    int ans = 0;
    string anstr;
    for(int i=0; i<len; i++) {
        bool f = SA[i] < al;
        bool s = SA[i+1] < al;
        if(f^s == true) {
            if(LCP[i] <= ml && ans < LCP[i]) {
                ans = LCP[i];
                anstr = str.substr(SA[i],ans);
            }
        }
    }
    cout << ans << "\n" << anstr;
    return 0;
}