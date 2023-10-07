#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 1001;
struct info {
    int s,e,x;
};

vector<info> edge;
int pt[LEN];

bool compare(info a,info b) {
    return a.x > b.x;
}

int root(int a) {
    if(pt[a] == a)
        return a;
    return pt[a] = root(pt[a]);
}

void uni(int a,int b) {
    a = root(a);
    b = root(b);
    if(a != b) pt[b] = a;
}

void solve(int N,int M,int K) {
    edge = vector<info>();
    for(int i=0; i<M; i++) {
        char C;
        int A,B;
        cin >> C >> A >> B;
        if(C == 'R') edge.push_back({A,B,0});
        else edge.push_back({A,B,1});
    }
    sort(edge.begin(),edge.end(),compare);
    for(int i=1; i<LEN; i++) pt[i] = i;

    int minv = 0, maxv = 0, ecnt = 0;
    for(int i=0; i<M; i++) {
        info now = edge[i];
        if(root(now.s) != root(now.e)) {
            uni(now.s,now.e);
            minv += now.x;
            if(++ecnt == N-1) break;
        }
    }

    ecnt = 0;
    for(int i=1; i<LEN; i++) pt[i] = i;
    for(int i=M-1; i>=0; i--) {
        info now = edge[i];
        if(root(now.s) != root(now.e)) {
            uni(now.s,now.e);
            maxv += now.x;
            if(++ecnt == N-1) break;
        }
    }
    if(K >= maxv && K <= minv) cout << "1\n";
    else cout << "0\n";
}


int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(true) {
        int N,M,K;
        cin >> N >> M >> K;
        if(N+M+K == 0) break;
        solve(N,M,K);
    }
}