#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
struct comp {
    bool operator() (pll a,pll b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};

deque<pll> cow;

bool compare(pll a,pll b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

bool compare2(pll a,pll b) {
    if(a.first == b.first) return a.second < b.second; 
    return a.first < b.first;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll N,K,M;
    cin >> N >> K >> M;

    for(int i=0; i<N; i++) {
        ll P,C;
        cin >> P >> C;
        cow.push_back({P,C});
    }
    sort(cow.begin(),cow.end(),compare);

    priority_queue<pll,vector<pll>,comp> pq;
    int ans = 0;

    for(int i=0; i<K; i++) {
        auto now = cow.front();
        if(M < now.second) break;
        M -= now.second;
        pq.push(now);
        cow.pop_front();
        ans++;
    }
    sort(cow.begin(),cow.end(),compare2);
    for(int i=0; i<N-K; i++) {
        if(cow.size() == 0) break;
        if(pq.empty()) {
            continue;
        }
        ll ori = pq.top().first;
        ll dis = pq.top().second;
        ll fi = M - cow.front().first;
        ll se = M + dis - ori - cow.front().second;
        auto ff = cow.front();
        cow.pop_front();
        if(fi < se) {
            if(se < 0) continue;
            ans++;
            M = se;
            pq.pop();
            pq.push(ff);
        } else {
            if(fi < 0) continue;
            ans++;
            M = fi;
        }
    }

    cout << ans;
    exit(0);
}