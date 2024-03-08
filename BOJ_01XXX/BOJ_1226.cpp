#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<pii> item;
vector<int> DP[100001];

bool compare(pii a,pii b) {
    return a.first > b.first;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, sum = 0;
    cin >> N;
    for(int i=1; i<=N; i++) {
        int temp;
        cin >> temp;
        item.push_back({temp,i});
        sum += temp;
    }
    sort(item.begin(),item.end(),compare);
    int limit = sum/2;

    int ans = 0;
    for(auto tt : item) {
        int cnt = tt.first;
        int idx = tt.second;
        if(cnt == 0) break;
        for(int i=limit; i>=cnt; i--) {
            if(DP[i].size() != 0 && DP[i+cnt].size() == 0) {
                ans = max(ans,i+cnt);
                DP[i+cnt] = DP[i];
                DP[i+cnt].push_back(idx);
            }
        }
        if(DP[cnt].size() == 0) DP[cnt].push_back(idx);
        ans = max(ans,cnt);
    }
    cout << DP[ans].size() << "\n";
    for(int idx : DP[ans]) cout << idx << " ";
    exit(0);
}