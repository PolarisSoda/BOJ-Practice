#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
struct info {
    int s,e,x;
};

constexpr int LEN = 1001;
vector<info> edge;
vector<pii> d_edge[LEN];
int pt[LEN], dist[LEN][LEN];
bool visited[LEN];

bool compare(info a,info b) {
    return a.x < b.x;
}

int root(int num) {
    if(pt[num] == num) return num;
    return pt[num] = root(pt[num]);
}

void uni(int a,int b) {
    a = root(a);
    b = root(b);
    if(a != b) pt[b] = a;
}

void DS(int num) {
    memset(visited,false,sizeof(visited));
    visited[num] = true;
    queue<int> task;
    task.push(num);
    while(!task.empty()) {
        int now = task.front();
        task.pop();
        for(pii temp : d_edge[now]) {
            int next = temp.first;
            int w = temp.second;
            if(visited[next] == false) {
                visited[next] = true;
                dist[num][next] = max(dist[num][now],w);
                task.push(next);
            }
        } 
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,Q;
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int A,B,C;
        cin >> A >> B >> C;
        edge.push_back({A,B,C});
    }

    for(int i=1; i<=N; i++) pt[i] = i;
    sort(edge.begin(),edge.end(),compare);
    int sum = 0, ecnt = 0;
    for(info now : edge) {
        if(root(now.s) != root(now.e)) {
            uni(now.s,now.e);
            sum += now.x;
            d_edge[now.s].push_back({now.e,now.x});
            d_edge[now.e].push_back({now.s,now.x});
            if(++ecnt == N-1) break;
        }
    }

    for(int i=1; i<=N; i++) DS(i);
    cin >> Q;

    for(int i=0; i<Q; i++) {
        int X,Y;
        cin >> X >> Y;
        cout << sum - dist[X][Y] << "\n";
    }
    exit(0);
}