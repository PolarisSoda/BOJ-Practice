#include <iostream>
#include <algorithm>

#define divisor 1000000000

using namespace std;

typedef long long int ll;

ll DP[101][1024][10] = {};

ll Dynamic(int digit,int ap,int last) {
    
    if(DP[digit][ap][last] == -1) {
        DP[digit][ap][last] = 0;
        ll& dp = DP[digit][ap][last];
        if(last != 9) {
            dp += Dynamic(digit-1,ap,last+1);
            dp %= divisor;
            if(ap & (1<<last)) {
                dp += Dynamic(digit-1,ap-(1<<last),last+1);
                dp %= divisor;
            }
        }
        if(last != 0) {
            dp += Dynamic(digit-1,ap,last-1);
            dp %= divisor;
            if(ap & (1<<last)) {
                dp += Dynamic(digit-1,ap-(1<<last),last-1);
                dp %= divisor;
            }
        }
    }
    return DP[digit][ap][last];
}

int main() {
    int N;
    cin >> N;
    ll ans = 0;
    for(int i=1; i<101; i++) {
        for(int j=0; j<1024; j++) {
            for(int k=0; k<10; k++) {
                if(j & (1<<k)) {
                    DP[i][j][k] = -1;
                } else {
                    DP[i][j][k] = 0;
                }
            }
        }
    }
    DP[1][1][0] = 0;
    for(int i=1; i<10; i++) {
        DP[1][1<<i][i] = 1;
    }
    for(int i=0; i<10; i++) {
        ans += Dynamic(N,1023,i);
        ans %= divisor;
    }
    cout << ans;
}
