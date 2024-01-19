#include <bits/stdc++.h>

using namespace std;

vector<int> cow,hrs;

void solve() {
    int N,M,C1,C2;
    cin >> N >> M >> C1 >> C2;
    cow = vector<int>(N);
    hrs = vector<int>(M);
    
    for(int i=0; i<N; i++) cin >> cow[i];
    for(int i=0; i<M; i++) cin >> hrs[i];
    if(N > M) swap(cow,hrs);
    
    sort(hrs.begin(),hrs.end());
    int bias = abs(C1-C2);
    int minv = 0x7FFFFFFF, cnt = 0;
    for(int now : cow) {
        int near = upper_bound(hrs.begin(),hrs.end(),now) - hrs.begin();
        if(near != M) {
            int val = abs(now - hrs[near]);
            if(minv > val) minv = val, cnt = 1;
            else if(minv == val) cnt++;
        }
        if(near != 0) {
            int val = abs(now - hrs[near-1]);
            if(minv > val) minv = val, cnt = 1;
            else if(minv == val) cnt++;
        }
    }
    cout << minv + bias << " " << cnt << "\n";
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " ", solve();
    return 0;
}