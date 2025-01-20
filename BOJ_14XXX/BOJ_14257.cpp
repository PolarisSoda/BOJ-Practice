#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll S,X;
    cin >> S >> X;
    
    if(S < X) cout << 0, exit(0);
    if(S-X & 1) cout << 0, exit(0);
    
    int ocnt = 0;
    ll res = (S - X)>>1LL;
    

    for(int i=50; i>=0; i--) {
        if((X>>i)&1) ocnt++;
        else {
            ll temp = 1LL << i;
            if(res >= temp) res -= temp;
        }
    }
    
    if(res != 0) cout << 0, exit(0);
    ll ans = 1LL<<ocnt;
    if(S == X) ans -= 2;

    cout << ans;
    exit(0);
}