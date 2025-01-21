#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        M -= temp+1;
    }

    if(M <= 0) cout << 0, exit(0);

    //residaul = M
    int bias = M/(N+1);
    int res = M%(N+1);
    cout << (N+1)*bias*(bias+1)*(bias*2+1)/ 6 + (bias+1)*(bias+1)*res;
}