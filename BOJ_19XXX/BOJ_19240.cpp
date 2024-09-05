#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 300001;
vector<int> edge[LEN];
bool visited[LEN],color[LEN];

void DFS(int now,int flag) {
    visited[now] = true;
    color[now] = flag;
    for(int next : edge[now]) {
        if(visited[next]) continue;
        DFS(next,flag^1);
    }
}

void solve() {
    int N,M;
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int X,Y;
        cin >> X >> Y;
        edge[X].push_back(Y);
        edge[Y].push_back(X);
    }

    for(int i=1; i<=N; i++) {
        if(visited[i]) continue;
        DFS(i,0);
    }
    for(int i=1; i<=N; i++) for(int next : edge[i]) if(color[i] == color[next]) goto FAIL;

    cout << "YES\n";
    goto INIT;

    FAIL:
    cout << "NO\n";

    INIT:
    for(int i=1; i<=N; i++) edge[i].clear();
    memset(visited,false,sizeof(visited));
    memset(color,false,sizeof(color));
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) solve();
    exit(0);
}