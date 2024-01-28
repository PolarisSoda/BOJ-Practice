#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
struct compare {
    bool operator()(pll a,pll b) {
        return a.second > b.second;
    }
};

constexpr int LEN = 1001;
vector<pll> edge[LEN];
priority_queue<ll> dist[LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,K;
    cin >> N >> M >> K;
    for(int i=0; i<M; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
    }

    priority_queue<pll,vector<pll>,compare> pq;
    pq.push({1,0});
    dist[1].push(0);
    while(!pq.empty()) {
        int now = pq.top().first;
        ll total = pq.top().second;
        pq.pop();

        if(!dist[now].empty() && total > dist[now].top()) continue;

        for(auto temp : edge[now]) {
            int next = temp.first;
            ll w = temp.second;

            if(dist[next].size() < K) {
                dist[next].push(total+w);
                pq.push({next,total+w});
            } else if(dist[next].top() > total+w) {
                dist[next].pop();
                dist[next].push(total+w);
                pq.push({next,total+w});
            }
        }
    }
    for(int i=1; i<=N; i++) {
        if(dist[i].size() < K) cout << -1 << "\n";
        else cout << dist[i].top() << "\n";
    }
    exit(0);
}