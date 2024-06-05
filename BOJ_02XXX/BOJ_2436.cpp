#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll GCD(ll a,ll b) {
    ll r = a%b;
    if(r == 0) return b;
    return GCD(b, r);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll A,B;
    cin >> A >> B;
    ll M = B/A;

    ll AA,AB,S = 0x7FFFFFFF;
    for(ll i=1; i*i<=M; i++) {
        if(M%i == 0 && GCD(M/i,i) == 1) {
            if(S > M/i+i) S = M/i+i,AA = M/i,AB=i;
        }
    }
    cout << min(AA,AB)*A << " " << max(AA,AB)*A;
}