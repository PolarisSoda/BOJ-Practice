#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 300001;

ll a[LEN];
ll DP[LEN][6];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    string str;
    cin >> N >> str;
    for(int i=1; i<=N; i++) cin >> a[i];

    for(int i=0; i<=N; i++) for(int j=0; j<6; j++) DP[i][j] = INT_MAX * (ll)100;
    DP[0][0] = 0;
    //DP[i][j] i번째까지 봤을때, j까지 완성했을때의 최소값.

    for(int i=1; i<=N; i++) {
        char now = str[i-1];

        for(int j=0; j<6; j++) DP[i][j] = DP[i-1][j];

        if(now == 'U') DP[i][1] = min(DP[i][1],a[i]);
        else if(now == 'O') DP[i][2] = min(DP[i][2],DP[i][1] + a[i]);
        else if(now == 'S') DP[i][3] = min(DP[i][3],DP[i][2] + a[i]);
        else if(now == 'P') DP[i][4] = min(DP[i][4],DP[i][3] + a[i]);
        else if(now == 'C') DP[i][5] = min(DP[i][5],DP[i][4] + a[i]);
    }
    cout << (DP[N][5] == INT_MAX * (ll)100 ? -1 : DP[N][5]);
    exit(0);
}