#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 200001;
ll A[LEN],PFX[LEN];
unordered_map<ll,ll> HS;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    ll ans = 0;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) {
        int temp;
        cin >> temp;
        A[i] -= temp;
        PFX[i] = A[i] + PFX[i-1];
        if(PFX[i] == 0) ans++;
        ans += HS[PFX[i]];
        HS[PFX[i]]++;
    }
    cout << ans;
    exit(0);
}