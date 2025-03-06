#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
struct info {
    int now,cnt,total;
};
struct compare {
    bool operator() (const info &a, const info &b) {
        return a.total > b.total;
    }
};

constexpr int LEN = 1001, INF = INT_MAX;
int dist[LEN][LEN],C[LEN];
vector<pii> edge[LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    for(int i=0; i<N; i++) cin >> C[i];
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) {
        int temp;
        cin >> temp;
        if(temp != 0) edge[i].push_back({j,temp});
    }

    for(int i=0; i<N; i++) for(int j=0; j<N; j++) dist[i][j] = INF;

    priority_queue<info,vector<info>,compare> pq;
    pq.push({0,0,0});

    while(!pq.empty()) {
        auto tt = pq.top();
        int now = tt.now, cnt = tt.cnt, total = tt.total;
        pq.pop();

        if(dist[cnt][now] <= total) continue;
        dist[cnt][now] = total;

        for(auto tt : edge[now]) {
            int next = tt.first, w = tt.second, bias = C[now] ^ C[next];
            if(dist[cnt+bias][next] > total + w) 
                pq.push({next,cnt+bias,dist[cnt+bias][next] = total + w});
        }

    }

    for(int i=0; i<N; i++)
        if(dist[i][M] != INF) cout << i << " " << dist[i][M], exit(0);
}