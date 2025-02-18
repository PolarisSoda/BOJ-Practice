#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct info {
    int s,e,x;
};

constexpr int LEN = 50;
constexpr long long INF = LONG_LONG_MIN;
vector<info> edge;
ll arr[LEN],dist[LEN];
bool check[LEN][LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,S,E,M;
    cin >> N >> S >> E >> M;

    for(int i=0; i<M; i++) {
        int A,B,C;
        cin >> A >> B >> C;
        edge.push_back({A,B,-C});
        check[A][B] = true;
    }
    for(int i=0; i<N; i++) cin >> arr[i], check[i][i] = true;
    for(auto &tt : edge) tt.x += arr[tt.e];

    for(int i=0; i<N; i++) dist[i] = INF;
    dist[S] = arr[S];

    for(int i=0; i<N-1; i++) {
        for(auto now : edge)
            if(dist[now.s] != INF) dist[now.e] = max(dist[now.e],dist[now.s]+now.x);
    }

    for(int m=0; m<N; m++) {
        for(int s=0; s<N; s++) {
            for(int e=0; e<N; e++) {
                if(check[s][m] && check[m][e]) check[s][e] = true;
            }
        }
    }
    for(auto now : edge) if(dist[now.s] != INF && dist[now.s]+now.x > dist[now.e] && check[now.e][E]) cout << "Gee", exit(0);
    cout << (dist[E] == INF ? "gg" : to_string(dist[E]));
}