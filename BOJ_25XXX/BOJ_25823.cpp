#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 iint;
constexpr iint DIV = 1000000007;

iint power(iint X,iint P) {
    iint ret = 1;
    while(P) {
        if(P&1) ret = (ret*X)%DIV;
        X = (X*X)%DIV;
        P >>= 1;
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    
    iint sum = 0, temp = 6;
    for(iint i=3; i<=N; i++) {
        temp = (temp*(i*2-1))%DIV;
        temp = (temp*i*2)%DIV;
        temp = (temp*power((i*i)%DIV,DIV-2))%DIV;
        sum = (sum + temp)%DIV;
    }
    cout << (ll)sum;
    exit(0);
}