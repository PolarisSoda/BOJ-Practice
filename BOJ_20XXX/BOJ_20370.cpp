#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

vector<pll> V;

bool compare(pll a,pll b) {
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

//10-> 남은것들 중 B 최대들.
//k를 가져간다면? 6 -> (어떤값) + AK, 10 -> (어떤값) - BK + (어떤값 - 어차피 정해진게 들어온다)
//바꿀 수 있는 차이는 AK + BK
//반드시 가져갈거라면 저게 큰거로 가져가는게 이득이다. 
ll DF[80001]; //기본적으로 B가 가져간것에대해 A가 i개를 뺏어왔을 때 차이. A - B로 정의됨.

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K;
    cin >> N >> K;

    V.resize(N);
    for(int i=0; i<N; i++) cin >> V[i].first;
    for(int i=0; i<N; i++) cin >> V[i].second;
    sort(V.begin(),V.end(),compare);

    ll b_side = 0;
    priority_queue<ll> pq;
    for(int i=0; i<K; i++) {
        b_side -= V[i].second;
        pq.push(V[i].first+V[i].second);
    }
    DF[0] = b_side;

    for(int i=0; i<K; i++) {
        ll now = pq.top();
        pq.pop();
        DF[i+1] = DF[i] + now - V[K+i].second;
        pq.push(V[K+i].first+V[K+i].second);
    }

    pq = priority_queue<ll>();
    for(int i=K*2; i<N; i++) pq.push(V[i].first);

    ll ans = DF[K], a_side = 0;
    for(int i=K-1; i>=0; i--) {
        pq.push(V[K+i].first);
        a_side += pq.top();
        pq.pop();
        ans = max(ans,DF[i]+a_side);
    }
    cout << ans;
    exit(0);
}