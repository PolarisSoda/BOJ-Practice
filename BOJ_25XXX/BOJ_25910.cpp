#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

constexpr int LEN = 100001;
vector<pii> edge[LEN];
int CTX[LEN],PFX[20];

void DFS(int now,int from,int code) {
    for(int i=0; i<20; i++) PFX[i] += (code>>i)&1;
    for(auto &[next,w] : edge[now]) {
        if(next == from) continue;
        DFS(next,now,CTX[next] = code^w);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,X;
    cin >> N >> X;

    for(int i=1; i<N; i++) {
        int A,B,C;
        cin >> A >> B >> C;
        edge[A].push_back({B,C});
        edge[B].push_back({A,C});
    }
    DFS(1,0,CTX[1] = X);

    int ans = 0x7FFFFFF;
    for(int i=1; i<=N; i++) {
        int ret = 0;
        for(int j=0; j<20; j++) {
            if((X>>j&1) != (CTX[i]>>j&1)) ret += N - PFX[j];
            else ret += PFX[j];
        }
        ans = min(ans,ret); 
    }
    cout << ans;
    exit(0);
}