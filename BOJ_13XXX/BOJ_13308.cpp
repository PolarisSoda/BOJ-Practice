#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

struct info {
    ll total;
    ll now;
    ll fuel;
};
struct compare {
    bool operator()(info a,info b) {
        return a.total > b.total;
    }
};

constexpr ll LEN = 2501;
constexpr ll INF = 0x7AAAAAAAAAA;

ll dist[LEN][LEN];
ll price[LEN];
vector<pii> edge[LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll N,M;
    cin >> N >> M;
    for(ll i=1; i<=N; i++) cin >> price[i];
    for(ll i=1; i<=M; i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    for(ll i=0; i<LEN; i++) for(ll j=0; j<LEN; j++) dist[j][i] = INF;
    priority_queue<info,vector<info>,compare> pq;
    pq.push({0,1,price[1]});

    while(!pq.empty()) {
        ll total = pq.top().total;
        ll now = pq.top().now;
        ll fuel = pq.top().fuel;
        pq.pop();

        if(total > dist[now][fuel]) continue;
        if(now == N) {
            cout << total;
            exit(0);
        }
        ll sz = edge[now].size();
        for(ll i=0; i<sz; i++) {
            ll next = edge[now][i].first;
            ll w = edge[now][i].second;
            if(dist[next][fuel] > total + w*fuel) {
                dist[next][fuel] = total + w*fuel;
                pq.push({total+w*fuel,next,min(fuel,price[next])});
            }
        }
    }
}