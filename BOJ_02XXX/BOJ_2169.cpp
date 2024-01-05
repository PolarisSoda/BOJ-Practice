#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 1001;

int arr[MAX][MAX],DP[MAX][MAX];
int L[MAX][MAX],R[MAX][MAX];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) cin >> arr[j][i];

    for(int i=1; i<=M; i++) DP[i][1] = DP[i-1][1] + arr[i][1]; //N = 1
    for(int i=2; i<=N; i++) {
        for(int j=1; j<=M; j++) L[j][i] = j == 1 ? DP[j][i-1] + arr[j][i] : max(DP[j][i-1],L[j-1][i]) + arr[j][i];
        for(int j=M; j>=1; j--) R[j][i] = j == M ? DP[j][i-1] + arr[j][i] :  max(DP[j][i-1],R[j+1][i]) + arr[j][i];
        for(int j=1; j<=M; j++) DP[j][i] = max(L[j][i],R[j][i]); 
    }
    cout << DP[M][N];
    exit(0);
}