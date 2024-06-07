#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> A,B;
int N,K;

bool check(ll num) {
    ll sum = 0;
    for(int i=0; i<N; i++) {
        int left = -1, right = N, idx = 0;
        while(left+1<right) {
            int mid = (left+right)>>1;
            if(A[i]*B[mid] <= num) {
                left = idx = mid;
            } else right = mid;
        }
        sum += idx+1;
    }
    if(sum >= K) return true;
    return false;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    A.resize(N),B.resize(N);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) cin >> B[i];
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    ll left = A[0]*B[0]-1, right = A[N-1]*B[N-1]+1, ans;
    while(left+1<right) {
        ll mid = (left+right)>>1LL;
        if(check(mid)) right = ans = mid;
        else left = mid;
    }
    cout << ans;
    exit(0);
}