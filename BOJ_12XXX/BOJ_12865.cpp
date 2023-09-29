#include <bits/stdc++.h>

using namespace std;

int DP[101][100001];

int main() {
    int N,K;
    cin >> N >> K;

    int W,P;
    for(int i=1; i<=N; i++) {
        cin >> W >> P;
        for(int j=1; j<=K; j++) {
            if(W > j) DP[i][j] = DP[i-1][j];
            else DP[i][j] = max(DP[i-1][j-W]+P,DP[i-1][j]);
        }
    }
    cout << DP[N][K];
    return 0;
}