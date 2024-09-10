#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    N %= 4;
    cout << N*(N-1)*(N-2)/6 + 1;
}