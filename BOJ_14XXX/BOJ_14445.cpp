#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll N;
    cin >> N;

    if(N == 1) cout << 0;
    else cout << (N+1)/2;
    
    return 0;
}