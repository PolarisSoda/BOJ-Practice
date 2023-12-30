#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> tree,prefix;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll N,Q;
    cin >> N >> Q;
    for(int i=0; i<N; i++) {
        ll temp;
        cin >> temp;
        tree.push_back(temp);
    }
    sort(tree.begin(),tree.end());
    
    prefix.push_back(0);
    for(int i=1; i<=N; i++) prefix.push_back(tree[i-1] + prefix.back());

    for(int i=0; i<Q; i++) {
        ll X;
        cin >> X;
        
        ll lo = lower_bound(tree.begin(),tree.end(),X) - tree.begin();
        ll left = X*lo - prefix[lo];
        ll right = prefix[N] - prefix[lo] - X*(N-lo);
        cout << left+ right << "\n";
    }
    return 0;
}