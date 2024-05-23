#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> prime;
bool visited[100001];

ll solve() {
    ll N;
    cin >> N;

    ll ans = 1;
    for(int num : prime) {
        if(N == 1) break;
        ll cnt = 0;
        while(N%num == 0) cnt += 2, N /= num;
        ans *= (cnt+1);
    }
    if(N > 1) ans *= 3;
    return ans/2+1;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    for(int i=2; i<=100000; i++) {
        if(visited[i] == false) {
            prime.push_back(i);
            for(int j=i; j<=100000; j+=i) visited[j] = true;
        }
    }

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) {
        cout << "Scenario #" << i << ":\n" << solve() << "\n\n"; 
    }
}   