#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 101;
deque<int> task[LEN];
bool plugged[LEN];
vector<int> total_task;
int pcnt;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K;
    cin >> N >> K;

    for(int i=0; i<K; i++) {
        int temp;
        cin >> temp;
        task[temp].push_back(i);
        total_task.push_back(temp);
    }

    int ans = 0;
    for(int i=0; i<K; i++) {
        int now = total_task[i];
        task[now].pop_front();

        if(plugged[now]) continue;
        
        if(pcnt < N) {
            pcnt++;
            plugged[now] = true;
        } else {
            int rm_task = -1;
            int max_wait = -1;
            for(int j=1; j<=K; j++) {
                if(!plugged[j] || j==now) continue;

                if(task[j].empty() == true) {
                    rm_task = j;
                    break;
                } else {
                    int local_wait = task[j].front() - i;
                    if(local_wait > max_wait) rm_task = j, max_wait = local_wait;
                }
            }
            plugged[rm_task] = false;
            plugged[now] = true;
            ans++;
        }
    }
    cout << ans;
    exit(0);
}