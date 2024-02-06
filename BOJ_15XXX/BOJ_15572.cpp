#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll DIV = 1999;
constexpr int LEN = 100001;
ll A[LEN],C[LEN],D[LEN],T[LEN<<1];

void Kitamasa(ll N,int M) {
    if(N == 1) {
        D[1] = 1;
        for(int i=2; i<=M; i++) D[i] = 0;
        return;
    }
    if(N&1) {
        Kitamasa(N^1,M);
        int j = D[M];
        for(int i=M; i>=1; i--) D[i] = (D[i-1] + C[M-i+1]*j)%DIV;
    } else {
        Kitamasa(N>>1,M);
        for(int i=1; i<=M+M; i++) T[i] = 0;
        for(int i=1; i<=M; i++) for(int j=1; j<=M; j++) T[i+j] = (T[i+j] + D[i]*D[j])%DIV;
        for(int i=M+M; i>M; i--) for(int j=1; j<=M; j++) T[i-j] = (T[i-j] + C[j]*T[i])%DIV;
        for(int i=1; i<=M; i++) D[i] = T[i];
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    ll N,M;
    cin >> N >> M;
    if(N == 1) cout << 1,exit(0);

    A[1] = 1;
    C[1] = 1;
    for(int i=2; i<N; i++) {
        A[i] = (A[i-1]*2)%DIV;
        C[i] = 1;
    }
    A[N] = ((A[N-1]*4)%DIV-1)%DIV;
    C[N] = (A[N-1]*2)%DIV;


    Kitamasa(M,N);
    ll ans = 0;
    for(int i=1; i<=N; i++) ans = (ans + A[i]*D[i])%DIV;
    cout << ans;
}
