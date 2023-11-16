#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int A[4001];
ll prefix[4001];
void solve() {
    int N;
    cin >> N;

    for(int i=1; i<=N; i++) cin >> A[i];
    sort(A+1,A+N+1);

    for(int i=1; i<=N; i++) prefix[i] = prefix[i-1] + A[i];
    
    ll ans = 0;
    for(int i=1; i<=N; i++) {
        ll temp = 0x7FFFFFFF;
        for(int j=1; j<=N; j++) {
            if(j-i < 0) continue;
            temp = min(temp,A[j]*i - (prefix[j] - prefix[j-i]));
        }
        ans += temp;
    }
    cout << ans << "\n";
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}