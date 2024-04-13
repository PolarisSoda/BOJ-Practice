#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
struct compare {
    bool operator() (pii a,pii b) {
        return a.second > b.second;
    }
};

constexpr int INF = 0x7FFFFFFD;
constexpr int LEN = 50001;
vector<pii> edge[LEN];
int dist[LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;
    for(int i=0; i<=N; i++) dist[i] = INF;
    for(int i=0; i<M; i++) {
        int S,E,X;
        cin >> S >> E >> X;
        edge[S].push_back({E,X});
        edge[E].push_back({S,X});
    }

    priority_queue<pii,vector<pii>,compare> pq;
    pq.push({1,0});
    while(!pq.empty()) {
        int now = pq.top().first;
        int total = pq.top().second;
        pq.pop();

        if(dist[now] < total) continue;

        int sz = edge[now].size();
        for(int i=0; i<sz; i++) {
            int next = edge[now][i].first;
            int w = edge[now][i].second;
            if(dist[next] > total+w)
                pq.push({next,dist[next] = total+w});
        }
    }
    cout << dist[N];
    exit(0);
}