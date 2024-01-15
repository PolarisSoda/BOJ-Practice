#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

constexpr int LEN = 1001;
constexpr int LIMIT = 100001;
constexpr int INF = 1e8;
int A[LEN],B[LEN];
int DP[2][LIMIT];

void solve() {
    int N;
    cin >> N;

    for(int i=1; i<=N; i++) cin >> A[i] >> B[i];
    for(int i=0; i<2; i++) for(int j=0; j<LIMIT; j++) DP[i][j] = INF;

    DP[0][0] = 0;

    for(int i=1; i<=N; i++) {
        int now = i&1;
        for(int j=0; j<LIMIT; j++) {
            DP[now][j] = DP[now^1][j] + B[i];
            if(j - A[i] >= 0) DP[now][j] = min(DP[now][j],DP[now^1][j-A[i]]);
        }
    }
    int ans = INF;
    for(int i=0; i<LIMIT; i++) ans = min(ans, max(i,DP[N%2][i]));
    cout << ans << "\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) solve();
    exit(0);
}