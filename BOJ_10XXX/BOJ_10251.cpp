#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 103;
constexpr int INF = 2139062143;
int road[LEN][LEN][2]; //Down is 0, Right is 1
int DP[LEN][LEN][LEN<<1][2]; //Down is 0, Right is 1

int solve() {
    int M,N,L,G;
    cin >> M >> N >> L >> G;
    //M 세로 N 가로

    memset(road,0,sizeof(road));
    memset(DP,127,sizeof(DP));

    for(int i=1; i<=M; i++) for(int j=1; j<=N-1; j++) cin >> road[j][i][1];
    for(int i=1; i<=M-1; i++) for(int j=1; j<=N; j++) cin >> road[j][i][0];

    DP[1][1][0][0] = 0;
    DP[1][1][0][1] = 0;
    for(int i=1; i<=M; i++) {
        for(int j=1; j<=N; j++) {
            for(int k=0; k<=max(M,N); k++) {
                DP[j+1][i][k][1] = min(DP[j+1][i][k][1],DP[j][i][k][1] + road[j][i][1]);
                DP[j+1][i][k+1][1] = min(DP[j+1][i][k+1][1],DP[j][i][k][0] + road[j][i][1]);
                DP[j][i+1][k][0] = min(DP[j][i+1][k][0],DP[j][i][k][0] + road[j][i][0]);
                DP[j][i+1][k+1][0] = min(DP[j][i+1][k+1][0],DP[j][i][k][1] + road[j][i][0]);
            }
        }
    }
    
    for(int i=0; i<=max(M,N); i++) {
        if(DP[N][M][i][0] <= G) return i + L*(M-1+N-1);
        if(DP[N][M][i][1] <= G) return i + L*(M-1+N-1);
    }
    return -1;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) cout << solve() << "\n";
    exit(0);
}