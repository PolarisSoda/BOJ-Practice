#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 1000001;
ll ball[LEN];
int N,M;

bool check(ll num) {
    ll sum = 0;
    for(int i=0; i<N; i++) {
        sum += num/ball[i];
        if(sum >= M) return true;
    }
    return false;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> ball[i];

    ll left = 0, right = 1'000'000'000'001,ans;
    while(left+1<right) {
        ll mid = (left+right)>>1LL;
        if(check(mid)) right = ans = mid;
        else left = mid;
    }
    cout << ans;
    exit(0);
}