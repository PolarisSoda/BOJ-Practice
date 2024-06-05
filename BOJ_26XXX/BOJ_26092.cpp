#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> VA,VB;
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll A,B;
    cin >> A >> B;

    ll LA = A, LB = B;
    VA.push_back(A), VB.push_back(B);
    for(ll i=2; i*i<=LA; i++) {
        if(A == 1) break;
        while(A%i == 0) VA.push_back(A/=i);
    }
    if(A != 1) VA.push_back(1);
    for(ll i=2; i*i<=LB; i++) {
        if(B == 1) break;
        while(B%i == 0) VB.push_back(B/=i);
    }
    if(B != 1) VB.push_back(1);

    ll ans = 1;
    for(int i=0; i<VA.size(); i++) {
        for(int j=0; j<VB.size(); j++) {
            if(VA[i] == VB[j]) ans = max(ans,VA[i]);
        }
    }
    cout << ans;
}