#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

struct compare {
    bool operator() (pii a,pii b) {
        return a.second > b.second;
    }
};
int arr[10];

int solve() {
    int N,K;
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    cin >> K;

    priority_queue<pii,vector<pii>,compare> pq;
    pq.push({K,0});    
    while(!pq.empty()) {
        int num = pq.top().first;
        int val = pq.top().second;
        pq.pop();

        if(num == 0) return val;
        pq.push({0,val+num});
        for(int i=0; i<N; i++) pq.push({num/arr[i],val+num%arr[i]});
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " " << solve() << "\n";
    return 0;
}