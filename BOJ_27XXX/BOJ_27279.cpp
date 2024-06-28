#include <bits/stdc++.h>

using namespace std;

vector<int> VA,VB;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;
    VA.resize(N), VB.resize(M);
    for(int i=0; i<N; i++) cin >> VA[i];
    for(int i=0; i<M; i++) cin >> VB[i];
    sort(VA.begin(),VA.end(),greater<int>());
    sort(VB.begin(),VB.end(),greater<int>());

    int idx = 0, th = M;
    for(int i=0; i<M; i++) {
        int req = VB[i];
        for(int j=0; j<req; j++)
            if(VA[idx+j] < th) cout << "NO",exit(0);
        idx += req;
        th--;
    }
    cout << "YES";
    exit(0);
}