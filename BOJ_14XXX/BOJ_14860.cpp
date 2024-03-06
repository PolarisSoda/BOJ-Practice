#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr ll DIV = 1000000007;
constexpr int LEN = 15000001;

vector<int> prime;
bool visited[LEN];

ll power(ll X,ll P) {
    ll ret = 1;
    while(P) {
        if(P&1) ret = (ret*X)%DIV;
        X = (X*X)%DIV;
        P >>= 1;
    }
    return ret;
}

int main() {
    ll N,M;
    cin >> N >> M;
    
    ll limit = min(N,M);
    for(int i=2; i<=limit; i++) {
        if(visited[i]) continue;
        prime.push_back(i);
        for(int j=i+i; j<=limit; j+=i) visited[j] = true;
    }

    ll ans = 1;
    for(ll num : prime) {
        ll bias = num;
        while(bias <= limit) {
            ll radix = (N/bias) * (M/bias);
            ans = (ans * power(num,radix)) % DIV;
            bias *= num;
        }
    }
    cout << ans;
    exit(0);
}