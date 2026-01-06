#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ll U,O,S;
    cin >> U >> O >> S;

    if(S >= U) cout << min(O,U);
    else cout << min(O,(U+2*S)/3);
    exit(0);
}