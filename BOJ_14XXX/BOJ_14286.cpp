#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 501;
constexpr int INF = 0x7FFFFFFF;
vector<int> edge[LEN];
int C[LEN][LEN],F[LEN][LEN];
int level[LEN],work[LEN];
int N,M,S,T;

bool Label() {
    memset(level,-1,sizeof(level));
    queue<int> task;
    task.push(S);
    level[S] = 0;
    while(!task.empty()) {
        int now = task.front();
        task.pop();
        for(int next : edge[now]) {
            if(level[next] == -1 && C[now][next]-F[now][next] > 0) {
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
        if(level[next] == level[now]+1 && C[now][next]-F[now][next] > 0) {
            int amount = DFS(next,min(flow,C[now][next]-F[now][next]));
            if(amount > 0) {
                F[now][next] += amount;
                F[next][now] -= amount;
                return amount;
            }
        }
    }
    return 0;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back(b);
        edge[b].push_back(a);
        C[a][b] += c;
        C[b][a] += c;
    }
    cin >> S >> T;

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