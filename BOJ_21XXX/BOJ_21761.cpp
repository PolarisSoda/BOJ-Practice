#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

vector<ll> card[4];
int c_idx[4];
ll num[4];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K;
    cin >> N >> K;
    for(int i=0; i<4; i++) cin >> num[i];
    for(int i=0; i<N; i++) {
        char T;
        ll U;
        cin >> T >> U;
        int idx = T - 'A';
        card[idx].push_back(U);
    }
    for(int i=0; i<4; i++) sort(card[i].rbegin(),card[i].rend());

    for(int i=0; i<K; i++) {
        int idx = 0;
        double max_rad = 0;
        for(int j=0; j<4; j++) {
            if(c_idx[j] == card[j].size()) continue;
            double rad = (double)card[j][c_idx[j]]/(double)num[j];
            if(max_rad < rad) idx = j, max_rad = rad;
        }
        cout << (char)(idx+'A') << " " << card[idx][c_idx[idx]] << "\n";
        num[idx] += card[idx][c_idx[idx]];
        c_idx[idx]++;
    }
    exit(0);
}