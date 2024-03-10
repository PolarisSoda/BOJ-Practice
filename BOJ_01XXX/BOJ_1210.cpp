#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 401;
constexpr int INF = 0x7FFFFFFF;
vector<int> edge[LEN];
int C[LEN][LEN],F[LEN][LEN];
int level[LEN],work[LEN];
int N,M,S,T;

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

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> S >> T;
    T += N;

    for(int i=1; i<=N; i++) {
        int A;
        cin >> A;
        edge[i].push_back(i+N);
        edge[i+N].push_back(i);
        C[i][i+N] = A; 
    }

    for(int i=0; i<M; i++) {
        int A,B;
        cin >> A >> B;
        edge[A+N].push_back(B);
        edge[B].push_back(A+N);
        C[A+N][B] = INF;
        
        edge[B+N].push_back(A);
        edge[A].push_back(B+N);
        C[B+N][A] = INF;
    }

    int ans = 0;
    while(Label()) {
        memset(work,0,sizeof(work));
        int flow = DFS(S,INF);
        while(flow != 0) {
            ans += flow;
            flow = DFS(S,INF);
        }
    }
    Label();
    for(int i=1; i<=N; i++) if(level[i] != -1 && level[i+N] == -1) cout << i << " ";
    exit(0);
}