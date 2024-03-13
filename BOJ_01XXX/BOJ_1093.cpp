#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

vector<int> P,V;
vector<pll> L,R; //{가격,가치};
ll K,sum;
int N,C;

bool compare(pll a,pll b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    V.resize(N), P.resize(N);
    for(int i=0; i<N; i++) cin >> P[i];
    for(int i=0; i<N; i++) cin >> V[i];
    cin >> K >> C;
    for(int i=0; i<C; i++) {
        int temp;
        cin >> temp;
        sum += P[temp];
    }

    int left = N/2, right = N - left;
    L.resize(1<<left), R.resize(1<<right);
    for(int i=0; i<(1<<left); i++) {
        pll ret = {0,0};
        for(int j=0; j<left; j++)
            if((i>>j)&1) ret.first += P[j], ret.second += V[j];
        L[i] = ret;
    }
    for(int i=0; i<(1<<right); i++) {
        pll ret = {0,0};
        for(int j=0; j<right; j++)
            if((i>>j)&1) ret.first += P[left+j], ret.second += V[left+j];
        R[i] = ret;
    }

    sort(R.begin(),R.end(),compare);
    for(int i=(1<<right)-2; i>=0; i--)
        R[i].first = min(R[i].first,R[i+1].first);

    ll ret = 0x7FFFFFFF;
    for(auto tt : L) {
        ll price = tt.first, val = tt.second;
        auto it = lower_bound(R.begin(),R.end(),make_pair(0,K-val),compare);
        if(it != R.end()) ret = min(ret,price + it->first);
    }
    if(ret == 0x7FFFFFFF) cout << -1;
    else cout << max(ret-sum,0LL);
}