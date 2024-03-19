#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

constexpr int LEN = 10011;
vector<int> edge[LEN];
int indicator[LEN];
bool visited[LEN];
bool lesson[101],already[101];
vector<pii> order;
int n_idx = 1;

bool DFS(int num) {
    for(int next : edge[num]) {
        if(visited[next]) continue;
        visited[next] = true;
        if(!indicator[next] || DFS(indicator[next])) {
            indicator[next] = num;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        order.push_back({0,temp});
        lesson[temp] = already[temp] = true;
    }

    cin >> M;
    for(int i=0; i<M; i++) {
        int C,K;
        cin >> C >> K;
        //i번째 졸업 요건은 K개 중에서 C개를 만족해야 한다.
        for(int i=0; i<K; i++) {
            int temp;
            cin >> temp;
            if(lesson[temp] == false) lesson[temp] = true, order.push_back({1,temp});
            for(int i=0; i<C; i++) edge[temp].push_back(n_idx+i);
        }
        n_idx += C;
    }
    n_idx--; 
    sort(order.begin(),order.end());

    int ret = 0;
    for(auto &[t,num] : order) {
        memset(visited,false,sizeof(visited));
        if(DFS(num)) ret++;
    }
    if(ret != n_idx) cout << -1, exit(0);
    
    vector<int> ans;
    for(int i=1; i<=n_idx; i++) if(!already[indicator[i]]) ans.push_back(indicator[i]);
    sort(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for(int num : ans) cout << num << " ";
}