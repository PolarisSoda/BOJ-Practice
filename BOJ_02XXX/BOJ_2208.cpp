#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 100001;
int DP[LEN],arr[LEN],pfx[LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> arr[i], pfx[i] = arr[i] + pfx[i-1];
    DP[1] = max(0,arr[1]);
    for(int i=2; i<=N; i++) DP[i] = arr[i] + max(DP[i-1],0);
    
    int ans = 0;
    for(int i=M; i<=N; i++) ans = max(ans,pfx[i]-pfx[i-M]+DP[i-M]);
    cout << ans;
    exit(0);
}