#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;

    int len = 0x7FFFFFFF;
    vector<int> ans;
    for(int i=1; i*i<=N; i++) {
        if(N%i) continue;
        int A = i, B = N/i;
        if(A&1) {
            //길이가 짝수일 때.
            int left = A>>1, right = left+1,tlen = N/A;
            if(tlen <= left && tlen*2 < len) {
                len = tlen*2;
                ans.clear();
                for(int j=left-tlen+1; j<=right+tlen-1; j++) ans.push_back(j);
            }

            tlen = (A-1)/2;
            int num = N/A;
            if(tlen != 0 && tlen < num && A < len) {
                len = A;
                ans.clear();
                for(int j=num-tlen; j<=num+tlen; j++) ans.push_back(j);
            }
        } 
        if(B&1) {
            int left = B>>1, right = left+1,tlen = N/B;
            if(tlen <= left && tlen*2 < len) {
                len = tlen*2;
                ans.clear();
                for(int j=left-tlen+1; j<=right+tlen-1; j++) ans.push_back(j);
            }

            tlen = (B-1)/2;
            int num = N/B;
            if(tlen != 0 && tlen < num && B < len) {
                len = B;
                ans.clear();
                for(int j=num-tlen; j<=num+tlen; j++) ans.push_back(j);
            }
        }
    }
    if(ans.size() == 0) cout << "IMPOSSIBLE\n";
    else {
        cout << N << " ";
        for(int i=0; i<ans.size(); i++) {
            if(i) cout << "+ ";
            else cout << "= ";
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=0; i<T; i++) solve();
    exit(0);
}