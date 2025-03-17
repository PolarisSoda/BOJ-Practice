#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 100001, DIV = 1000000007;
int arr[2][LEN];
ll DP[2][LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[0][i];
    for(int i=1; i<N; i++) cin >> arr[1][i];

    DP[0][0] = 1;
    for(int i=1; i<=N; i++) {
        DP[0][i] = (DP[0][i-1]*(arr[0][i]+arr[1][i-1]) + DP[1][i-1]*(arr[0][i]+arr[1][i-1]-1)) % DIV;
        DP[1][i] = ((DP[0][i-1] + DP[1][i-1])*arr[1][i]) % DIV; 
    }
    cout << DP[0][N];
    exit(0);
}