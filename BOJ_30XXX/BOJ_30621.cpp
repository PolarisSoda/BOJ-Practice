#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 100001;
ll T[LEN],B[LEN],C[LEN],DP[LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> T[i];
    for(int i=1; i<=N; i++) cin >> B[i];
    for(int i=1; i<=N; i++) cin >> C[i];

    ll ans = DP[1] = C[1];
    for(int i=2; i<=N; i++) {
        ll left = 0, right = i, idx = 0;
        while(left+1<right) {
            int mid = (left+right)/2;
            if(T[mid] < T[i] - B[i]) left = idx = mid;
            else right = mid;
        }
        DP[i] = max(DP[i-1],DP[idx]+C[i]);
        ans = max(DP[i],ans);
    }
    cout << ans;
    exit(0);
}