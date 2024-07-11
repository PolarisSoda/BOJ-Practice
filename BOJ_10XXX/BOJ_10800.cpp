#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct info {
    int W,C,idx;
};

constexpr int LEN = 200001;

ll cnt[LEN],ans[LEN];
vector<info> V;

bool compare(info a,info b) {
    return a.W < b.W;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int C,S;
        cin >> C >> S;
        V.push_back({S,C,i});
    }
    sort(V.begin(),V.end(),compare);

    queue<info> task;
    ll sum = 0;
    for(auto tt : V) {
        while(true) {
            if(task.empty() || task.front().W == tt.W) break;
            auto now = task.front();
            task.pop();
            sum += now.W, cnt[now.C] += now.W;
        }
        ans[tt.idx] = sum - cnt[tt.C];
        task.push(tt);
    }

    for(int i=0; i<N; i++) cout << ans[i] << "\n";
    exit(0);
}