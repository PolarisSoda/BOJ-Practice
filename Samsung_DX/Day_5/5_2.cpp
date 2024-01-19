#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll can[101];
ll N,M;

bool check(ll num) {
    if(num == 0) return true;
    ll sum = 0;
    for(int i=0; i<N; i++) sum += can[i]/num;
    if(sum >= M) return true;
    return false;
}
ll solve() {
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> can[i];

    ll left = -1;
    ll right = 1000000000000000001;
    ll ans = 0;
    while(left+1 < right) {
        ll mid = (left+right)/2;
        if(check(mid)) {
            ans = mid;
            left = mid;
        } else right = mid;
    }
    return ans;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " " << solve() << "\n";
}