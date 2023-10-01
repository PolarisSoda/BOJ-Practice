#include <bits/stdc++.h>
#define LEN 16
#define INF 0x7FFFFFFF

using namespace std;

int arr[LEN][LEN]; // arr[i][j] -> i로 j를 고치는 가격
int DP[1<<LEN];
int N,P;
bool visited[1<<LEN];

int BC(int num) {
    int ret = 0;
    for(int i=0; i<N; i++) {
        if(num&1) ret++;
        num >>= 1;
    }
    return ret;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> arr[i][j];

    int code = 0;
    for(int i=0; i<N; i++) {
        char c;
        cin >> c;
        if(c == 'Y') code += 1<<i;
    }
    cin >> P;
    if(!BC(code) && P) {
        cout << -1;
        return 0;
    }

    queue<int> task;
    task.push(code);
    int ans = INF;
    memset(DP,-1,sizeof(DP));
    DP[code] = 0;
    while(!task.empty()) {
        int now = task.front();
        task.pop();

        if(visited[now]) continue;
        if(BC(now) >= P) {
            ans = min(ans,DP[now]);
            continue;
        }
        visited[now] = true;

        for(int i=0; i<N; i++) {
            if(now>>i&1) continue;
            int cost = 0x7FFFFFFF;
            int next = now + (1<<i); 
            for(int j=0; j<N; j++) {
                if((now>>j&1) == 0) continue;
                cost = min(cost,arr[j][i]);
            }
            if(DP[next] == -1) DP[next] = 0x7FFFFFFF;
            DP[next] = min(DP[next],DP[now] + cost);
            task.push(next);
        }
    }
    cout << ans;
    return 0;
}