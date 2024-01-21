#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct info {
    int L,R,W;
    ll V;
};

constexpr int LEN = 101;
constexpr ll INF = 0x7FFFFFFFFF;
ll DP[LEN][LEN][2];

void solve() {
    int N,A;
    cin >> N >> A;

    for(int i=0; i<LEN; i++) for(int j=0; j<LEN; j++) DP[i][j][0] = DP[i][j][1] = INF;
    vector<ll> arr;
    arr.push_back(1);
    for(int i=0; i<N-1; i++) {
        ll temp;
        cin >> temp;
        temp += arr.back();
        arr.push_back(temp);
    }

    queue<info> task;
    task.push({A-1,A-1,0,0});

    while(!task.empty()) {
        int L = task.front().L;
        int R = task.front().R;
        int W = task.front().W;
        ll V = task.front().V;
        task.pop();

        if(V > DP[L][R][W]) continue;
        DP[L][R][W] = V;

        ll cnt = N-R+L-1;
        if(L != 0) {
            ll D = arr[W == 0 ? L : R] - arr[L-1];
            task.push({L-1,R,0,V+D*cnt});
        }
        if(R != N-1) {
            ll D = arr[R+1] - arr[W == 0 ? L : R];
            task.push({L,R+1,1,V+D*cnt});
        }
    }
    cout << min(DP[0][N-1][0],DP[0][N-1][1]) << "\n";
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--) solve();
    exit(0);
}