#include <bits/stdc++.h>

using namespace std;

int arr[100001];
bool have[500001];
int N,M;

bool check(int num) {
    if(num*M > N) return false;
    memset(have,false,sizeof(have));

    int left = 0, right = 0;
    int cnt = 0;

    while(right < N) {
        int now = arr[right];

        while(have[now] == true) have[arr[left++]] = false;
        have[now] = true;
        if(right-left+1 >= num) {
            cnt++;
            right++;
            while(left != right) have[arr[left++]] = false;
        } else {
            right++;
        }
    }
    return cnt >= M;
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> arr[i];

    int left = 0, right = N+1, ans = 1;
    while(left+1 < right) {
        int mid = (left+right)>>1;

        if(check(mid)) left = ans = mid;
        else right = mid;
    }
    cout << ans;
    exit(0);
}