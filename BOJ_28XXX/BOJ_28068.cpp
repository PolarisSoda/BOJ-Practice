#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

struct compare {
    bool operator()(const pii a,const pii b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};

bool comp(const pii a,const pii b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
}
vector<pii> remain;
int main() {
    int N;
    cin >> N;

    priority_queue<pii,vector<pii>,compare> pq;
    for(int i=0; i<N; i++) {
        int A,B;
        cin >> A >> B;
        pq.push({A,B});
    }

    ll bored = 0;
    while(!pq.empty()) {
        pii now = pq.top();
        if(now.first > bored) {
            cout << 0;
            return 0;
        }
        pq.pop();
        if(now.first > now.second) {
            remain.push_back(now);
            continue;
        }
        bored -= now.first;
        bored += now.second;
    }
    sort(remain.begin(),remain.end(),comp);
    for(pii now : remain) {
        if(now.first > bored) {
            cout << 0;
            return 0;
        }
        bored -= now.first;
        bored += now.second;
    }
    cout << 1;
} 