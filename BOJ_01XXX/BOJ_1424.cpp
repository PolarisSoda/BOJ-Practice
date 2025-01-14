#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,L,C;
    cin >> N >> L >> C;
    
    int inside = min(N,(C+1)/(L+1));
    if(inside % 13 == 0) inside--;

    int Q = N / inside;
    int R = N % inside;
    
    if(R == 0) cout << Q;
    else if(R % 13 == 0 && R == inside - 1) cout << Q + 2;
    else cout << Q + 1;
    exit(0);
}