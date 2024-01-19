#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 1000001;

int arr[LEN],sum[LEN];
int N,P;

bool check(int num) {
    //num이 최대 연속 일수가 될 수 있는가?
    if(num <= P) return true;
    if(sum[num-1]+P >= num) return true;
    for(int i=num; i<LEN; i++) if(sum[i]-sum[i-num]+P >= num) return true;
    return false;
}
int solve() {
    cin >> N >> P;
    
    memset(arr,0,sizeof(arr));
    for(int i=1; i<=N; i++) {
        int temp;
        cin >> temp;
        arr[temp]++;
    }

    sum[0] = arr[0];
    for(int i=1; i<LEN; i++) sum[i] = sum[i-1] + arr[i];

    int left = 0;
    int right = 400001;
    int ans = 1;
    while(left+1<right) {
        int mid = (left+right)/2;
        if(check(mid)) {
            ans = mid;
            left = mid;
        } else right = mid;
    }
    return ans;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " " << solve() << "\n";
}