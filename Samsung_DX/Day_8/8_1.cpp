#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 10000;

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

string solve() {
    int N;
    cin >> N >> str;
    
    len = str.length();
    t = 1;
    memset(SA,0,sizeof(SA));
    memset(temp,0,sizeof(temp));
    memset(G,0,sizeof(G));

    GetSuffix(str);
    if(N > len) return "none";
    else return str.substr(SA[N-1]);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " " << solve() << "\n";
    return 0;
}