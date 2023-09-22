#include <bits/stdc++.h>
#define DIV 1000000007

using namespace std;

typedef long long ll;

ll DP[101][101][101];

ll Dynamic(int left,int num,int right) {
    if(DP[left][num][right] != -1) return DP[left][num][right];

    ll ans = 0;
    for(int i=1; i<=num; i++) {
        int l = Dynamic(1,1,1);
        int r = Dynamic(1,1,1);
        if(l == 0 || r == 0) {
            return 0;
        }
    }
    return 0;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,L,R;
    cin >> N >> L >> R;

    cout << Dynamic(L,N,R);
}