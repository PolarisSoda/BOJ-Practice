#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

vector<int> V;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,A,B,C;
    cin >> N >> A >> B >> C;

    V.resize(N);
    for(int i=0; i<N; i++) cin >> V[i];
    sort(V.rbegin(),V.rend());

    int price = A, cal = C;
    ld maxv = cal / price;
    for(int num : V) {
        price += B;
        cal += num;
        maxv = max(maxv,(ld)cal/price);
    }
    cout << (int)maxv;
    exit(0);
}