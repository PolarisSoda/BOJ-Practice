#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 10001;
vector<int> edge[LEN];
int v_idx[LEN],idx,root;
set<int> ans;

int DFS(int now) {
    v_idx[now] = ++idx;

    int minv = idx;
    int child = 0;
    for(int next : edge[now]) {
        if(v_idx[next] == 0) {
            child++;
            int temp = DFS(next);
            if(now != root && temp >= v_idx[now]) ans.insert(now);
            minv = min(minv,temp);
        } else {
            minv = min(minv,v_idx[next]);
        }
    }
    if(now == root && child >= 2) ans.insert(now);
    return minv;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int V,E;
    cin >> V >> E;
    for(int i=0; i<E; i++) {
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for(int i=1; i<=V; i++) if(v_idx[i] == 0) DFS(root = i);
    cout << ans.size() << "\n";
    for(auto val : ans) cout << val << " ";
    exit(0);
}