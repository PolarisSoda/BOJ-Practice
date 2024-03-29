#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 1001;
constexpr int DIV = 1'000'000'007;
ll DP[LEN][10][10][11];
int N,K;

ll Dynamic(int digit,int group,int now,int diff) {
    if(digit == N) return group == K ? 1 : 0;
    if(DP[digit][group][now][diff] != -1) return DP[digit][group][now][diff];
    ll ret = 0;
    if(diff == 10) {
        for(int i=now; i<=9; i++) ret = (ret + Dynamic(digit+1,group,i,i-now))%DIV;
    } else {
        if(now+diff <=9) ret = (ret + Dynamic(digit+1,group,now+diff,diff))%DIV;
        for(int i=now; i<=9; i++)
            if(i != now+diff) ret = (ret + Dynamic(digit+1,group+1,i,10))%DIV;
    }
    return DP[digit][group][now][diff] = ret;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    if(K > 9) cout << 0,exit(0);
    
    ll ans = 0;
    memset(DP,-1,sizeof(DP));
    for(int i=1; i<=9; i++) ans = (ans + Dynamic(1,1,i,10))%DIV;
    cout << ans;
    exit(0);
}