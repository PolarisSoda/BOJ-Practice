#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int indgree[32001] = {};
vector<int> edge[32001];

int main() {
    int N,M;
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int left,right;
        cin >> left >> right;
        edge[left].push_back(right);
        indgree[right]++;
    }
    
    priority_queue<int,vector<int>,greater<int>> task;
    
    for(int i=1; i<=N; i++) {
        if(indgree[i] == 0) {
            task.push(i);
        }
    }
    while(!task.empty()) {
        int now = task.top();
        task.pop();
        for(int i=0; i<edge[now].size(); i++) {
            int next = edge[now][i];
            indgree[next]--;
            if(indgree[next] == 0) {
                task.push(next);
            }
        }
        cout << now << " ";
    }
}