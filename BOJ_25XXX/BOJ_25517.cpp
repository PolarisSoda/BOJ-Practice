#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll DIV = 1000000007;

vector<ll> called;
ll pre[] = {/*This is deleted because it takes too much space.*/};
ll power(ll X,ll P) {
    ll ret = 1;
    while(P) {
        if(P&1) ret = (ret*X)%DIV;
        X = (X*X)%DIV;
        P >>= 1;
    }
    return ret;
}
ll Fact(ll s,ll e) {
    ll ret = 1;
    for(ll i=s; i<=e; i++) ret = (ret*i)%DIV;
    return ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll N,M;
    cin >> N >> M;
    ll Q = N/1000000;
    ll R = N%1000000;
    ll ans = pre[Q];
    ans = (ans * Fact(Q*1000000+1,N))%DIV;

    for(int i=0; i<M; i++) {
        ll temp;
        cin >> temp;
        called.push_back(temp);
    }
    sort(called.begin(),called.end());
    called.erase(unique(called.begin(),called.end()),called.end());
    for(ll num : called) ans = (ans*power(num,DIV-2))%DIV;
    cout << ans;
    exit(0);
}