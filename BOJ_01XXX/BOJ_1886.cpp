#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int dist[13][13];
int j_idx[13][13],d_idx[13][13];
char arr[13][13];
int dcnt,jcnt;
int N,M;
vector<pii> edge[10001];
vector<int> indicator;
bool visited[10001];
vector<int> t_edge[10001];

bool Approx(int X,int Y) {
    if(X>=1 && X<=M && Y>=1 && Y<=N) return true;
    return false;
}

void BFS(int X,int Y) {
    memset(dist,5,sizeof(dist));
    dist[X][Y] = 0;
    int idx = j_idx[X][Y];
    queue<pii> task;
    task.push({X,Y});
    int cnt = 0;
    while(!task.empty()) {
        int nx = task.front().first;
        int ny = task.front().second;
        task.pop();

        if(arr[nx][ny] == 'D') {
            edge[idx].push_back({d_idx[nx][ny],dist[nx][ny]});
            cnt++;
            continue;
        }

        for(int i=0; i<4; i++) {
            int ox = nx + dx[i];
            int oy = ny + dy[i];
            if(Approx(ox,oy) && arr[ox][oy] != 'X') {
                if(dist[ox][oy] > dist[nx][ny]+1) {
                    dist[ox][oy] = dist[nx][ny]+1;
                    task.push({ox,oy});
                }
            }
        }
    }
    if(cnt == 0) cout << "impossible", exit(0);
}

bool DFS(int num) {
    for(int i=0; i<t_edge[num].size(); i++) {
        int next = t_edge[num][i];
        if(visited[next]) continue;
        visited[next] = true;
        if(indicator[next] == 0 || DFS(indicator[next])) {
            indicator[next] = num;
            return true;
        }
    }
    return false;
}

bool check(int num) {
    indicator = vector<int>(num*dcnt+1,0);
    for(int i=0; i<10001; i++) t_edge[i].clear();
    
    for(int i=1; i<=jcnt; i++) {
        for(auto tt : edge[i]) {
            int ent = tt.first;
            int w = tt.second;
            for(int j=0; j<=num-w; j++) {
                t_edge[i].push_back(ent+dcnt*j);
            }
        }
    }
    int cnt = 0;
    for(int i=1; i<=jcnt; i++) {
        memset(visited,false,sizeof(visited));
        if(DFS(i) == true) cnt++;
    }
    if(cnt == jcnt) return true;
    return false;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            char C;
            cin >> C;
            if(C == 'D') d_idx[j][i] = ++dcnt;
            else if(C == '.') j_idx[j][i] = ++jcnt;
            arr[j][i] = C;
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(j_idx[j][i] != 0) BFS(j,i);
        }
    }

    int left = 0, right = 150, ans = 0;
    while(left+1 < right) {
        int mid = (left+right)/2;
        if(check(mid))
            ans = right = mid;
        else left = mid;
    }
    cout << ans;
    exit(0);
}