#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> SO,TO;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    string S,T;
    cin >> N >> M >> S >> T;

    for(int i=0; i<N+M; i++) {
        if(S[i] == '1') SO.push_back(i);
        if(T[i] == '1') TO.push_back(i);
    }
    ll ans = 0;
    for(int i=0; i<M; i++) SO[i] > TO[i] ? ans += SO[i] - TO[i] : ans += TO[i] - SO[i];
    ll frac = ans >> 1LL;
    ll b = ans&1LL;
    cout << frac*frac + (frac+b)*(frac+b);
    return 0;
}