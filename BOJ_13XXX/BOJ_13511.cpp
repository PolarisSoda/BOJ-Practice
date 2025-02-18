#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pil;

constexpr int LEN = 100001;
vector<pil> edge[LEN];
int H[LEN];
int DP[LEN][32]; //i번째 노드의 2^j번째 조상
ll D[LEN][32]; //i번째 노드와 2^j번째 조상까지의 길이.

void DFS(int now,int prev,int height) {
    H[now] = height;

    for(int i=1; (1<<i)<=height; i++) {
        int mid = DP[now][i-1];
        DP[now][i] = DP[mid][i-1];
        D[now][i] = D[now][i-1] + D[mid][i-1];
    }

    for(auto tt : edge[now]) {
        int next = tt.first, dist = tt.second;
        if(next == prev) continue;
        DP[next][0] = now, D[next][0] = dist;
        DFS(next,now,height+1);
    }
}

pil LCA(int A,int B) {
	if(H[A] > H[B]) swap(A,B);

	ll dist = 0;

	for(int i=17; i>=0; i--) {
        if(H[B]-H[A] >= (1<<i)) dist += D[B][i], B = DP[B][i];
    }

    if(A == B) return {A,dist};
    for(int i=17; i>=0; i--) {
        if(DP[A][i] == DP[B][i]) continue;
        else dist += D[A][i] + D[B][i], A = DP[A][i], B = DP[B][i];
    }
	return {DP[A][0],dist + D[A][0] + D[B][0]};
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;

    cin >> N;
    
    for(int i=0; i<N-1; i++) {
        int U,V,W;
        cin >> U >> V >> W;
        edge[U].push_back({V,W});
        edge[V].push_back({U,W});
    }
    DFS(1,-1,0);

    cin >> M;
    for(int i=0; i<M; i++) {
        int C,U,V,K;
        cin >> C;
        if(C == 1) {
            cin >> U >> V;
            cout << LCA(U,V).second << "\n";
        } else {
            cin >> U >> V >> K;
            int now, PT = LCA(U,V).first;

            if(K <= H[U] - H[PT]) K--, now = U;
            else {
                K -= H[U] - H[PT], K = H[V] - H[PT] + 1 - K;
                now = V;
            }
            for(int i=17; i>=0; i--) {
                if(K >= (1<<i)) now = DP[now][i], K -= 1<<i;
            }
            cout << now << "\n";
        }
    }
}