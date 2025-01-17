#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 30001;
int candy[LEN],pt[LEN];
unordered_map<int,pair<int,int>> HS;

int root(int num) {
    if(pt[num] == num) return num;
    return pt[num] = root(pt[num]);
}

void uni(int a,int b) {
    a = root(a);
    b = root(b);
    if(a != b) pt[b] = a;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,K;
    cin >> N >> M >> K;

    for(int i=1; i<=N; i++) {
        cin >> candy[i];
        pt[i] = i;
    }

    for(int i=0; i<M; i++) {
        int A,B;
        cin >> A >> B;
        if(A > B) swap(A,B);
        uni(A,B);
    }

    for(int i=1; i<=N; i++) {
        HS[root(i)].first++;
        HS[root(i)].second += candy[i];
    }

    int DP[2][3002];
    int ans = 0, toggle = 0;

    memset(DP,0,sizeof(DP));
    for(auto tt : HS) {
        int W = tt.second.first, P = tt.second.second;
        for(int i=1; i<=K; i++) {
            if(W > i) DP[toggle][i] = DP[toggle^1][i];
            else DP[toggle][i] = max(DP[toggle^1][i],DP[toggle^1][i-W] + P);
        }
        toggle ^= 1;
    }
    cout << max(DP[0][K-1],DP[1][K-1]);
    exit(0);
}