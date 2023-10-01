#include <iostream>
#include <vector>
#define dividor 1000000000
using namespace std;

long long int DP[1000001] = {};

int main() {
    int N;
    cin >> N;
    DP[0] = 1;
    long long int ans;
    bool plus;
    
    if(N == 1) {
        cout << 0;
        return 0;
    }
    if(N%2) {
        plus = true;
        ans = -1;
    } else {
        plus = false;
        ans = 1;
    }
    
    for(int i=1; i<=N-2; i++) {
        DP[i] = DP[i-1] * (N-i+1);
        DP[i] %= dividor;
        if(plus) {
            ans += DP[i];
            ans %= dividor;
            plus = false;
        } else {
            ans += dividor;
            ans -= DP[i];
            ans %= dividor;
            plus = true;
        }
        //cout << ans << " ";
    }
    cout << ans;
}