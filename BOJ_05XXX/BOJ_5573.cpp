#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 1005;
int cross[LEN][LEN];
int DP[LEN][LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int H,W,N;
    cin >> H >> W >> N;

    for(int i=1; i<=H; i++) for(int j=1; j<=W; j++) cin >> cross[j][i];

    DP[1][1] = N-1;
    for(int i=1; i<=H; i++) {
        for(int j=1; j<=W; j++) {
            if(cross[j][i] == 1) {
                DP[j+1][i] += (DP[j][i]+1)>>1;
                DP[j][i+1] += DP[j][i]>>1; 
            } else {
                DP[j+1][i] += DP[j][i]>>1;
                DP[j][i+1] += (DP[j][i]+1)>>1;
            }
        }
    }
    int x = 1;
    int y = 1;
    while(x != W+1 && y != H+1) {
        int direction = cross[x][y] ^ DP[x][y]&1;
        if(direction) x++;
        else y++;
    }
    cout << y << " " << x;
    exit(0);
}