#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll BIG = 0x7FFFFFFF;
ll DP[201][201];

ll C(int N,int R) {
    if(N == 0) return 1;
    if(R == 0 || N == R) return 1;
    if(!DP[N][R]) {
        ll ret = C(N-1,R) + C(N-1,R-1);
        DP[N][R] = (ret >= BIG ? BIG : ret);
    }
    return DP[N][R];
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll N,M,K;
    cin >> N >> M >> K;

    string ans = "";

    int un = N, um = M;
    if(C(N+M,M) < K) cout << -1,exit(0);
    for(int i=1; i<=N+M; i++) {
        ll rank = C(un-1+um,um);
        if(un > 0 && K <= rank) ans += 'a',un--;
        else ans += 'z',um--,K -= rank;
    }
    cout << ans;
    exit(0);
}