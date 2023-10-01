#include <bits/stdc++.h>

using namespace std;

struct info {
    int l,x,r;
};
struct compare {
    bool operator() (info A,info B) {
        return A.x < B.x;
    }
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K;
    cin >> N >> K;

    priority_queue<info,vector<info>,compare> pq;
    for(int i=1; i<=N; i++) {
        int temp;
        cin >> temp;
        int left = i==1 ? N : i-1;
        int right = i==N ? 1 : i+1;
        pq.push({left,temp,right});
    }
    int ans = 0;
    for(int i=0; i<K; i++) {
        info now = pq.top();
        pq.pop();
        ans += now.x;
        
    }
    cout << ans;
}