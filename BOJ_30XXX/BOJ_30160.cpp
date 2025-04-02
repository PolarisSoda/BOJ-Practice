#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 100001;
ll arr[LEN],OTN[LEN],PFX[LEN];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i], OTN[i] = OTN[i-1] + arr[i];
    
    for(int i=1; i<=N; i++) PFX[i] = PFX[i-1] + OTN[i-1]*2 + arr[i];

    ll ret = 0;
    for(int i=1; i<=N; i++) cout << (ret += PFX[i]) << " ";
    exit(0);
}