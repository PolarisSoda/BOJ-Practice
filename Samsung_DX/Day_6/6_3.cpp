#include <bits/stdc++.h>
#define INF 0x7FFFFFFF

using namespace std;

typedef pair<int,int> pii;

constexpr int LEN = 50001;
vector<pii> edge[LEN],redge[LEN];

int solve() {
    int N,M,X;
    cin >> N >> M >> X;
    
    for(int i=0; i<LEN; i++) {
        edge[i] = vector<pii>();
        redge[i] = vector<pii>();
    }
    
    for(int i=0; i<M; i++) {
        int s,e,w;
        cin >> s >> e >> w;
        edge[s].push_back({e,w});
        redge[e].push_back({s,w});
    }
    
    vector<int> dist(N+1,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    dist[X] = 0;
    pq.push({0,X});
    
    while(!pq.empty()) {
        int start = pq.top().second;
        int checker = pq.top().first;
        pq.pop();
        
        if(checker > dist[start]) {
            continue;
        }
        
        for(int i=0; i<edge[start].size(); i++) {
            int next = edge[start][i].first;
            int weight = edge[start][i].second;
            
            if(dist[next] > dist[start] + weight) {
                dist[next] = dist[start] + weight;
                pq.push({dist[next],next});
            }
        }
    }
    
    vector<int> rdist(N+1,INF);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> rpq;
    
    rdist[X] = 0;
    rpq.push({0,X});
    
    while(!rpq.empty()) {
        int start = rpq.top().second;
        int checker = rpq.top().first;
        rpq.pop();
        
        if(checker > rdist[start]) {
            continue;
        }
        
        for(int i=0; i<redge[start].size(); i++) {
            int next = redge[start][i].first;
            int weight = redge[start][i].second;
            
            if(rdist[next] > rdist[start] + weight) {
                rdist[next] = rdist[start] + weight;
                rpq.push({rdist[next],next});
            }
        }
    }
    int ans = -1;
    for(int i=1; i<=N; i++) {
        if(dist[i]+rdist[i] > ans) {
            ans = dist[i] + rdist[i];
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " " << solve() << "\n";
}