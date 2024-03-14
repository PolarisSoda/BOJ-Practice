#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
struct compare {
    bool operator()(pii a,pii b) {
        return a.first < b.first;
    }
};

vector<pii> lux;
priority_queue<pii,vector<pii>,compare> pq;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K;
    cin >> N >> K;
    
    lux.push_back({-1,-1});
    for(int i=1; i<=N; i++) {
        int temp;
        cin >> temp;
        lux.push_back({temp,i});
    }
    lux.push_back({-1,-1});
    for(int i=1; i<K+K; i++) pq.push(lux[i]);
    int left = 1, right = 2*K-1;
    while(right <= N) {
        while(pq.top().second < left || pq.top().second > right) pq.pop();
        cout << pq.top().first << " ";
        pq.push(lux[++right]);
        left++;
    }
}