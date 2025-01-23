#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 100001;
int P[LEN],PFX[LEN];
vector<int> edge[LEN];

void DFS(int now,int prev,int sum) {
    PFX[now] = sum + P[now];
    for(int next : edge[now]) DFS(next,now,PFX[now]);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,trash;
    cin >> N >> M;

    cin >> trash;
    for(int i=2; i<=N; i++) {
        int S;
        cin >> S;
        edge[S].push_back(i);
    }

    for(int i=0; i<M; i++) {
        int I,W;
        cin >> I >> W;
        P[I] += W;
    }

    DFS(1,-1,0);
    for(int i=1; i<=N; i++) cout << PFX[i] << " ";
    exit(0);
}