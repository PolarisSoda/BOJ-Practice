#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr ll DIV = 1000000007;
constexpr int LEN = 100001;
ll A[LEN],C[LEN],D[LEN],T[LEN<<1];

void Kitamasa(int N,ll M) {
    //A_N을 구함.
    //M은 대충 얼마나 딸려있는지?
    //A는 수열
    //C는 곱해질 수열.
    //D는 초기 수열들을 이용해서 구할 때의 수열.
    if(N == 1) {
        D[1] = 1;
        for(int i=2; i<=M; i++) D[i] = 0;
        return;
    }
    if(N&1) {
        //N이 홀수라면.
        Kitamasa(N^1,M);
        int j = D[M];
        for(int i=M; i>=1; i--) D[i] = (D[i-1] + C[M-i+1]*j)%DIV;
    } else {
        //N이 짝수라면.
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
    
    ll N;
    cin >> N;
    
    Kitamasa(N,2);
    ll ans = 0;
    for(int i=1; i<=2; i++) {
        ans = (ans + A[i]*D[i])%DIV;
    }
    cout << ans;
}
