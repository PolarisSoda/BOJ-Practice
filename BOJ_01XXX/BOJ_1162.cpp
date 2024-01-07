#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

struct info {
    ll total;
    int now;
    int used;
};
struct compare {
    bool operator() (info a,info b) {
        return a.total > b.total;
    }
};

constexpr int LEN = 10001;
constexpr ll INF = 0x7FFFFFFFFF;
vector<pll> edge[LEN];
ll dist[LEN][21];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,K;
    cin >> N >> M >> K;
    
    for(int i=0; i<LEN; i++) for(int j=0; j<21; j++) dist[i][j] = INF; 
    for(int i=0; i<M; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    priority_queue<info,vector<info>,compare> pq;
    pq.push({0,1,0});
    while(!pq.empty()) {
        ll total = pq.top().total;
        int now = pq.top().now;
        int used = pq.top().used;
        pq.pop();

        if(total > dist[now][used]) continue;

        int sz = edge[now].size();
        for(int i=0; i<sz; i++) {
            int next = edge[now][i].first;
            ll w = edge[now][i].second;

            if(dist[next][used] > total + w) {
                pq.push({total+w,next,used});
                dist[next][used] = total + w;
            }
            if(used < K && dist[next][used+1] > total) {
                pq.push({total,next,used+1});
                dist[next][used+1] = total;
            }
        }
    }
    ll ans = INF;
    for(int i=0; i<=K; i++) ans = min(ans,dist[N][i]);
    cout << ans;
    exit(0);
} 