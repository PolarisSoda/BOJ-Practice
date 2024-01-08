#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int DIV = 1000000007;
ll DP[101][101][101];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    DP[1][1][1] = 1;
    DP[2][2][1] = 1;
    DP[1][2][2] = 1;
    for(int i=3; i<=100; i++) {
        for(int j=1; j<=i; j++) {
            for(int k=1; k<=i; k++) {
                if(i+j == 2 || j+k > i+1) continue;
                DP[j][i][k] = DP[j-1][i-1][k] + DP[j][i-1][k-1] + DP[j][i-1][k]*(i-2);
                DP[j][i][k] %= DIV;
            }
        }
    }

    int N,L,R;
    cin >> N >> L >> R;
    cout << DP[L][N][R];
    exit(0);
}