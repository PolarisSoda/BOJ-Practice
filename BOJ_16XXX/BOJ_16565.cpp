#include <iostream>

using namespace std;

int C[53][53];

int main() {
    int N;
    cin >> N;
    int Q = N/4;
    int R = N%4;
    int ans = 0;
    for(int i=0; i<=52; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
        if(i>=2) {
            for(int j=1; j<=i-1; j++) {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
                C[i][j] %= 10007;
            }
        }
    }
    //cout << C[48][4] << endl;
    for(int i=1; i<=Q; i++) {
        if(i%2 == 0) {
            ans -= C[13][i] * C[52-4*i][N-4*i];
        } else {
            ans += C[13][i] * C[52-4*i][N-4*i];
        }
        ans %= 10007;
    }
    cout << (ans+10007)%10007;
}