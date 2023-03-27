#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int N,M,ccnt,pcnt;
char parking[51][51];
pii car[101];
pii park[101];
int dist[101][101];
bool visited[101];
int indicator[101];
vector<int> edge[101];

bool Approx(int x,int y) {
    if(x>=1 && x<=M && y>=1 && y<=N)
        return true;
    return false;
}
void BFS(int num);
bool DFS(int num,int bias);

bool check(int num) {
    memset(indicator,0,sizeof(indicator));
    int ans = 0;
    for(int i=1; i<=ccnt; i++) {
        memset(visited,false,sizeof(visited));
        if(DFS(i,num))
            ans++;
    }
    if(ans == ccnt)
        return true;
    return false;
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> parking[j][i];
            if(parking[j][i] == 'C') {
                ccnt++;
                car[ccnt] = {j,i};
            } else if(parking[j][i] == 'P') {
                pcnt++;
                park[pcnt] = {j,i};
            }
        }
    }
    if(ccnt == 0) {
        cout << 0;
        return 0;
    }
    for(int i=1; i<=ccnt; i++)
        BFS(i);
    int left = -1;
    int right = 2501;
    int ans = 0;
    while(left+1<right) {
        int mid = (left+right)/2;
        if(check(mid)) {
            right = mid;
            ans = mid;
        } else {
            left = mid;
        }
    }
    if(ans == 0)
        cout << -1;
    else
        cout << ans;
    
}

bool DFS(int num,int bias) {
    for(int i=0; i<edge[num].size(); i++) {
        int next = edge[num][i];
        if(visited[next])
            continue;
        if(dist[num][next] > bias)
            continue;
        visited[next] = true;
        if(indicator[next] == 0 || DFS(indicator[next],bias)) {
            indicator[next] = num;
            return true;
        }
    }
    return false;
}

void BFS(int num) {
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    bool visit[51][51] = {};
    int arr[51][51] = {};
    
    queue<pii> task;
    task.push(car[num]);
    visit[car[num].first][car[num].second] = true;
    while(!task.empty()) {
        int nx = task.front().first;
        int ny = task.front().second;
        task.pop();
        for(int i=0; i<4; i++) {
            int ox = nx + dx[i];
            int oy = ny + dy[i];
            if(Approx(ox,oy) && parking[ox][oy] != 'X' && visit[ox][oy] == false) {
                visit[ox][oy] = true;
                arr[ox][oy] = arr[nx][ny] + 1;
                task.push({ox,oy});
            }
        }
    }
    for(int i=1; i<=pcnt; i++) {
        int x = park[i].first;
        int y = park[i].second;
        int bias = arr[x][y];
        if(bias) {
            dist[num][i] = bias;
            edge[num].push_back(i);
        }
    }
}
