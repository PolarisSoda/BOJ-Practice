#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 51;

int arr[LEN],bass[LEN],SA[LEN],G[LEN],temp[LEN];
int len,t = 1;

bool comp(int x,int y) {
    if(G[x] == G[y]) return G[x+t] < G[y+t];
    return G[x] < G[y];
}
void GetSuffix() {
    for(int i=0; i<len; i++) {
        SA[i] = i;
        G[i] = arr[i];
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

    int N;
    cin >> N;

    len = N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> bass[i];
        arr[bass[i]] = i;
    }
    int ans = N;
    int cnt = 0;
    for(int i=1; i<N; i++) {
        arr[bass[i]] = arr[bass[i-1]];
        t = 1;
        GetSuffix();
        bool same = true;
        for(int i=0; i<N; i++) {
            if(SA[i] != bass[i]) same = false;
        }
        if(same == true) ans = min(ans,N-(++cnt));
        else arr[bass[i]] = i;
    }
    cout << ans;
    return 0;
}