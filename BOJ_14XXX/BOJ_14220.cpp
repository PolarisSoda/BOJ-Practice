#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 501;
constexpr ll INF = LONG_LONG_MAX;
ll DP[LEN][LEN];
int edge[LEN][LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) cin >> edge[i][j], DP[i][j] = INF;
    
    for(int i=1; i<=N; i++) DP[i][0] = 0;
    for(int i=1; i<=N-1; i++) {
        for(int j=1; j<=N; j++) {
            if(DP[i-1][j] == INF) continue;
            for(int k=1; k<=N; k++) if(edge[j][k] != 0) DP[i][k] = min(DP[i][k],DP[i-1][j] + edge[j][k]);
        }
    }

    ll ans = INF;
    for(int i=1; i<=N; i++) ans = min(ans,DP[N-1][i]);
    if(ans == INF) cout << -1;
    else cout << ans;

    exit(0);
}