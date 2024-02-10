#include <bits/stdc++.h>
using namespace std;

constexpr int LEN = 100001;
constexpr int RCK = 0,SCR = 1,PAP = 2;
int RSP[LEN];
int DP[LEN][21][3]; //i번까지 진행했고 j번 바꿨으며 현재 i(R,S,P)

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(DP,-1,sizeof(DP));

    int N,K;
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        char C;
        cin >> C;
        if(C == 'P') RSP[i] = PAP;
        else if(C == 'S') RSP[i] = SCR;
        else RSP[i] = RCK;
    }

    DP[0][0][0] = RSP[0] == SCR ? 1 : 0;
    DP[0][0][1] = RSP[0] == PAP ? 1 : 0;
    DP[0][0][2] = RSP[0] == RCK ? 1 : 0;
    for(int i=0; i<N-1; i++) {
        for(int j=0; j<=K; j++) {
            for(int k=0; k<3; k++) {
                if(DP[i][j][k] == -1) continue;
                if(k == RCK) {
                    DP[i+1][j][RCK] = max(DP[i+1][j][RCK],RSP[i+1] == SCR ? DP[i][j][k]+1 : DP[i][j][k]);
                    if(j != K) {
                        DP[i+1][j+1][SCR] = max(DP[i+1][j+1][SCR],RSP[i+1] == PAP ? DP[i][j][k]+1 : DP[i][j][k]);
                        DP[i+1][j+1][PAP] = max(DP[i+1][j+1][PAP],RSP[i+1] == RCK ? DP[i][j][k]+1 : DP[i][j][k]);
                    }
                    
                } else if(k == SCR) {
                    DP[i+1][j][SCR] = max(DP[i+1][j][SCR],RSP[i+1] == PAP ? DP[i][j][k]+1 : DP[i][j][k]);
                    if(j != K) {
                        DP[i+1][j+1][RCK] = max(DP[i+1][j+1][RCK],RSP[i+1] == SCR ? DP[i][j][k]+1 : DP[i][j][k]);
                        DP[i+1][j+1][PAP] = max(DP[i+1][j+1][PAP],RSP[i+1] == RCK ? DP[i][j][k]+1 : DP[i][j][k]);
                    }
                } else {
                    DP[i+1][j][PAP] = max(DP[i+1][j][PAP],RSP[i+1] == RCK ? DP[i][j][k]+1 : DP[i][j][k]);
                    if(j != K) {
                        DP[i+1][j+1][RCK] = max(DP[i+1][j+1][RCK],RSP[i+1] == SCR ? DP[i][j][k]+1 : DP[i][j][k]);
                        DP[i+1][j+1][SCR] = max(DP[i+1][j+1][SCR],RSP[i+1] == PAP ? DP[i][j][k]+1 : DP[i][j][k]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=K; i++) for(int j=0; j<3; j++) ans = max(ans,DP[N-1][i][j]);
    cout << ans;
}