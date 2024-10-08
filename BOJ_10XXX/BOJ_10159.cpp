#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 101;
int edge[LEN][LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    for(int i=0; i<M; i++) {
        int A,B;
        cin >> A >> B;
        edge[A][B] = 1;
    }

    for(int m=1; m<=N; m++) {
        for(int s=1; s<=N; s++) {
            for(int e=1; e<=N; e++) {
                if(edge[s][m] && edge[m][e]) edge[s][e] = 1;
            }
        }
    }
    for(int i=1; i<=N; i++) {
        int cnt = N-1;
        for(int j=1; j<=N; j++) {
            if(edge[i][j] || edge[j][i]) cnt--;   
        }
        cout << cnt << "\n";
    }
    exit(0);
}