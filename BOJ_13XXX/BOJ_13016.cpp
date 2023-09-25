#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

constexpr int LEN = 50001;

vector<pii> edge[LEN];
bool visited[LEN];
ll dist[LEN][2],mv;
int opp;

void DFS(int now,int flag) {
    for(pii temp : edge[now]) {
        int next = temp.first;
        int cost = temp.second;
        if(visited[next] == true) continue;
        visited[next] = true;
        dist[next][flag] = dist[now][flag] + cost;
        if(dist[next][flag] > mv) mv = dist[opp = next][flag];
        DFS(next,flag);
        visited[next] = false; 
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for(int i=0; i<N-1; i++) {
        int A,B,C;
        cin >> A >> B >> C;
        edge[A].push_back({B,C});
        edge[B].push_back({A,C});
    }

    visited[1] = true;
    DFS(1,0);
    memset(dist,false,sizeof(dist));

    for(int i=0; i<2; i++) {
        int temp = opp;
        memset(visited,false,sizeof(visited));
        visited[opp] = true;
        DFS(temp,i);
    }

    for(int i=1; i<=N; i++) cout << max(dist[i][0],dist[i][1]) << "\n";
}