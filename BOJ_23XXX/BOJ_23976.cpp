#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int DIV = 1000000007;

ll DP[2501][2501][2];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K;
    string str;
    cin >> N >> K >> str;
    
    DP[1][1][str[0] == '0' ? 0 : 1] = 1;
    for(int i=1; i<N; i++) {
        int now = (str[i] == '0' ? 0 : 1);
        for(int j=0; j<=K; j++) {
            if(DP[i][j][0]) {
                if(j+1 <= K) {
                    DP[i+1][j+1][now] += DP[i][j][0];
                    DP[i+1][j+1][now] %= DIV;
                }
            }
            if(DP[i][j][1]) {
                DP[i+1][j][1] += DP[i][j][1];
                DP[i+1][j][1] %= DIV;
                if(j+1 <= K) {
                    DP[i+1][j+1][now] += DP[i][j][1];
                    DP[i+1][j+1][now] %= DIV;
                }
            }
        }
    }
    cout << DP[N][K][0] + DP[N][K][1];
}