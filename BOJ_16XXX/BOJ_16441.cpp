#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

constexpr int LEN = 101;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int N,M;
char arr[LEN][LEN];
bool visited[LEN][LEN];
queue<pii> task;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'W') task.push({i,j});
        }
    }

    while(!task.empty()) {
        int r = task.front().first;
        int c = task.front().second;
        task.pop();

        visited[r][c] = true;

        for(int i=0; i<4; i++) {
            int nr = r + dy[i], nc = c + dx[i];
            if(arr[nr][nc] == '#' || visited[nr][nc]) continue;
            if(arr[nr][nc] == '+') {
                int tr = nr, tc = nc;
                while(true) {
                    int ttr = tr + dy[i], ttc = tc + dx[i];
                    if(arr[tr][tc] != '+' || arr[ttr][ttc] == '#') break;
                    tr = ttr, tc = ttc;
                }
                if(!visited[tr][tc]) task.push({tr,tc});
            } else task.push({nr,nc});
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(arr[i][j] == '.' && !visited[i][j]) cout << 'P';
            else cout << arr[i][j];
        }
        cout << "\n";
    }
    exit(0);
}