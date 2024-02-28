#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 111111;
constexpr ll INF = 1000000000000000;
ll s_cnt[LEN];
int N;

bool check(int num) {
    ll zeros = 0, r_bias = 1;

    for(int i=num; i<=N; i++) zeros += s_cnt[i];
    for(int i=num-1; i>=1; i--) {
        if(r_bias <= s_cnt[i]) zeros += s_cnt[i] - r_bias;
        else r_bias += r_bias - s_cnt[i];
        r_bias = min(r_bias,INF);
    }
    if(r_bias <= zeros+s_cnt[0]) return true;
    return false;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    ll sum = 0;
    int maxv = 0;
    for(int i=0; i<N; i++) {
        cin >> s_cnt[i];
        if(s_cnt[i] != 0) sum += s_cnt[i], maxv = i;
    }
    if(sum == 1) cout << max(1,maxv), exit(0);

    int left = 0;
    int right = LEN;
    int ans = 0;
    while(left+1<right) {
        int mid = (left+right)/2;
        if(check(mid)) ans = left = mid;
        else right = mid;
    }
    cout << ans;
    exit(0);
}