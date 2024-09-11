#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr ull DIV = ULLONG_MAX;
vector<ll> candy;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll M,N;
    cin >> M >> N;
    ll sum = 0;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        candy.push_back(temp);
        sum += temp;
    }
    sort(candy.begin(),candy.end());

    ll R = sum - M;
    ull ans = 0;
    for(int i=0; i<N; i++) {
        ll r = min(candy[i],R/(N-i));
        ans = (ans + (ull)r*r)%DIV;
        R -= r;
    }
    //R은 정해져있음.
    //그리고 여러개로 펼치면 펼칠수록 이득임.
    //
    cout << ans;
    exit(0);
}