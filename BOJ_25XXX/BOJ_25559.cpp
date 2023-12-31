#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll N;
    cin >> N;
    ll sum = N*(N+1)/2;

    if(N == 1) cout << 1,exit(0);
    if(sum%N == 0) cout << -1, exit(0);
    for(int i=0; i<N; i++) cout << (i%2 ? i : N-i) << " ";
} 