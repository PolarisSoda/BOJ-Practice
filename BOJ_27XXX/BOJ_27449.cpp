#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef tuple<ll,ll,ll,ll,ll> info;

constexpr int LEN = 5001;
vector<pll> flow;
ll DP[LEN][LEN][2];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(DP,-1,sizeof(DP));

    int N,M;
    cin >> N >> M;

    int f_idx = 0;
    flow.push_back({0,M});
    for(int i=0; i<N; i++) {
        int X,P;
        cin >> X >> P;
        if(X < 0) f_idx++;
        flow.push_back({X,P});
    }
    sort(flow.begin(),flow.end());

    DP[f_idx][f_idx][0] = M;
    queue<info> task;
    task.push({f_idx,f_idx,0,M,M});
    ll ans = -1;
    while(!task.empty()) {
        ll left,right,where,total,ret;
        tie(left,right,where,total,ret) = task.front();
        task.pop();

        if(DP[left][right][where] > total) continue;
        DP[left][right][where] = total;
        ans = max(ans,ret);
        int now = where == 0 ? left : right;
        if(left != 0) {
            ll dist = flow[now].first - flow[left-1].first;
            if(dist < DP[left][right][where]) {
                if(DP[left-1][right][0] < DP[left][right][where] - dist + flow[left-1].second) {
                    DP[left-1][right][0] = DP[left][right][where] - dist + flow[left-1].second;
                    task.push({left-1,right,0,DP[left-1][right][0],ret+flow[left-1].second});
                }
            }
        }
        if(right != N) {
            ll dist = flow[right+1].first - flow[now].first;
            if(dist < DP[left][right][where]) {
                if(DP[left][right+1][1] < DP[left][right][where] - dist + flow[right+1].second) {
                    DP[left][right+1][1] = DP[left][right][where] - dist + flow[right+1].second;
                    task.push({left,right+1,1,DP[left][right+1][1],ret+flow[right+1].second});
                }
            }
        }
    }
    cout << ans;
    exit(0);
}