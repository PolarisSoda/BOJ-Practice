#include <bits/stdc++.h>

using namespace std;

struct info {
    int total;
    int now;
    int used;
};

struct compare {
    bool operator() (info a,info b) {
        return a.total > b.total;
    }
};

constexpr int LEN = 101;
constexpr int INF = 0x7FFFFFFF;

vector<info> edge[LEN];
int dist[LEN][10001];

void solve() {
    int N,M,K;
    cin >> N >> M >> K;
    
    for(int i=0; i<LEN; i++) for(int j=0; j<10001; j++) dist[i][j] = INF; 
    for(int i=0; i<LEN; i++) edge[i] = vector<info>();

    for(int i=0; i<K; i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        edge[a].push_back({b,c,d});
    }

    queue<info> task;
    task.push({0,1,0});

    while(!task.empty()) {
        int total = task.front().total;
        int now = task.front().now;
        int used = task.front().used;
        task.pop();

        if(total > dist[now][used]) continue;

        int sz = edge[now].size();
        for(int i=0; i<sz; i++) {
            int next = edge[now][i].total;
            int cost = edge[now][i].now;
            int w = edge[now][i].used;

            if(used+cost <= M && dist[next][used+cost] > total+w) {
                task.push({total+w,next,used+cost});
                dist[next][used+cost] = total+w;
            }
        }
    }
    int ans = INF;
    for(int i=0; i<=M; i++) ans = min(ans,dist[N][i]);

    if(ans == INF) cout << "Poor KCM\n";
    else cout << ans << "\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) solve();
    exit(0);
}