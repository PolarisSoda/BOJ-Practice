#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<ld,int> pdi;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K;
    cin >> N;

    ld minv = 1000000000;

    priority_queue<pdi> pq;
    for(int i=0; i<N; i++) {
        ld temp;
        cin >> temp;
        pq.push({temp,1});
        minv = min(minv,temp);
    }
    cin >> K;

    ld ans = pq.top().first - minv;
    for(int i=0; i<K; i++) {
        pdi now = pq.top();
        pq.pop();
        ld big = now.first;
        int rd = now.second;
        big = big*rd/(rd+1);
        minv = min(minv,big);
        pq.push({big,rd+1});
        ans = min(ans,pq.top().first - minv);
    }
    cout << fixed;
    cout.precision(9);
    cout << ans;
    return 0;
}