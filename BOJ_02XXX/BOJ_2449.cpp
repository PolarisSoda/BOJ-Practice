#include <bits/stdc++.h>

using namespace std;

int DP[201][201];
int bulb[201];

int Dynamic(int left,int right) {
    if(left == right) return 0;
    if(DP[left][right] != -1) return DP[left][right];
    int ret = 0x7FFFFFFF;
    for(int i=left; i<right; i++) {
        int temp = Dynamic(left,i) + Dynamic(i+1,right);
        if(bulb[left] != bulb[i+1]) temp++;
        ret = min(ret,temp);
    }
    return DP[left][right] = ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K;
    cin >> N >> K;

    for(int i=1; i<=N; i++) cin >> bulb[i];
    memset(DP,-1,sizeof(DP));
    
    cout << Dynamic(1,N);
    return 0;
}