#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int LEN = 10001;
vector<int> edge[LEN];
int idx[LEN],itn[LEN<<1],arr[LEN<<1],cur;

void Preorder(int num) {
    idx[num] = cur;
    itn[cur] = num;
    arr[cur] = idx[num];
    cur++;
    for(int next : edge[num]) {
        Preorder(next);
        arr[cur] = idx[num];
        cur++;
    }
}
int CNT(int num) {
    int ret = 1;
    for(int next : edge[num]) ret += CNT(next);
    return ret;
}
void solve() {
    for(int i=0; i<LEN; i++) edge[i] = vector<int>();
    cur = 0;

    int V,E,A,B;
    cin >> V >> E >> A >> B;
    for(int i=0; i<E; i++) {
        int C,D;
        cin >> C >> D;
        edge[C].push_back(D);
    }

    Preorder(1);
    A = idx[A];
    B = idx[B];
    if(A > B) swap(A,B);
    int ans = 0x7FFFFFFF;
    for(int i=A; i<=B; i++) ans = min(ans,arr[i]);
    cout << itn[ans] << " " << CNT(itn[ans]) << "\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " ", solve();
}