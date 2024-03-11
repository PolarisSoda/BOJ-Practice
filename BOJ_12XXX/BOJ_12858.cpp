#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int len;
vector<ll> RST,ST;

ll gcd(ll a,ll b) {
    if(a == 0) return b;
    if(b == 0) return a;

    if(a%b == 0) return b;
    return gcd(b,a%b);
}

void Init() {
    for(int i=len-1; i>0; i--) {
        ST[i] = gcd(ST[i<<1],ST[i<<1|1]);
    }
}
        
void R_Update(int left,int right,ll value) {
    int ans = 0;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1) {
        if(left&1) RST[left++] += value;
        if(right&1) RST[--right] += value;
    }
}
ll R_Query(int lo) {
    ll ans = 0;
    for(lo+=len; lo>0; lo>>=1) ans += RST[lo];
    return ans;
}

ll Query(int left,int right) {
    ll ans = 0;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1) {
        if(left&1) ans = gcd(ans,ST[left++]);
        if(right&1) ans = gcd(ans,ST[--right]);
    }
    return ans;
}
void Update(int lo,ll value) {
    for(ST[lo+=len] = value; lo>1; lo>>=1)
        ST[lo>>1] = gcd(ST[lo],ST[lo^1]);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N,Q;
    cin >> N;

    len = N+1;
    RST = vector<ll>(len<<1|1,0);
    ST = vector<ll>(len<<1|1,0);

    for(int i=1; i<=N; i++) {
        cin >> RST[len+i];
        ST[len+i] = abs(RST[len+i]-RST[len+i-1]);
    }
    Init();

    cin >> Q;
    for(int i=0; i<Q; i++) {
        int T,A,B;
        cin >> T >> A >> B;
        if(T == 0) {
            cout << gcd(R_Query(A),Query(A+1,B+1)) << "\n";
        } else {
            R_Update(A,B+1,T);
            ll l_diff = R_Query(A) - R_Query(A-1);
            ll r_diff = R_Query(B) - R_Query(B+1);
            Update(A,abs(l_diff));
            Update(B+1,abs(r_diff));
        }
    }
}

