#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[100001] = {};

struct comp {
    bool operator() (pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

int main() {
    int N,M;
    cin >> N >> M;
    
    vector<pair<int,int>> edge[N+1];
    
    for(int i=0; i<M; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
    for(int i=0; i<edge[1].size(); i++) {
        pq.push(edge[1][i]);
    }
    visited[1] = true;
    int edgecnt = 0;
    int ans = 0;
    int max = -1;
    while(edgecnt < N-1) {
        int arrival = pq.top().first;
        int weight = pq.top().second;
        pq.pop();
        
        if(visited[arrival]) {
            continue;
        }
        
        for(int i=0; i<edge[arrival].size(); i++) {
            if(!visited[edge[arrival][i].first]) {
                pq.push(edge[arrival][i]);
            }
        }
        
        visited[arrival] = true;
        edgecnt++;
        ans += weight;
        if(weight > max) {
            max = weight;
        }
    }
    cout << ans - max;
}