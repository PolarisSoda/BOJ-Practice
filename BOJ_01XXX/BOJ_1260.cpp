#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 1001;
bool visited[LEN];
vector<int> edge[LEN];
vector<int> R_DFS,R_BFS;

void DFS(int now) {
    visited[now] = true;
    R_DFS.push_back(now);
    for(int next : edge[now]) {
        if(visited[next] == false) DFS(next);
    }
}

void BFS(int start) {
    queue<int> task;
    task.push(start);

    while(!task.empty()) {
        int now = task.front();
        task.pop();

        if(visited[now] == true) continue;
        R_BFS.push_back(now);
        visited[now] = true;

        for(int next : edge[now]) {
            if(visited[next] == false) task.push(next);
        }
    }
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,V;
    cin >> N >> M >> V;

    for(int i=0; i<M; i++) {
        int A,B;
        cin >> A >> B;
        edge[A].push_back(B);
        edge[B].push_back(A);
    }
    for(int i=1; i<=LEN; i++) sort(edge[i].begin(),edge[i].end());

    DFS(V);
    memset(visited,false,sizeof(visited));
    BFS(V);

    for(int num : R_DFS) cout << num << " ";
    cout << "\n";
    for(int num : R_BFS) cout << num << " ";
    exit(0);
}