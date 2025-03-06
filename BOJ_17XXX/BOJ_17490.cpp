#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
struct info {
    ll s,e,x;
};

constexpr int LEN = 1000001;
ll S[LEN],pt[LEN];
vector<info> edge;
bool construct[LEN];

bool compare(const info &a, const info &b) {
    return a.x < b.x;
}

int root(int num) {
    if(num == pt[num]) return num;
    return pt[num] = root(pt[num]);
}

void uni(int a,int b) {
    a = root(a), b = root(b);
    if(a != b) pt[b] = a;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll N,M,K;
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++) cin >> S[i];

    if(M <= 1) cout << "YES", exit(0);

    for(int i=0; i<M; i++) {
        ll A,B;
        cin >> A >> B;
        if(A > B) swap(A,B);
        if(A == 1 && B == N) A = N, B = 1;
        construct[A] = true;
    }
    for(int i=1; i<=N; i++) if(construct[i] == false) edge.push_back({i,i+1 > N ? 1 : i+1,0});

    for(int i=0; i<=N; i++) pt[i] = i;
    for(int i=1; i<=N; i++) edge.push_back({0,i,S[i]});
    sort(edge.begin(),edge.end(),compare);

    ll ret = 0, ecnt = 0;
    for(auto now : edge) {
        if(root(now.s) == root(now.e)) continue;
        uni(now.s,now.e);
        ret += now.x;
        if(++ecnt == N) break;
    }
    
    cout << (ret > K ? "NO" : "YES");
    exit(0);
}