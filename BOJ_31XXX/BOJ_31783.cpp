#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 300001;
ll DP[LEN];
ll A[LEN],B[LEN],H[LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++) cin >> H[i];
    for(int i=2; i<=N; i++) cin >> A[i];
    for(int i=2; i<=N; i++) cin >> B[i];

    DP[1] = 0;
    for(int i=2; i<=N; i++) {
        ll height = H[i] + B[i];

        int left = 0, right = i, idx = -1;
        while(left+1<right) {
            int mid = (left+right) >> 1;
            if(H[mid] >= height) idx = left = mid;
            else right = mid;
        }
        DP[i] = DP[i-1];
        if(idx != -1) DP[i] = max(DP[i],DP[idx] + A[i]);
    }
    cout << DP[N];
    exit(0);
}