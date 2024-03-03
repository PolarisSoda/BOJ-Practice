#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 500001;
vector<int> ST;
int DP[LEN], CF[LEN];
int M_MAX[LEN]; //MOD 값에 따른 최대값.
int len;

void Init() {
    for(int i=len-1; i>0; i--) {
        ST[i] = max(ST[i<<1],ST[i<<1|1]);
    }
}
int Query(int left,int right) {
    int ans = 0;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1) {
        if(left&1)
            ans = max(ans,ST[left++]);
        if(right&1)
            ans = max(ans,ST[--right]);
    }
    return ans;
}
void Update(int lo,int value) {
    for(ST[lo+=len] = value; lo>1; lo>>=1) {
        ST[lo>>1] = max(ST[lo],ST[lo^1]);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K,D;
    cin >> N >> K >> D;
    for(int i=0; i<N; i++) cin >> CF[i];
    len = 1000000, ST = vector<int>(len<<1|1,0);

    int ans = DP[0] = 1;

    for(int i=0; i<N; i++) {
        int &M = M_MAX[CF[i]%K];
        int R = Query(max(0,CF[i]-D),CF[i]+D+1);
        DP[i] = max({1,M+1,R+1});
        M = max(M,DP[i]);
        if(ST[len+CF[i]] < DP[i]) Update(CF[i],DP[i]);
        ans = max(ans,DP[i]);
    }
    cout << ans;
    exit(0);
}