#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 100001;
vector<int> edge[LEN];
int indicator[LEN];
bool visited[LEN];

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
    
}