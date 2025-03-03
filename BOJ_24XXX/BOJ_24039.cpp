#include <bits/stdc++.h>

using namespace std;

vector<int> V;
bool visited[10001];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    for(int i=2; i<=10000; i++) {
        if(visited[i]) continue;
        V.push_back(i);
        for(int j=i+i; j<=10000; j+=i) visited[j] = true;
    }
    
    int sz = V.size();
    int ret = INT_MAX;
    for(int i=0; i<sz-1; i++) {
        int now = V[i]*V[i+1];
        if(now <= N) continue;
        ret = min(ret,now);
    }
    cout << ret;
}