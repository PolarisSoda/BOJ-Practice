#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 200002;
int arr[LEN][4];
ll DP[2][12][1<<4];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=1; i<=N; i++) for(int j=0; j<4; j++) cin >> arr[i][j];

    memset(DP,-1,sizeof(DP));
    DP[0][0][0] = 0;
    
    for(int i=0; i<=N; i++) {
        int now = i%2;
        for(int j=0; j<=11; j++) {
            for(int k=0; k<16; k++) {
                if(DP[now][j][k] == -1) continue;
                DP[now^1][j][k] = max(DP[now^1][j][k],DP[now][j][k]);

                if(j == 11) continue;
                for(int t=0; t<4; t++) {
                    int new_code = (k|(1<<t));
                    if(t == 3 && new_code == k) continue;
                    DP[now^1][j+1][new_code] = max(DP[now^1][j+1][new_code],DP[now][j][k]+arr[i+1][t]);
                }
                DP[now][j][k] = -1;
            }
        }
    }
    cout << DP[N%2][11][15];
    exit(0);
}