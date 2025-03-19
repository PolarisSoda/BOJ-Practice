#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N;
vector<ll> V;

bool check(ll itv) {
    if(V[0] > itv) return false;

    int cnt = N-1;
    int filled = 0;
    for(ll now : V) {
        ll temp = (now-1)/itv + 1;
        filled += temp - 1; 
    }
    if(cnt >= filled) return true;
    return false;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    V.resize(N);
    for(int i=0; i<N; i++) cin >> V[i];
    sort(V.begin(),V.end());

    ll left = 0, right = V[N-1]+1, ans = 0;
    while(left+1<right) {
        ll mid = (left+right)>>1LL;
        if(check(mid)) right = ans = mid;
        else left = mid;
    }
    cout << ans;
    exit(0);
}