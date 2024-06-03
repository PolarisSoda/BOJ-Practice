#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int ans = 1, maxv = 0, cnt = 1;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        if(maxv <= num) {
            maxv = num;
            ans = max(ans,cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }
    cout << max(ans,cnt);
    exit(0);
}