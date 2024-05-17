#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 301;
vector<int> V;
int arr[LEN],PFX[LEN];
int N,M;

bool check(int num) {
    vector<int> ret;
    int sum = 0;
    for(int i=1; i<=N; i++) {
        if(arr[i] > num) return false;
        if(sum + arr[i] > num) {
            ret.push_back(i-1);
            sum = arr[i];
        } else sum += arr[i];
    }
    if(sum) ret.push_back(N);
    if(ret.size() <= M) { V = ret; return true; }
    return false;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> arr[i], PFX[i] = arr[i] + PFX[i-1];

    int left = 0, right = 100*300+1, ans;
    while(left+1<right) {
        int mid = (left+right)>>1;
        if(check(mid)) ans = right = mid;
        else left = mid;
    }

    cout << ans << "\n";
    if(V.size() == M) {
        for(int i=0; i<V.size(); i++) cout << V[i] - (i == 0 ? 0 : V[i-1]) << " ";
    } else {
        int diff = M - V.size();
        int dnt_idx = -1,dnt_cnt = 0x7FFFFFF;
        for(int i=0; i<V.size(); i++) {
            int left = (i == 0 ? 0 : V[i-1]) + 1;
            int right = V[i];
            if(PFX[right] - PFX[left-1] == ans && dnt_cnt > right-left+1) dnt_idx = i,dnt_cnt = right-left+1;
        }
        for(int i=0; i<V.size(); i++) {
            int itv = V[i] - (i == 0 ? 0 : V[i-1]);
            if(i == dnt_idx) {cout << itv << " "; continue;}
            if(diff) {
                int cnt = min(diff,itv-1);
                diff -= cnt;
                for(int i=0; i<cnt; i++) cout << "1 ";
                cout << itv-cnt << " ";
            } else cout << itv << " ";
        }
    }
    
    exit(0);
}