#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

constexpr int LEN = 200001;
pii RCP[LEN];
vector<int> IDX[LEN];
bool visited[LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,Y;
    cin >> N >> M;
    for(int i=1; i<=M; i++) {
        int K,R;
        cin >> K;
        for(int j=0; j<K; j++) {
            int temp;
            cin >> temp;
            IDX[temp].push_back(i);
        }
        cin >> R;
        RCP[i] = {K,R};
    }
    cin >> Y;
    queue<int> task;
    for(int i=0; i<Y; i++) {
        int temp;
        cin >> temp;
        task.push(temp);
    }
    vector<int> ans;
    while(!task.empty()) {
        int now = task.front();
        task.pop();

        if(visited[now]) continue;
        visited[now] = true;
        ans.push_back(now);

        for(int idx : IDX[now]) {
            if(--RCP[idx].first <= 0) task.push(RCP[idx].second);
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for(int num : ans) cout << num << " ";
}