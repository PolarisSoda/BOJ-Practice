#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct info {
    ll s,e,x;
};

constexpr int LEN = 2001;
vector<info> edge;
int pt[LEN];

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
    if(a > b) swap(a,b);
    if(a != b) pt[b] = a;
}

void solve() {
    int N,M;
    cin >> N >> M;

    edge.clear();
    for(int i=0; i<=2000; i++) pt[i] = i;
    
    for(int i=1; i<N; i++) {
        ll A,B;
        cin >> A >> B;
        edge.push_back({i,A,B});
    }
    
    ll ans = 0;
    for(int i=0; i<M; i++) {
        ll A,B,C;
        cin >> A >> B >> C;
        edge.push_back({A,B,C});

        for(int i=0; i<=2000; i++) pt[i] = i;
        sort(edge.begin(),edge.end(),compare);

        ll sum = 0, ecnt = 0;
        for(info now : edge) {
            if(root(now.s) != root(now.e)) {
                uni(now.s,now.e);
                sum += now.x;
                if(++ecnt == N-1) break;
            }
        }
        ans ^= sum;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--) solve();
    exit(0);
}