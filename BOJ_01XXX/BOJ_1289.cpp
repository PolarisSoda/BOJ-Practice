#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

constexpr int DIV = 1000000007;
constexpr int LEN = 100001;
vector<pii> edge[LEN];
bool visited[LEN];
ll DP[LEN],ans;
//DP = 이 루트를 포함하는 모든 가중치의 합.

ll DFS(int now) {
    visited[now] = true;

    ll ret = 0;
    for(auto tt : edge[now]) {
        int next = tt.first, w = tt.second;
        if(visited[next]) continue;

        ll temp = ((DFS(next)*w)%DIV + w)%DIV;

        if(ret == 0) ans = (ans + temp)%DIV;
        else ans = (ans + (ret*temp)%DIV + temp)%DIV;
        
        ret = (ret + temp)%DIV;
    }
    return DP[now] = ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=0; i<N-1; i++) {
        int A,B,W;
        cin >> A >> B >> W;
        edge[A].push_back({B,W});
        edge[B].push_back({A,W});
    }
    DFS(1);
    cout << ans;
    exit(0);
}
