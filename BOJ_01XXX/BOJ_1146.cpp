#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int DIV = 1000000;
ll DP[101][101][2];

ll Dynamic(int l,int r,int d) {
    if(DP[l][r][d] != -1) return DP[l][r][d];

    ll ret = 0;
    if(d == 0) for(int i=0; i<r; i++) ret = (ret + Dynamic(l+i,r-1-i,1)) % DIV;
    else for(int i=0; i<l; i++) ret = (ret + Dynamic(l-1-i,r+i,0)) % DIV;
    
    return DP[l][r][d] = ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    
    if(N == 1) cout << 1, exit(0);

    memset(DP,-1,sizeof(DP));
    DP[1][0][0] = 0, DP[1][0][1] = 1, DP[0][1][0] = 1, DP[0][1][1] = 0;

    ll ret = 0;
    for(int i=1; i<=N; i++) ret = (ret + Dynamic(i-1,N-i,0) + Dynamic(i-1,N-i,1)) % DIV;
    cout << ret;
    exit(0);
}