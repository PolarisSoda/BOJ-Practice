#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

void solve() {
    int M,P,A,B;
    cin >> M >> P >> A >> B;
    int xc = (M+A*B)/(A+1);
    int yc = (xc-B)*A;
    int rm = M - xc - yc;

    double ans = 0;
    double bias = 1;
    for(int i=0; i<P; i++) bias *= sqrt(A);
    for(int i=0; i<xc; i++) ans += bias;
    for(int i=0; i<yc; i++) ans += 1/bias;
    if(rm > 1) {
        int savior = 0;
        for(int i=1; i<rm; i++) {
            ans += 1/bias;
            if(++savior == A) {
                savior = 0;
                ans += bias;
            }
        }
        if(savior != 0) {
            bias = savior/sqrt(A);
            double temp = 1;
            for(int i=0; i<P; i++) temp *= bias;
            ans += temp;
        }
    }
    cout << ans << "\n";
} 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    cout << fixed;
    cout.precision(0);
    while(T--) solve();
    return 0;
}