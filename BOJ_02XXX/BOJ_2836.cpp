#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector<pair<int,int>> taxi;

bool compare(pii a,pii b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int A,B;
        cin >> A >> B;
        if(A > B) taxi.push_back({A,B});
    }
    sort(taxi.begin(),taxi.end(),compare);
    if(taxi.size() == 0) cout << M,exit(0);
    ll cnt = 0;
    ll start = taxi[0].second;
    ll end = taxi[0].first;
    for(int i=1; i<taxi.size(); i++) {
        ll st = taxi[i].second;
        ll ed = taxi[i].first;
        if(st <= end) {
            end = max(ed,end);
        } else {
            cnt += end-start;
            start = st;
            end = ed;
        }
    }
    cnt += end-start;
    cout << (ll)M + cnt*2;
    return 0;
}