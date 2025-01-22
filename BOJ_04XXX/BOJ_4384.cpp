#include <bits/stdc++.h>

using namespace std;

bool DP[101][45005];
int arr[101];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int sum = 0;
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    DP[0][0] = true;
    for(int i=1; i<=N; i++) {
        for(int j=N/2; j>=1; j--) {
            for(int k=arr[i]; k<=sum; k++) {
                DP[j][k] |= DP[j-1][k-arr[i]];
            }
        }
    }

    int idx = N>>1;
    int minv = -1000000, maxv = 1000000;
    for(int i=0; i<=sum; i++) {
        if(!DP[idx][i]) continue;
        int local_minv = min(sum-i,i);
        int local_maxv = sum - local_minv;
        if(local_maxv-local_minv < maxv-minv) maxv = local_maxv, minv = local_minv;
    }

    cout << minv << " " << maxv;
    exit(0);
}