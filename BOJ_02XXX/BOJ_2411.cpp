#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 110;
int arr[LEN][LEN];
int DP[LEN][LEN][1001];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,A,B;
    cin >> N >> M >> A >> B;
    //M 가로 N 세로
    for(int i=0; i<A; i++) {
        int X,Y;
        cin >> X >> Y;
        arr[X][Y] = 1;
    }
    for(int i=0; i<B; i++) {
        int X,Y;
        cin >> X >> Y;
        arr[X][Y] = 2;
    }
    DP[1][1][0] = 1;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            for(int k=0; k<=A; k++) {
                if(DP[i][j][k] == 0) continue;
                if(arr[i][j+1] != 2) {
                    if(arr[i][j+1] == 1) DP[i][j+1][k+1] += DP[i][j][k];
                    else DP[i][j+1][k] += DP[i][j][k];
                }
                if(arr[i+1][j] != 2) {
                    if(arr[i+1][j] == 1) DP[i+1][j][k+1] += DP[i][j][k];
                    else DP[i+1][j][k] += DP[i][j][k];
                }
            }
        }
    }
    cout << DP[N][M][A];
}