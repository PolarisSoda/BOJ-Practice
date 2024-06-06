#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
struct compare {
    bool operator()(pii a,pii b) {
        return a.second > b.second;
    }
};

constexpr int LEN = 6001;
constexpr int INF = 0x7FFFFFFF;
vector<pii> edge[LEN];
int dist[LEN];

int Dijkstra(int S,int E,int X) {
    for(int i=1; i<=LEN; i++) dist[i] = INF;
    priority_queue<pii,vector<pii>,compare> pq;
    pq.push({S,0}), dist[S] = 0;
    while(!pq.empty()) {
        int now = pq.top().first;
        int total = pq.top().second;
        pq.pop();

        if(dist[now] < total) continue;
        dist[now] = total;
        for(auto tt : edge[now]) {
            int next = tt.first;
            int w = (tt.second == -1 ? X : tt.second);
            if(dist[next] > dist[now] + w) {
                pq.push({next,dist[next] = dist[now] + w});
            }
                
        }
    }
    return dist[E];
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,K;

    cin >> N;
    for(int i=1; i<=N; i++) {
        int temp;
        cin >> temp;
        for(int j=1; j<temp; j++) {
            int A = 100*i + j;
            edge[A].push_back({A+1,1});
            edge[A+1].push_back({A,1});
        }
    }

    cin >> M;
    for(int i=0; i<M; i++) {
        int A,B,C,D;
        cin >> A >> B >> C >> D;
        edge[A*100+B].push_back({C*100+D,-1});
        edge[C*100+D].push_back({A*100+B,-1});
    }
    
    cin >> K;
    for(int i=0; i<K; i++) {
        int T,A,B,C,D;
        cin >> T >> A >> B >> C >> D;
        cout << Dijkstra(A*100+B,C*100+D,T) << "\n";
    }
}