#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> prime;
bool visited[32001];

ll Euler_Phi(ll N) {
    ll ret = N;
    for(int num : prime) {
        if(N%num) continue;
        while(N%num == 0) N /= num;
        ret -= ret/num;
    }
    if(N > 1) ret -= ret/N;
    return ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=2; i<=32000; i++) {
        if(visited[i]) continue;
        prime.push_back(i);
        for(int j=i; j<=32000; j+=i) visited[j] = true;
    }

    ll N;
    cin >> N;

    ll ret = INT_MAX;
    for(ll i=1; i*i<=N; i++) {
        if(N%i != 0) continue;

        if(Euler_Phi(N/i) == i) ret = min(ret,N/i);
        if(Euler_Phi(i) == N/i) ret = min(ret,i);
    }
    
    if(ret == INT_MAX) cout << -1;
    else cout << ret;

    exit(0);
}