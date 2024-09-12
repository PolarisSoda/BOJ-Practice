#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
struct compare {
    bool operator() (pii a,pii b) {
        return a.first > b.first;
    }
};

constexpr int LEN = 100003;
int EVP[LEN];
int PFX[LEN];

priority_queue<pii,vector<pii>,compare> pq;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,Q;
    cin >> N >> M >> Q;
    for(int i=1; i<=N; i++) {
        int rain, R = 0;
        cin >> rain;
        PFX[i] = rain + PFX[i-1];
        pq.push({i+rain/M,rain%M});

        while(!pq.empty()) {
            if(pq.top().first > i) break;
            R += pq.top().second;
            pq.pop();
        }
        EVP[i+1] = pq.size()*M + R + EVP[i];
    }

    for(int i=0; i<Q; i++) {
        int C,T;
        cin >> C >> T;
        if(C == 1) cout << PFX[T] - EVP[T] << "\n";
        else cout << EVP[T] - EVP[T-1] << "\n";
    }
    exit(0);
}