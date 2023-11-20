#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 10001;
int in[LEN],t[LEN],tt[LEN];
vector<int> edge[LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for(int i=1; i<=N; i++) {
        int cnt;
        cin >> t[i] >> cnt;
        for(int j=1; j<=cnt; j++) {
            int temp;
            cin >> temp;
            edge[temp].push_back(i);
        }
        in[i] += cnt;
    }

    queue<int> task;
    for(int i=1; i<=N; i++) if(in[i] == 0) task.push(i);

    while(!task.empty()) {
        int now = task.front();
        task.pop();

        tt[now] += t[now];
        int sz = edge[now].size();
        for(int i=0; i<sz; i++) {
            int next = edge[now][i];
            tt[next] = max(tt[next],tt[now]);
            if(--in[next] == 0) task.push(next);
        }
    }

    int ans = 0;
    for(int i=1; i<=N; i++) ans = max(ans,tt[i]);
    cout << ans;

    return 0;
}