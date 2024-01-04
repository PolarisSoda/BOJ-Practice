#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 1000001;
int dist[101][101];

int main() {
    int N,M;
    cin >> N >> M;

    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) if(i != j) dist[i][j] = INF;
    for(int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        dist[a][b] = 1;
    }
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) for(int k=1; k<=N; k++) dist[j][k] = min(dist[j][k],dist[j][i] + dist[i][k]);

    int cnt = N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(dist[i][j] == INF && dist[j][i] == INF) {
                cnt--;
                break;
            }
        }
    }
    cout << cnt;
    exit(0);
}