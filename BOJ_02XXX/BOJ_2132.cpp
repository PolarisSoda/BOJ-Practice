#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 10001;
int arr[LEN],w[LEN];
vector<int> edge[LEN];

void DFS(int num,int prev) {
    w[num] += arr[num];
    for(int next : edge[num]) {
        if(next == prev) continue;
        w[next] += w[num];
        DFS(next,num);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int V;
    cin >> V;
    
    for(int i=1; i<=V; i++) cin >> arr[i];
    for(int i=0; i<V-1; i++) {
        int A,B;
        cin >> A >> B;
        edge[A].push_back(B);
        edge[B].push_back(A);
    }

    DFS(1,1);
    int idx = 1,idx2 = 1,maxv = 0;
    for(int i=2; i<=V; i++) if(maxv < w[i]) idx = i, maxv = w[i];

    memset(w,0,sizeof(w));
    DFS(idx,idx);
    maxv = 0;
    for(int i=1; i<=V; i++) if(maxv < w[i]) idx2 = i, maxv = w[i];
    cout << maxv << " " << min(idx,idx2);
}
