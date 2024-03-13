#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 1000000000;

int EGCD(int A,int B,int &X,int &Y) {
    //ax + by = gcd(a, b)
    int R = A; 
    X = 1, Y = 0;
    if(B != 0) R = EGCD(B,A%B,Y,X), Y -= A/B*X;
    return R;
}

string solve() {
    int N,K,X,Y;
    cin >> N >> K;
    if(N == 1 && K == 1) return "2";
    if(__gcd(N,K) != 1) return "IMPOSSIBLE";     
    if(K == 1) {
        if(N+1 > MAX) return "IMPOSSIBLE";
        return to_string(N+1);
    }
    if(N == 1) return "1";

    int ret = EGCD(N,K,X,Y);
    if(Y < 0) Y = (Y+N)%N;
    if(Y > MAX) return "IMPOSSIBLE";
    return to_string(Y);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) cout << solve() << "\n";
}