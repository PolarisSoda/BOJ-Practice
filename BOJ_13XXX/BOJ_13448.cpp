#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct info {
    ll M,P,R;
};

constexpr int LEN = 61;
info qst[LEN];
ll DP[LEN][100001];
int N,T;

bool compare(info a,info b) {
    return a.R*b.P < b.R*a.P;
}

ll Dynamic(int idx,int time) {
    if(DP[idx][time] != -1) return DP[idx][time];
    if(idx == N+1) return 0;
    ll n_solve = Dynamic(idx+1,time);
    ll y_solve = 0;
    if(time + qst[idx].R <= T) y_solve = Dynamic(idx+1,time+qst[idx].R) + qst[idx].M-(qst[idx].R+(ll)time)*qst[idx].P;
    return DP[idx][time] = max({DP[idx][time],n_solve,y_solve});
} 

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> T;

    for(int i=1; i<=N; i++) cin >> qst[i].M;
    for(int i=1; i<=N; i++) cin >> qst[i].P;
    for(int i=1; i<=N; i++) cin >> qst[i].R;
    sort(qst+1,qst+N+1,compare);
    memset(DP,-1,sizeof(DP));

    cout << Dynamic(1,0);
    exit(0);
}