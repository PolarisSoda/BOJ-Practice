#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 100001;

vector<int> edge[LEN];
bool visited[LEN];

void DFS(int num) {
    int len = edge[num].size();
    for(int i=0; i<len; i++) {
        int next = edge[num][i];
        if(visited[next] == false) {
            visited[next] = true;
            DFS(next);
        }
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,K;
    cin >> N >> M >> K;

    int left,right,u,v;
    for(int i=1; i<=M; i++) {
        cin >> u >> v;
        if(i == K) {
            left = u;
            right = v;
        } else {
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
    }

    int lcnt = 0;
    visited[left] = true;
    DFS(left);
    for(int i=1; i<=N; i++) if(visited[i] == true) lcnt++;
    cout << (ll)lcnt * (ll)(N-lcnt);
}