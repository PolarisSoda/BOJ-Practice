#include <bits/stdc++.h>

using namespace std;

struct info {
    int x,y,val;
};
struct compare {
    bool operator()(info a,info b) {
        return a.val > b.val;
    }  
};

constexpr int INF = 0x7FFFFFFF;
int arr[102][102],dist[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int N;

bool Approx(int x,int y) {
    if(x>=1 && x<=N && y>=1 && y<=N) return true;
    return false;
}
int solve() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            char c;
            cin >> c;
            arr[j][i] = c - '0';
            dist[j][i] = INF;
        }
    }

    priority_queue<info,vector<info>,compare> pq;
    pq.push({1,1,0});
    while(!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int val = pq.top().val;
        pq.pop();

        if(x == N && y == N) return val;
        dist[x][y] = val;
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(Approx(nx,ny)) {
                int new_dist = val + arr[nx][ny];
                if(dist[nx][ny] > new_dist) pq.push({nx,ny,new_dist});
            }
        }
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " " << solve() << "\n";
}