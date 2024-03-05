#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 21;
ll A[LEN],B[LEN],CO[LEN][LEN];

ll C(int N,int K) {
    if(K == 0 || K == N) return 1;
    if(K == 1) return N;
    if(CO[N][K] != -1) return CO[N][K];
    return CO[N][K] = C(N-1,K) + C(N-1,K-1);
}

ll Dynamic(int num) {
    if(A[num] != -1) return A[num];
    ll ret = 0;
    for(int i=0; i<=num-1; i++)
        ret += C(num-1,i) * Dynamic(i) * Dynamic(num-1-i);
    return A[num] = ret>>1;
}

ll solve() {
    int N;
    cin >> N;
    if(N <= 1) return 1;
    return Dynamic(N)<<1;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(A,-1,sizeof(A));
    memset(B,-1,sizeof(B));
    memset(CO,-1,sizeof(CO));
    A[0] = 1, A[1] = 1;

    int T;
    cin >> T;
    while(T--) cout << solve() << "\n";
}