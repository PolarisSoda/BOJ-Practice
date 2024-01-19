#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 200001;

int usb[LEN],dat[LEN];
int N,K;

bool check(int num) {
    int idx = 0;
    for(int i=0; i<N; i++) {
        if(usb[i] > num) continue;

        int R = i + dat[idx];
        for(int j=i; j<R; j++) {
            if(j >= N) break;
            i = j;
            if(usb[j] > num) break;
            if(j == R-1) idx++;
        }
        if(idx == K) return true;
    }
    return false;
}

int solve() {
    cin >> N >> K;
    for(int i=0; i<N; i++) cin >> usb[i];
    for(int i=0; i<K; i++) cin >> dat[i];

    int left = 0;
    int right = 200001;
    int ans = 200000;
    while(left+1<right) {
        int mid = (left+right)/2;
        if(check(mid)) ans = mid,right = mid;
        else left = mid;
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