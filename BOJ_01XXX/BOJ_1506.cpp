#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 101;
bool visited[LEN];
vector<int> edge[2][LEN];
int arr[LEN];
stack<int> order;
vector<vector<int>> SCC;

void DFS(int now) {
    visited[now] = true;
    for(int next : edge[0][now]) if(!visited[next]) DFS(next);
    order.push(now);
}
void DFS_R(int now) {
    visited[now] = true;
    SCC.back().push_back(now);
    for(int next : edge[1][now]) if(!visited[next]) DFS_R(next);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            char C;
            cin >> C;
            if(C == '1') edge[0][i].push_back(j), edge[1][j].push_back(i);
        }
    }

    for(int i=1; i<=N; i++) if(!visited[i]) DFS(i);

    memset(visited,false,sizeof(visited));
    while(!order.empty()) {
        int now = order.top();
        order.pop();
        if(!visited[now]) {
            SCC.push_back(vector<int>());
            DFS_R(now);
        }
    }

    int ans = 0;
    for(auto vec : SCC) {
        int local_v = 1000001;
        for(int num : vec) local_v = min(local_v,arr[num]);
        ans += local_v;
    }
    cout << ans;
    exit(0);
}
    
