#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pil;

constexpr int LEN = 100001;
pil pt[LEN];

pil root(int num) {
    if(pt[num].first == num) return pt[num];
    pil ret = root(pt[num].first);
    ret.second += pt[num].second;
    return pt[num] = ret;
}

void solve() {
    int N,M;
    cin >> N >> M;
    if(N+M == 0) exit(0);

    for(int i=1; i<=N; i++) pt[i] = {i,0};
    for(int i=0; i<M; i++) {
        char C;
        int A,B,W;
        cin >> C >> A >> B;
        pil RA = root(A);
        pil RB = root(B);
        if(C == '!') {
            cin >> W;
            ll diff = RA.second - RB.second + W;
            if(diff >= 0) pt[RB.first] = {RA.first,diff};
            else pt[RA.first] = {RB.first,(-1)*diff};
        } else {
            if(RA.first != RB.first) cout << "UNKNOWN\n";
            else cout << RB.second - RA.second << "\n";
        }
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    while(true) solve();
}