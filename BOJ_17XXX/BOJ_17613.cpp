#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

map<pll,int> HS;

int Dynamic(ll X, ll Y) {
    if(HS.count({X,Y}) != 0) return HS[{X,Y}];

	int ret = 0;
    for(int i=1; i<=32; i++) {
        ll bias = (1LL<<i) - 1;
        ll left = bias, right = (1LL<<(i+1)) - 2;
        
        if(right < X || Y < left) continue;
        left = max(left,X) - bias;
        right = min(right,Y) - bias;
        
        ret = max(ret,i+Dynamic(left,right));
    }
    return HS[{X,Y}] = ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--) {
        ll X,Y;
        cin >> X >> Y;
        cout << Dynamic(X,Y) << "\n";
    }
    exit(0);
}