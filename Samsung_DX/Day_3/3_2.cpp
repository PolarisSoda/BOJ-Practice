#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
struct info {
    ll s,e,x;
};

constexpr int LEN = 1001;
pll isl[LEN];
int pt[LEN];
vector<info> edge;

bool compare(info a,info b) {
    return a.x < b.x;
}

int root(int num) {
    if(pt[num] == num) return num;
    return pt[num] = root(pt[num]);
}

void uni(int a,int b) {
    a = root(a);
    b = root(b);
    if(a != b) pt[b] = a;
}

void solve() {
    int N;
    cin >> N;

    edge = vector<info>();
    for(int i=1; i<=N; i++) pt[i] = i;

    for(int i=1; i<=N; i++) cin >> isl[i].first;
    for(int i=1; i<=N; i++) cin >> isl[i].second;
    
    for(int i=1; i<N; i++) {
        for(int j=i; j<=N; j++) {
            ll dx = (isl[i].first - isl[j].first) * (isl[i].first - isl[j].first);
            ll dy = (isl[i].second- isl[j].second) * (isl[i].second - isl[j].second);
            edge.push_back({i,j,dx+dy});
        }
    }

    ld E;
    cin >> E;
    sort(edge.begin(),edge.end(),compare);
    int sz = edge.size();
    ll ret = 0;
    int ecnt = 0;
    for(int i=0; i<sz; i++) {
        info now = edge[i];
        if(root(now.s) != root(now.e)) {
            uni(now.s,now.e);
            ret += now.x;
            if(++ecnt == N-1) break;
        }
    }
    ld ans = (ld)ret*E + 0.5;
    cout << (ll)ans << "\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " ", solve();
}