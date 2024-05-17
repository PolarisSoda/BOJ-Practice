#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 500001;
int A[LEN],B[LEN],idx[LEN<<1];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i], B[i] = A[i];
    sort(B+1,B+N+1);

    int ans = 0;
    for(int i=1; i<=N; i++) idx[B[i]] = i;
    for(int i=1; i<=N; i++) ans = max(ans,i-idx[A[i]]);
    cout << ans+1;
}
