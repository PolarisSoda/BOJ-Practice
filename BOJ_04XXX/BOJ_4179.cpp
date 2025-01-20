#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

constexpr int INF = 0x7FFFFFF;
constexpr int LEN = 1001;
char arr[LEN][LEN];
int fcnt[LEN][LEN];
bool visited[LEN][LEN];
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
int R,C;
vector<pii> fire;

bool Approx(int r,int c) {
    if(r>=0 && r<R && c>=0 && c<C) return true;
    return false;
}

void F_BFS() {
    queue<pii> task;
    for(auto tt : fire) task.push(tt);

    while(!task.empty()) {
        int nr = task.front().first;
        int nc = task.front().second;
        task.pop();

        for(int i=0; i<4; i++) {
            int tr = nr + dr[i], tc = nc + dc[i];
            if(Approx(tr,tc) && arr[tr][tc] != '#' && fcnt[tr][tc] > fcnt[nr][nc] + 1) {
                task.push({tr,tc});
                fcnt[tr][tc] = fcnt[nr][nc]+1;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> R >> C;

    pii J;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> arr[i][j];
            fcnt[i][j] = INF;
            if(arr[i][j] == 'F') fire.push_back({i,j}), fcnt[i][j] = 0;
            else if(arr[i][j] == 'J') J = {i,j};
        }
    }
    
    F_BFS();

    queue<pair<pii,int>> task;
    task.push({J,0});

    int ans = -1;
    while(!task.empty()) {
        int r = task.front().first.first;
        int c = task.front().first.second;
        int cnt = task.front().second;
        task.pop();

        if(r == 0 || r == R-1 || c == 0 || c == C-1) {ans = cnt + 1; break;}

        for(int i=0; i<4; i++) {
            int tr = r + dr[i];
            int tc = c + dc[i];

            if(Approx(tr,tc) && !visited[tr][tc] && arr[tr][tc] != '#' && fcnt[tr][tc] > cnt+1) {
                visited[tr][tc] = true;
                task.push({{tr,tc},cnt+1});
            }
        }
    }

    if(ans == -1) cout << "IMPOSSIBLE";
    else cout << ans;
    exit(0);
}