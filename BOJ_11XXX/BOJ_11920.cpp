#include <bits/stdc++.h>

using namespace std;

int N,K;
priority_queue<int,vector<int>,greater<int>> pq;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
        if(pq.size() > K) cout << pq.top() << " ", pq.pop();
    }
    while(!pq.empty()) cout << pq.top() << " ", pq.pop();
    exit(0);
}