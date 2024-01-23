#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
struct info {
    int w,now;
    ll wt;
    ll total;
};

struct compare {
    bool operator()(info a,info b) {
        return a.total > b.total;
    }
};

constexpr int LEN = 200001;
constexpr ll INF = 0x7FFFFFFFF;
ll dist[LEN];
vector<pll> edge[LEN];
set<pll> check;

ll solve() {
    int N,M;
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        edge[i] = vector<pll>();
        dist[i] = INF;
    }
    for(int i=0; i<M; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    priority_queue<info,vector<info>,compare> pq;
    pq.push({1,1,0,0});
    ll sum = 0;

    while(!pq.empty()) {
        int where = pq.top().w;
        int now = pq.top().now;
        ll wt = pq.top().wt;
        ll total = pq.top().total;
        pq.pop();

        if(dist[now] <= total) continue;
        cout << wt << " ";
        dist[now] = total;
        int sz = edge[now].size();
        for(int i=0; i<sz; i++) {
            int next = edge[now][i].first;
            ll w = edge[now][i].second;
            if(dist[next] > total+w) {
                pq.push({now,next,w,total+w});
            }
        }
    }
    return sum;
}

int main() {
    //cin.tie(NULL);
    //ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " " << solve() << "\n";
    return 0;
}