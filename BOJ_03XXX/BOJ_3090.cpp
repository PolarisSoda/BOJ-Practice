#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int INF = 0x7FFFFFFF;
constexpr int LEN = 100001;
ll arr[LEN], lst[LEN];
ll N,T;

bool check(ll num) {
    //T번 조져서 차이를 num이하로 만들 수 있는가.
    //memset(lst,0,sizeof(lst));
    ll cnt = 0;

    lst[1] = arr[1]; 
    for(int i=2; i<=N; i++) {
        lst[i] = arr[i];
        ll diff = lst[i] - lst[i-1];
        if(diff > num) {
            cnt += diff - num;
            lst[i] -= diff - num;
        }
    }
    for(int i=N-1; i>=1; i--) {
        ll diff = abs(lst[i]-lst[i+1]);
        if(diff > num) {
            cnt += diff - num;
            lst[i] -= diff - num;
        }
    }
    if(cnt <= T) return true;
    return false;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> T;
    for(int i=1; i<=N; i++) cin >> arr[i];

    ll left = -1, right = INF, ans;
    while(left+1<right) {
        ll mid = (left+right)/2;
        if(check(mid)) right = ans = mid;
        else left = mid;
    }
    check(ans);
    for(int i=1; i<=N; i++) cout << lst[i] << " ";
}