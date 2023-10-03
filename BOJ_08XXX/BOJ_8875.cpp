#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector<int> AR,BR;
vector<pii> toy;
int A,B,T;

bool check(int num) {
    priority_queue<int> pq;
    //각 로봇이 들 수 있는 것중에서 반대 value가 최대인 것들은 어떻게 꺼내냐.
    int cur = 0;
    for(int i=0; i<A; i++) {
        for(cur; cur<T; cur++) {
            if(toy[cur].first >= AR[i]) break;
            pq.push(toy[cur].second);
        }
        for(int j=0; j<num; j++) {
            if(pq.empty()) break;
            pq.pop();
        }
    }
    for(cur; cur<T; cur++) pq.push(toy[cur].second);
    for(int i=0; i<B; i++) {
        for(int j=0; j<num; j++) {
            if(pq.empty()) return true;
            int now = pq.top();
            if(now >= BR[i]) return false;
            pq.pop();
        }
    }
    return pq.empty();
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> A >> B >> T;
    for(int i=0; i<A; i++) {
        int temp;
        cin >> temp;
        AR.push_back(temp);
    }
    for(int i=0; i<B; i++) {
        int temp;
        cin >> temp;
        BR.push_back(temp);
    }
    for(int i=0; i<T; i++) {
        int W,S;
        cin >> W >> S;
        toy.push_back({W,S});
    }
    sort(AR.begin(),AR.end());
    sort(BR.rbegin(),BR.rend());
    sort(toy.begin(),toy.end());

    ll left = 0;
    ll right = T+1;
    ll ans = -1;
    while(left+1<right) {
        ll mid = (left+right)/2;
        if(check(mid)) {
            right = mid;
            ans = mid;
        } else {
            left = mid;
        }
    }
    cout << ans;
    return 0;
}