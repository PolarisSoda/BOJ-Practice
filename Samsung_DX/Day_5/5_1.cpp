#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N;

bool check(ll num) {
    if(num*(num+1)/2 <= N) return true;
    return false;
}

int solve() {
    cin >> N;
    ll left = 0;
    ll right = 10000000001;
    ll ans = -1;
    while(left+1 < right) {
        ll mid = (left+right)/2;
        if(check(mid)) {
            ans = mid;
            left = mid;
        } else right = mid;
    }
    if(ans*(ans+1)/2 != N) return -1;
    return ans;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " " << solve() << "\n";
}