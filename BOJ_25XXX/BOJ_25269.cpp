#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 101;
int arr[LEN];
int N,E,O;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        E += temp%2 == 0;
        O += temp%2;
    }

    int ans = N%2 == 0 ? E == O : O == E + 1;
    cout << ans;
    exit(0);
}