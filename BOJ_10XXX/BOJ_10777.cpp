#include <bits/stdc++.h>

using namespace std;

vector<int> HA,HB;
int N,M;
int DP[3002][101][101][2]; 

int Dynamic(int i,int j,int k,int w) {
    if(i >= N+1 && j >= k) return 0;
    if(DP[i][j][k][w] != -1) return DP[i][j][k][w];

    int ret = 0;
    if(w == 0) {
        if(i <= N) ret = max(ret,Dynamic(i+1,j,k,1)+HA[i]);
        if(j < k) ret = max(ret,Dynamic(i,j,k-1,1)+HB[k]);
    }
    if(i <= N) ret = max(ret,Dynamic(i+1,j,k,0));
    if(j < k) ret = max(ret,Dynamic(i,j+1,k,0));

    return DP[i][j][k][w] = ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N;
    HA.resize(N+1);
    for(int i=1; i<=N; i++) cin >> HA[i];
    cin >> M;
    HB.resize(M+1);
    for(int i=1; i<=M; i++) cin >> HB[i];
    sort(HB.begin(),HB.end());

    memset(DP,-1,sizeof(DP));
    cout << Dynamic(1,0,M,0);
    exit(0);
}