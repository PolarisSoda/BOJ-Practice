#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll N,K,Q;
    cin >> N >> K >> Q;

    ll cnt = 0;
    for(ll i=1; i<=N; i++) {
        for(int j=1; j<=K; j++) {
            ll temp;
            cin >> temp;
            temp -= i;
            if(temp < 0) temp += N;
            cnt += temp;
        }
        if(i == 1 && cnt == 0) cnt += N;
    }
    if(cnt%N != 0) cout << 0;
    else {
        if(cnt/N <= Q) cout << 1;
        else cout << 0;
    }
    return 0;
}