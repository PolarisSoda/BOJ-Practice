#include <bits/stdc++.h>

using namespace std;

vector<int> V;

int main() {
    int N;
    cin >> N;

    V.resize(N);
    for(int i=0; i<N; i++) cin >> V[i];
    sort(V.begin(),V.end());

    int ret = 0;
    for(int i=1; i<N; i++) {
        if(__gcd(V[i-1],V[i]) == 1) continue;

        int local = 2;
        for(int j=V[i-1]+1; j<V[i]; j++)
            if(__gcd(V[i-1],j) == 1 && __gcd(j,V[i]) == 1) local = 1;
        ret += local;
    }
    cout << ret;
    exit(0);
}