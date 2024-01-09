#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 300001;
bool visited[LEN];
vector<int> edge[LEN];
ll N,ans;

ll DFS(int now) {
    visited[now] = true;
    ll ret = 1;
    for(int next : edge[now]) {
        if(visited[next] == false) {
            ll temp = DFS(next);
            ret += temp;
            ans += temp*(N-temp);
            ans += temp*(temp-1)/2;
        }
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N-1; i++) {
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    DFS(1);
    cout << ans;
    exit(0);
}