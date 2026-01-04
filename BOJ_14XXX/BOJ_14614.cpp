#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A,B;
    string C;
    cin >> A >> B >> C;
    
    int last = C.back() - '0';
    cout << (last&1 ? A^B : A);
    exit(0);
}