#include <bits/stdc++.h>

using namespace std;

int arr[8],SSS[16],N;
int ans[16];

void BF(int num) {
    bool ret = false;
    int limit = (N<<1);
    for(int i=0; i<limit; i++) {
        int left = i, right = i+arr[num]+1;
        if(right >= limit) continue;
        if(SSS[left] != -1 || SSS[right] != -1) continue;
        SSS[left] = SSS[right] = arr[num];
        if(num == N-1) {
            if(ans[0] == -1) for(int j=0; j<limit; j++) ans[j] = SSS[j];
            else {
                bool bigger = false;
                for(int j=0; j<limit; j++) {
                    if(ans[j] != SSS[j]) {bigger = (ans[j] > SSS[j]); break;}
                }
                if(bigger) for(int j=0; j<limit; j++) ans[j] = SSS[j];
            }
        }
        BF(num+1);
        SSS[left] = SSS[right] = -1;
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    sort(arr,arr+N);
    memset(SSS,-1,sizeof(SSS));
    memset(ans,-1,sizeof(ans));
    BF(0);
    if(ans[0] == -1) cout << -1;
    else for(int j=0; j<(N<<1); j++) cout << ans[j] << " ";
    exit(0);
}