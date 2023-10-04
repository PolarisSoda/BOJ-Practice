#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll DIV = 1000000007;

struct info {
    int s,e;
    ll x;
};

vector<info> edge;
int pt[10000];

int root(int a) {
    if(pt[a] == a) return a;
    return pt[a] = root(pt[a]);
}

void uni(int a,int b) {
    a = root(a);
    b = root(b);
    if(a != b) pt[b] = a;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    ll W = 1;
    for(int i=0; i<M; i++) {
        int A,B;
        cin >> A >> B;
        edge.push_back({A,B,W});
        W = (W*3)%DIV;
    }

    for(int i=0; i<N; i++) pt[i] = i;

    ll ans = 0;
    for(int i=M-1; i>=0; i--) {
        info now = edge[i];
        if(root(now.s) == root(0) && root(now.e) == root(N-1)) ans += now.x;
        else if(root(now.s) == root(N-1) && root(now.e) == root(0)) ans += now.x;
        else uni(now.s,now.e);
        ans %= DIV;
    }
    cout << ans;
    return 0;
}