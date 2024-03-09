#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
struct Linear {
    ld ix;
    ll ratio, y;
};

constexpr int MAX = 100001;
ll DP[MAX],A[MAX],B[MAX];
vector<Linear> EQ;

ld getinterx(Linear a,Linear b) {
    return (ld)(a.y-b.y)/(b.ratio-a.ratio);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) cin >> B[i];
    
    for(int i=1; i<=N; i++) {
        Linear now = {0,B[i-1],DP[i-1]};
        while(EQ.size() >= 1) {
            now.ix = getinterx(now,EQ.back());
            if(now.ix < EQ.back().ix) EQ.pop_back();
            else break;
        }
        
        EQ.push_back(now);
        ll left = -1;
        ll right = EQ.size();
        ll pivot = 0;
        while(left+1<right) {
            ll mid = (left+right)/2;
            if(EQ[mid].ix < A[i]) pivot = left = mid;
            else right = mid;
        }
        DP[i] = EQ[pivot].ratio*A[i] + EQ[pivot].y;
    }
    cout << DP[N];
}
 