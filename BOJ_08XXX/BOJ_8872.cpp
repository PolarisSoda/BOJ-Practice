#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

constexpr int LEN = 100001;
vector<pii> edge[LEN];
vector<int> dia;
bool visited[2][LEN];
int weight[LEN],pre[LEN];
int N,M,L;

int make_diameter(int num) {
    queue<int> task;
    task.push(num);
    visited[0][num] = true;
    int S = num, E = num, V = 0;
    while(!task.empty()) {
        int now = task.front();
        task.pop();
        for(auto &[next,w] : edge[now]) {
            if(visited[0][next]) continue;
            visited[0][next] = true;
            weight[next] = weight[now]+w;
            if(weight[next] > V) S = next, V = weight[next];
            task.push(next);
        }
    }
    
    task.push(S);
    visited[1][S] = true, weight[S] = 0, pre[S] = S;
    while(!task.empty()) {
        int now = task.front();
        task.pop();
        for(auto &[next,w] : edge[now]) {
            if(visited[1][next]) continue;
            visited[1][next] = true;
            pre[next] = now;
            weight[next] = weight[now]+w;
            if(weight[next] > V) E = next, V = weight[next];
            task.push(next);
        }
    }
    int cur = pre[E],maxdiff = 0x7FFFFFF,maxd = 0;
    while(pre[cur] != cur) {
        int fi = weight[cur], se = V - weight[cur];
        if(abs(fi-se) < maxdiff) maxdiff = abs(fi-se),maxd = max(fi,se);
        cur = pre[cur];
    }
    dia.push_back(maxd);
    return V;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> L;
    for(int i=0; i<M; i++) {
        int A,B,T;
        cin >> A >> B >> T;
        edge[A].push_back({B,T});
        edge[B].push_back({A,T});
    }

    int ans = 0;
    for(int i=0; i<N; i++) if(visited[0][i] == false) ans = max(ans,make_diameter(i));
    sort(dia.begin(),dia.end(),greater<int>());
    int fi = dia.size() >= 2 ? dia[0]+dia[1]+L : 0;
    int se = dia.size() >= 3 ? dia[1]+dia[2]+2*L : 0;
    cout << max({ans,fi,se});
    exit(0);
}