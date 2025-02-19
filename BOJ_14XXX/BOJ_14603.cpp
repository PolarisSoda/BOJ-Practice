#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 301;
vector<int> ST;
int arr[LEN][LEN],ans[LEN][LEN];
int len,lx,ly;
int N,M,K,W;

void Init() {
    for(int i=len-1; i>0; i--)
        ST[i] = ST[i<<1] + ST[i<<1|1];
}
int Query(int left,int right) {
    int ans = 0;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1) {
        if(left&1) ans += ST[left++];
        if(right&1) ans += ST[--right];
    }
    return ans;
}
void Update(int lo,int value) {
    for(ST[lo+=len] += value; lo>1; lo>>=1)
        ST[lo>>1] = ST[lo] + ST[lo^1];
}

int Binary() {
    int left = -1, right = K+1, ret = -1;
    while(left+1<right) {
        int mid = (left+right) >> 1;
        if(Query(0,mid+1) > W*W/2) right = ret = mid;
        else left = mid;
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> M >> N >> K >> W;
    for(int i=0; i<M; i++) for(int j=0; j<N; j++) cin >> arr[i][j];

    len = K+1;
    for(int ly=0; ly+W<=M; ly++) {
        ST = vector<int>(len<<1,0);
        int lx = 0;

        for(int i=ly; i<ly+W; i++) for(int j=lx; j<lx+W; j++) Update(arr[i][j],1);
        ans[ly][lx] = Binary();

        for(lx=1; lx+W<=N; lx++) {
            for(int i=ly; i<ly+W; i++) Update(arr[i][lx-1],-1), Update(arr[i][lx+W-1],1);
            ans[ly][lx] = Binary();
        }
    }

    for(int i=0; i<M-W+1; i++) {
        for(int j=0; j<N-W+1; j++) cout << ans[i][j] << " ";
        cout << "\n";
    }
    exit(0);
}