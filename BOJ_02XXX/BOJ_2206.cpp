#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 1001;
constexpr int INF = 0x7FFFFFF;
int dist[LEN][LEN][2], arr[LEN][LEN];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N,M;

bool Approx(int x,int y) {
    if(x>=0 && x<M && y>=0 && y<N) return true;
    return false;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            char c;
            cin >> c;
            arr[j][i] = c - '0';
            dist[j][i][0] = dist[j][i][1] = INF;
        }
    }

    queue<tuple<int,int,int,int>> task;
    task.push({0,0,0,1});
    while(!task.empty()) {
        int x,y,used,dis;
        tie(x,y,used,dis) = task.front();
        task.pop();

        if(dis >= dist[x][y][used]) continue;
        dist[x][y][used] = dis;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(Approx(nx,ny)) {
                if(used == 0 && arr[nx][ny] == 1) {
                    if(dist[nx][ny][1] > dis + 1) task.push({nx,ny,1,dis+1});
                } else if(arr[nx][ny] == 0) {
                    if(dist[nx][ny][used] > dis + 1) task.push({nx,ny,used,dis+1});
                }
            }
        }
    }
    int ret = min(dist[M-1][N-1][0],dist[M-1][N-1][1]);
    cout << (ret == INF ? -1 : ret);
    exit(0);
}