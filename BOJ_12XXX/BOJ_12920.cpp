#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<pii> item;

int DP[10001][10001];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int V,C,K;
        cin >> V >> C >> K;
        int p = 1;
        while(K >= p) {
            item.push_back({V*p,C*p});
            K -= p;
            p <<= 1;
        }
        if(K != 0) item.push_back({V*K,C*K});
    }
    int sz = item.size();
    for(int i=1; i<=sz; i++) {
        int W = item[i-1].first;
        int P = item[i-1].second;
        for(int j=1; j<=M; j++) {
            if(W > j) DP[i][j] = DP[i-1][j];
            else DP[i][j] = max(DP[i-1][j-W]+P,DP[i-1][j]);
        }
    }
    cout << DP[sz][M];
    return 0;
}