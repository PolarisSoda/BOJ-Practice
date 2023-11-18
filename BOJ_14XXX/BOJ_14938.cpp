#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 10000000;
int item[101];
int dist[101][101];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,R;
    cin >> N >> M >> R;
    for(int i=1; i<=N; i++) cin >> item[i];

    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) if(i != j) dist[j][i] = INF;

    for(int i=0; i<R; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[b][a],c);
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            for(int k=1; k<=N; k++) {
                dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=N; i++) {
        int temp = 0;
        for(int j=1; j<=N; j++) if(dist[i][j] <= M) temp += item[j];
        ans = max(temp,ans);
    }
    cout << ans;
}
