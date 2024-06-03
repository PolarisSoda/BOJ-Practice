#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll walk[101][2];
ll bike[101][2];
ll DP[101][100001];
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K;
    cin >> N >> K;
    for(int i=1; i<=N; i++) {
        cin >> walk[i][0] >> walk[i][1];
        cin >> bike[i][0] >> bike[i][1];
    }

    memset(DP,-1,sizeof(DP));
    DP[1][walk[1][0]] = walk[1][1], DP[1][bike[1][0]] = max(DP[1][bike[1][0]],bike[1][1]);
    for(int i=1; i<N; i++) {
        for(int j=1; j<=K; j++) {
            if(DP[i][j] == -1) continue;
            ll NW = j+walk[i+1][0], NB = j+bike[i+1][0];
            if(NW <= K) DP[i+1][NW] = max(DP[i+1][NW],DP[i][j] + walk[i+1][1]);
            if(NB <= K) DP[i+1][NB] = max(DP[i+1][NB],DP[i][j] + bike[i+1][1]);
        }
    }

    ll ans = 0;
    for(int i=0; i<=K; i++) ans = max(ans,DP[N][i]);
    cout << ans;
    exit(0);
}