#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
struct compare {
    bool operator()(pii a,pii b) {
        return a.second > b.second;
    }
};

constexpr int LEN = 601;
constexpr int INF = 0x7FFFFFF;
unordered_map<int,int> func;
vector<pii> edge[LEN],redge[LEN];
vector<int> dist;
int idx;

int init(int N, int sCity[], int eCity[], int mCost[]) {
    func.clear();
    for(int i=0; i<LEN; i++) edge[i] = vector<pii>(), redge[i] = vector<pii>();
    idx = 0;

    for(int i=0; i<N; i++) if(func.count(sCity[i]) == 0) func[sCity[i]] = idx++;
    for(int i=0; i<N; i++) {
        int s = func[sCity[i]];
        int e = func[eCity[i]];
        int x = mCost[i];
        edge[s].push_back({e,x});
        redge[e].push_back({s,x});
    }
    return func.size();
}

void add(int sCity, int eCity, int mCost) {
    int s = func[sCity];
    int e = func[eCity];
    edge[s].push_back({e,mCost});
    redge[e].push_back({s,mCost});
}

int cost(int mHub) {
    int X = func[mHub];
    int ret = 0;
    priority_queue<pii,vector<pii>,compare> pq;

    dist = vector<int>(idx,INF);
    pq.push({X,0});
    dist[X] = 0;
    while(!pq.empty()) {
        int now = pq.top().first;
        int total = pq.top().second;
        pq.pop();
        
        if(dist[now] < total) continue;

        int sz = edge[now].size();
        for(int i=0; i<sz; i++) {
            int next = edge[now][i].first;
            int w = edge[now][i].second;
            if(dist[next] > total+w) {
                dist[next] = total+w;
                pq.push({next,dist[next]});
            }
        }
    }
    for(int i=0; i<idx; i++) ret += dist[i];

    dist = vector<int>(idx,INF);
    pq.push({X,0});
    dist[X] = 0;

    while(!pq.empty()) {
        int now = pq.top().first;
        int total = pq.top().second;
        pq.pop();

        if(dist[now] < total) continue;

        int sz = redge[now].size();
        for(int i=0; i<sz; i++) {
            int next = redge[now][i].first;
            int w = redge[now][i].second;
            if(dist[next] > total+w) {
                dist[next] = total+w;
                pq.push({next,total+w});
            }
        }
    }
    for(int i=0; i<idx; i++) ret += dist[i];
	return ret;
}