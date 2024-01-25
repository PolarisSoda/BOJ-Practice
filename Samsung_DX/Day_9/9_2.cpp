#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int len;
vector<ll> ST;

void Init() {
    for(int i=len-1; i>0; i--) {
        ST[i] = ST[i<<1] + ST[i<<1|1];
    }
}
ll Query(int left,int right) {
    int o_left = left;
    ll ans = 0;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1) {
        if(left&1)
            ans += ST[left++];
        if(right&1)
            ans += ST[--right];
    }
    if(o_left%2) ans *= -1;
    return ans;
}

void Update(int lo,ll value) {
    if(lo%2) value *= -1;
    for(ST[lo+=len] = value; lo>1; lo>>=1) {
        ST[lo>>1] = ST[lo] + ST[lo^1];
    }
}

void solve() {
    int N,Q;
    cin >> N >> Q;

    len = N;
    ST = vector<ll>(N<<1|1,0);
    for(int i=0; i<N; i++) {
        ll temp;
        cin >> temp;
        if(i%2) temp *= -1;
        ST[len+i] = temp;
    }
    Init();

    for(int i=0; i<Q; i++) {
        int A,B,C;
        cin >> A >> B >> C;
        if(A == 0) Update(B,C);
        else cout << Query(B,C) << " ";

    }
    cout << "\n";
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " ", solve();
    return 0;
}