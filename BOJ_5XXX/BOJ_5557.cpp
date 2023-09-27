#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 100;

int arr[LEN];
ll DP[LEN][21];

int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    DP[0][arr[0]]++;
    for(int i=1; i<N-1; i++) {
        int num = arr[i];
        for(int j=0; j<=20; j++) {
            if(j+num <= 20) DP[i][j+num] += DP[i-1][j];
            if(j-num >= 0) DP[i][j-num] += DP[i-1][j];
        }
    }
    cout << DP[N-2][arr[N-1]];
    return 0;
}