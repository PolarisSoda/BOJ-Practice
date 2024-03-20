#include <bits/stdc++.h>

using namespace std;

int a[2] = {1,-1};

int func(int num) {
    int ret = 0;
    for(int i=1; i<=num; i++) ret += (num/i)*a[i&1];
    return ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int S,T;
    cin >> S >> T;

    cout << func(T) - func(S-1);
    exit(0);
}