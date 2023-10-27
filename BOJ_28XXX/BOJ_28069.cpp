#include <bits/stdc++.h>

using namespace std;

int DP[3000001];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K;
    cin >> N >> K;

    for(int i=1; i<=1000000; i++) DP[i] = 0x7FFFFFFF;
    for(int i=0; i<=1000000; i++) {
        DP[i+1] = min(DP[i]+1,DP[i+1]);
        DP[i+i/2] = min(DP[i]+1,DP[i+i/2]);
    }
    if(DP[N] <= K) cout << "minigimbob";
    else cout << "water";
    return 0;
}