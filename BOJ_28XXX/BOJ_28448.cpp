#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

vector<pll> Q;
ll ans = 0;

bool compare(pll a,pll b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,L;
    cin >> N >> L;
    for(int i=0; i<N; i++) {
        int K,T;
        cin >> K >> T;
        ans += T;
        if(T > 5) Q.push_back({K,T});
    }
    sort(Q.begin(),Q.end(),compare);

    ll ret = 0;
    ll last = 0;
    int sz = Q.size();
    for(auto tt : Q) {
        ll fi = tt.first * tt.second;
        ll se = tt.first * 5;

        ret += fi-se;
        last += fi;
        if(last >= L) last = L;
        last -= se;
    }
    ret -= last;
    if(ret > 0) ans += ret;
    cout << ans;
    exit(0);
}