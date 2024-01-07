#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

struct info {
    int total; //지금까지 총 거리
    int now; //현재 위치
    int cnt; //지금까지 거쳐간 길 개수.
};

struct compare {
    bool operator()(info a,info b) {
        return a.total > b.total;
    }
};
constexpr int LEN = 1001;
constexpr int INF = 0x7FFFFFF;
vector<pii> edge[LEN];
int dist[LEN][LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,K,S,D;
    cin >> N >> M >> K >> S >> D;

    for(int i=0; i<LEN; i++) for(int j=0; j<LEN; j++) dist[i][j] = INF;
    for(int i=0; i<M; i++) {
        int a,b,w;
        cin >> a >> b >> w;
        edge[a].push_back({b,w});
        edge[b].push_back({a,w});
    }

    priority_queue<info,vector<info>,compare> pq;
    pq.push({0,S,0});
    dist[S][0] = 0;
    
    while(!pq.empty()) {
        int total = pq.top().total;
        int now = pq.top().now;
        int cnt = pq.top().cnt;
        pq.pop();

        if(total > dist[now][cnt] || cnt >= N) continue;

        int sz = edge[now].size();
        for(int i=0; i<sz; i++) {
            int next = edge[now][i].first;
            int w = edge[now][i].second;

            if(dist[next][cnt+1] > total+w) {
                pq.push({total+w,next,cnt+1});
                dist[next][cnt+1] = total+w;
            }
        }
    }
    
    for(int i=0; i<=K; i++) {
        int P = 0;
        if(i != 0) cin >> P;
        int ans = INF;
        for(int j=1; j<=N; j++) {
            if(dist[D][j] == INF) continue;
            dist[D][j] += j*P;
            ans = min(ans,dist[D][j]);
        }
        cout << ans << "\n";
    }
}