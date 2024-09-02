#include <bits/stdc++.h>

using namespace std;

vector<int> V;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    
    V.resize(N);
    for(int i=0; i<N; i++) cin >> V[i];
    sort(V.begin(),V.end());

    int ans = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0; i<N; i++) {
        if(pq.empty() || pq.top() > V[i]) {
            ans++;
            for(int j=0; j<=1000; j++) pq.push(j);
        }
        pq.pop();
    }
    cout << ans;
}