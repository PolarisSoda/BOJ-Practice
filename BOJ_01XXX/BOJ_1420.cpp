
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

constexpr int LEN = 20002;
constexpr int INF = 0x7FFFFFF;

vector<int> edge[LEN]; //간선
char label[101][101];

map<pii,int> C,F;

int level[LEN],work[LEN]; //레벨, 이미 탐색한 간선 알려줌.
int N,M,S,T; //시작점, 끝점.

bool Approx(int x,int y) {
    if(x>=0 && x<M && y>=0 && y<N) return true;
    return false;
}
bool Label() {
    memset(level,-1,sizeof(level));
    queue<int> task;
    task.push(S);
    level[S] = 0;
    while(!task.empty()) {
        int now = task.front();
        task.pop();
        for(int next : edge[now]) {
            if(level[next] == -1 && C[{now,next}]-F[{now,next}] > 0) {
                level[next] = level[now]+1;
                task.push(next);
            }
        }
    }
    if(level[T] == -1) return false;
    return true;
}
int DFS(int now,int flow) {
    if(now == T) return flow; 

    int sz = edge[now].size();
    for(int &i=work[now]; i<sz; i++) {
        int next = edge[now][i];
        if(level[next] == level[now]+1 && C[{now,next}]-F[{now,next}] > 0) {
            int amount = DFS(next,min(flow,C[{now,next}]-F[{now,next}]));
            if(amount > 0) {
                F[{now,next}] += amount;
                F[{next,now}] -= amount;
                return amount;
            }
        }
    }
    return 0;
}

//하나의 정점이 부여받은 idx에 대해, idx는 in idx+1는 out
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    int idx = -2;
    int sx,sy,tx,ty;
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) {
        idx += 2;
        cin >> label[j][i];
        if(label[j][i] == '#') continue;
        if(label[j][i] == 'K') S = idx+1, sx = j, sy = i;
        else if(label[j][i] == 'H') T = idx, tx = j, ty = i;

        edge[idx].push_back(idx+1);
        edge[idx+1].push_back(idx);
        C[{idx,idx+1}] = 1;
        C[{idx+1,idx}] = 0;

        if(Approx(j-1,i) && label[j-1][i] != '#') {
            edge[idx+1].push_back(idx-2);
            edge[idx-2].push_back(idx+1);
            C[{idx+1,idx-2}] = INF;
            C[{idx-2,idx+1}] = 0;

            edge[idx-1].push_back(idx);
            edge[idx].push_back(idx-1);
            C[{idx-1,idx}] = INF;
            C[{idx,idx-1}] = 0;
        }
        if(Approx(j,i-1) && label[j][i-1] != '#') {
            edge[idx+1].push_back(idx-2*M);
            edge[idx-2*M].push_back(idx+1);
            C[{idx+1,idx-2*M}] = INF;
            C[{idx-2*M,idx+1}] = 0;

            edge[idx-2*M+1].push_back(idx);
            edge[idx].push_back(idx-2*M+1);
            C[{idx-2*M+1,idx}] = INF;
            C[{idx,idx-2*M+1}] = 0;
        }
    }
    if(abs(sx-tx)+abs(sy-ty) == 1) cout << -1, exit(0);

    int ans = 0;
    while(Label()) {
        memset(work,0,sizeof(work));
        int flow = DFS(S,INF);
        while(flow != 0) {
            ans += flow;
            flow = DFS(S,INF);
        }
    }
    cout << ans;
    exit(0);
}