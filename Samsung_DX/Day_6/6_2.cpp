#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
struct info {
    int now;
    ll wt,total;
};
struct compare {
    bool operator()(info a,info b) {
        if(a.total == b.total) return a.wt > b.wt;
        return a.total > b.total;
    }
};

constexpr int LEN = 200001;
constexpr ll INF = 0x7FFFFFFFF;
vector<pll> edge[LEN];

ll solve() {
    int N,M;
    scanf("%d %d",&N,&M);

    for(int i=0; i<LEN; i++) edge[i].clear();
    for(int i=0; i<M; i++) {
        int S,E,X;
        scanf("%d %d %d",&S,&E,&X);
        edge[S].push_back({E,X});
        edge[E].push_back({S,X});
    }

    vector<ll> dist(LEN,INF);
    priority_queue<info,vector<info>,compare> pq;
    pq.push({1,0,0});

    ll sum = 0;
    while(!pq.empty()) {
        int now = pq.top().now;
        ll wt = pq.top().wt;
        ll total = pq.top().total;
        pq.pop();
        
        if(dist[now] <= total) continue;
        dist[now] = total;
        sum += wt;
        int sz = edge[now].size();
        for(int i=0; i<sz; i++) {
            int next = edge[now][i].first;
            ll w = edge[now][i].second;
            if(dist[next] >= total+w) {
                pq.push({next,w,total+w});
            }
        }
    }
    return sum;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int i=1; i<=T; i++) printf("#%d %lld\n",i,solve());
}