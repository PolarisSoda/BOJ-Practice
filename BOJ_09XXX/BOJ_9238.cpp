#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef pair<ld,int> pdi;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ld T;
    int N;
    cin >> T >> N;

    ld minv = 1000001;
    priority_queue<pdi> pq;
    for(int i=0; i<N; i++) {
        ld temp;
        cin >> temp;
        pq.push({temp,1});
        minv = min(minv,temp);
    }

    ld ratio = minv/pq.top().first;
    int ans;
    for(ans=0; ans<500; ans++) {
        if(ratio > T) break;
        ld big = pq.top().first;
        int rd = pq.top().second;
        pq.pop();
        big = big*rd/(rd+1);
        minv = min(minv,big);
        pq.push({big,rd+1});
        ratio = max(ratio,minv/pq.top().first);
    }
    cout << ans;
    exit(0);
}