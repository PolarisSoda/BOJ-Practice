#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pii;

constexpr int LEN = 20001;
pii pt[LEN];

pii root(int num) {
    if(num == pt[num].first) return pt[num];
    pii ret = root(pt[num].first);
    return pt[num] = {ret.first,ret.second+pt[num].second};
}

void uni(int a,int b,int d) {
    pii pb = root(b);
    if(a != pb.first) pt[a] = {pb.first,d+pb.second};
}

void solve() {
    int N;
    cin >> N;

    for(int i=1; i<=N; i++) pt[i] = {i,0};

    while(true) {
        int I,J;
        char command;

        cin >> command;
        if(command == 'E') {
            cin >> I;
            cout << root(I).second << "\n";    
        } else if(command == 'I') {
            cin >> I >> J;
            int D = abs(I-J)%1000;
            uni(I,J,D);
        } else break;
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) solve();
    exit(0);
}