#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr int LEN = 100001;

string str;
int SA[LEN],G[LEN],temp[LEN];
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

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> str;
    len = str.length();

    GetSuffix(str);
    for(int i=0; i<len; i++) cout << SA[i] << "\n";
    return 0;
}