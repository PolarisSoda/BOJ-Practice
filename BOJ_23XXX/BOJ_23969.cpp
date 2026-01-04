#include <bits/stdc++.h>

using namespace std;

vector<int> V;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K;
    cin >> N >> K;
    V.resize(N);
    for(int i=0; i<N; i++) cin >> V[i];

    int cnt = 0;
    for(int i=N-1; i>=1; i--) {
        for(int j=0; j<i; j++) {
            if(V[j] > V[j+1]) {
                swap(V[j],V[j+1]);
                cnt++;
            }
            if(cnt == K) goto print;
        }
    }

    print:
    if(cnt < K) cout << -1;
    else for(int num : V) cout << num << " ";
}