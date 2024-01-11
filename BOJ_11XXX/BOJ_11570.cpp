#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll INF = 0x7FFFFFFF;
constexpr int LEN = 2001;
ll music[LEN];
ll DP[LEN][LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> music[i];
    for(int i=0; i<=N; i++) for(int j=0; j<=N; j++) DP[j][i] = INF;
    DP[1][0] = 0;
    DP[0][1] = 0;
    for(int i=1; i<N; i++) {
        for(int j=0; j<=i-1; j++) {
            int next = max(i,j) + 1;
            //DP[i][j] -> DP[next][j], DP[i][next]
            DP[next][j] = min(DP[next][j],DP[i][j]+(i == 0 ? 0 : abs(music[i]-music[next])));
            DP[i][next] = min(DP[i][next],DP[i][j]+(j == 0 ? 0 : abs(music[j]-music[next])));
            //DP[j][i] -> DP[next][i], DP[j][next]
            DP[next][i] = min(DP[next][i],DP[j][i]+(j == 0 ? 0 : abs(music[j]-music[next])));
            DP[j][next] = min(DP[j][next],DP[j][i]+(i == 0 ? 0 : abs(music[i]-music[next])));
        }
    }
    ll ans = INF;
    for(int i=0; i<N; i++) ans = min({ans,DP[i][N],DP[N][i]});
    cout << ans;
    exit(0);
}