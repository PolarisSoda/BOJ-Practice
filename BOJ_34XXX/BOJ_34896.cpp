#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int N,B;
vector<pii> V;

bool compare(const pii &a, const pii &b) {
    return a.first < b.first;
}

bool check(int num) {
    int total = 0;
    int prev = -100000001;
    priority_queue<int,vector<int>,greater<int>> pq;

    for(auto &[X,C] : V) {
        if(pq.empty() || X - prev <= num) pq.push(C);
        else total += pq.top(), pq = priority_queue<int,vector<int>,greater<int>>(), pq.push(C);
        prev = X;
    }
    if(!pq.empty()) total += pq.top();
    
    return total <= B;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    V.resize(N);
    for(int i=0; i<N; i++) cin >> V[i].first;
    for(int i=0; i<N; i++) cin >> V[i].second;
    cin >> B;

    sort(V.begin(),V.end(),compare);

    int left = 0, right = 200000001, ans = right;
    while(left+1<right) {
        int mid = (left+right) >> 1;
        if(check(mid)) right = ans = mid;
        else left = mid;
    }
    cout << ans;
    exit(0);
}