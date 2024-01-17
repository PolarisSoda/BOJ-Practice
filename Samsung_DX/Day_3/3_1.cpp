#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 101;
int parent[LEN];
bool visited[LEN];

int root(int num) {
    if(num == parent[num]) return num;
    return parent[num] = root(parent[num]);
}

void uni(int a,int b) {
    a = root(a);
    b = root(b);
    if(a != b) parent[b] = a;
}

void solve() {
    int N,M;
    cin >> N >> M;

    memset(visited,false,sizeof(visited));
    for(int i=1; i<=N; i++) parent[i] = i;

    for(int i=0; i<M; i++) {
        int A,B;
        cin >> A >> B;
        uni(A,B);
    }
    int ans = 0;
    for(int i=1; i<=N; i++) {
        int r = root(i);
        if(!visited[r]) {
            visited[r] = true;
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " ", solve();
}