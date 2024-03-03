#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 501;
constexpr int INF = 0x7FFFFFFF;
vector<int> edge[LEN]; //간선
int C[LEN][LEN],F[LEN][LEN]; //전체 용량, 흐르는 유량
int level[LEN],work[LEN]; //레벨, 이미 탐색한 간선 알려줌.
int N,M,S,T; //정점개수, 간선개수, 시작점, 끝점.

//라벨링.
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
//Dinic. Ref : BOJ_14286.cpp

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        //간선을 정의하는 곳.
        //만약 start와 sink를 따로두고 싶다면 MAX + 이런식으로 새 정점으로 빼는 것을 추천.
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