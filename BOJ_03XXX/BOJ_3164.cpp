#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int X1,Y1,X2,Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;
    X1++,Y1++;

    ll ans = 0;

    int X1T = X1;
    if(X1%2) X1++;
    for(int i=X1; i<=X2; i+=2) {
        int min_height = min(Y2,i);
        ans += max(0,min_height-Y1+1);
    }

    if(Y1%2) Y1++;
    for(int i=Y1; i<=Y2; i+=2) {
        int min_height = min(X2,i-1);
        ans += max(0,min_height-X1T+1);
    }
    cout << ans;
}