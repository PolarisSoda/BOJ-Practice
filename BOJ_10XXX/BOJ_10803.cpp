#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 0x7FFFFF;
int DP[10001][101];

int Dynamic(int N,int M) {
    if(N < M) swap(N,M);
    if(DP[N][M] != -1) return DP[N][M];
    if(N%M == 0) return DP[N][M] = N/M;

    int ret = INF;
    if(N > M*2) return DP[N][M] = Dynamic(N-M,M)+1;
    for(int i=1; i<=N/2; i++)
        ret = min(ret,Dynamic(i,M)+Dynamic(N-i,M));
    for(int i=1; i<=M/2; i++)
        ret = min(ret,Dynamic(N,i)+Dynamic(N,M-i));
    return DP[N][M] = ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N,M;
    cin >> N >> M;

    if(N < M) swap(N,M);
    memset(DP,-1,sizeof(DP));
    cout << Dynamic(N,M);
    exit(0);
}