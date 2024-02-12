#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

constexpr int DIV = 20070713;
constexpr int LEN = 100001;
vector<pii> road;
vector<int> EOR;
ll DP[LEN];

bool compare(pii a,pii b) {
    return a.second < b.second;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    road.push_back({0,0});
    EOR.push_back(0);
    for(int i=0; i<N; i++) {
        int S,E;
        cin >> S >> E;
        road.push_back({S,E});
        EOR.push_back(E);
    }
    sort(road.begin(),road.end(),compare);
    sort(EOR.begin(),EOR.end());

    DP[0] = 1;
    for(int i=1; i<=N; i++) {
        int idx = upper_bound(EOR.begin(),EOR.end(),road[i].first) - EOR.begin() - 1;
        DP[i] = (DP[i-1] + DP[idx])%DIV;
    }
    cout << DP[N];
    exit(0);
}