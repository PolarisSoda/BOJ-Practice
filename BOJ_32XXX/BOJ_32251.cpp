#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 100001;
vector<int> edge[LEN];
ll apple[LEN];
ll pred[LEN],succ[LEN];

void DFS_init(int now,int prev) {
    succ[now] = prev;
    for(int next : edge[now]) {
        if(next == prev) continue;
        DFS_init(next,now);
        pred[now]++;
    }
}

void DFS(int now,int prev,ll amount) {
    ll take = min(amount,apple[now]);
    apple[now] += take, amount -= take;

    if(pred[now] != 0 && amount/pred[now] != 0) {
        ll new_amount = amount/pred[now];
        for(int next : edge[now]) {
            if(next == prev) continue;
            DFS(next,now,new_amount);
        }
    }
} 

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,Q;
    cin >> N >> Q;

    for(int i=0; i<N-1; i++) {
        int A,B;
        cin >> A >> B;
        edge[A].push_back(B);
        edge[B].push_back(A);
    }

    for(int i=1; i<=N; i++) cin >> apple[i];
    DFS_init(1,0);
    
    for(int i=0; i<Q; i++) {
        ll T,U,X;
        cin >> T;
        if(T == 1) {
            cin >> U >> X;
            DFS(U,succ[U],X);
        } else {
            cin >> U;
            cout << apple[U] << "\n";
        }
    }
    exit(0);
}