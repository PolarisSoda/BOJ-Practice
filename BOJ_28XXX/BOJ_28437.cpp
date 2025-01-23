#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 100001;
int arr[LEN],DP[LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,Q;

    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        DP[arr[i]] = 1;
    }

    for(int i=1; i<=100000; i++) {
        for(int j=2; j<=100000; j++) {
            if(i*j > 100000) break;
            DP[i*j] += DP[i];
        }
    }

    cin >> Q;
    for(int i=0; i<Q; i++) {
        int temp;
        cin >> temp;
        cout << DP[temp] << " ";
    }
    exit(0);
}