#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll DP[21][21]; //i개를 j개의 폭탄으로 열수 있는 모든 경우의 수.
//DP[i][j] = DP[i-1][j-1] + DP[i-1][j]*(????????)

ll GCD(ll a,ll b) {
    ll r = a%b;
    if (r == 0) return b;
    return GCD(b,r);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    DP[1][1] = 1;
    for(int i=2; i<=N; i++) {
        for(int j=1; j<=i; j++) {
            DP[i][j] = DP[i-1][j-1] + DP[i-1][j]*(i-1);
        }
    }
    ll A = 0, B = 0, C = 0;
    for(int i=1; i<=M; i++) A += DP[N][i];
    for(int i=1; i<=N; i++) B += DP[N][i];
    C = GCD(A,B);
    cout << A/C << "/" << B/C;
}