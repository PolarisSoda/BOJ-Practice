#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 501;
int PFX[LEN], DP[LEN][LEN];

int Dynamic(int X,int Y) {
    if(DP[X][Y] != -1) return DP[X][Y];
    if(X == Y) return 0;

    int ret = 0x7FFFFFF;
    for(int i=X; i<Y; i++) {
        int left = Dynamic(X,i);
        int right = Dynamic(i+1,Y);
        ret = min(ret,left+right-PFX[X-1]+PFX[Y]);
    }
    return DP[X][Y] = ret;
}

int solve() {
    int K;
    cin >> K;
    for(int i=1; i<=K; i++) cin >> PFX[i], PFX[i] += PFX[i-1];
    memset(DP,-1,sizeof(DP));
    return Dynamic(1,K);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    
    while(T--) cout << solve() << "\n";
}