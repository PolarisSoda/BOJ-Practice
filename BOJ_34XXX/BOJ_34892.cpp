#include <bits/stdc++.h>

using namespace std;

int var[9];

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0; i<9; i++) cin >> var[i];

    vector<int> ans = {-1,-1,-1};
    for(int i=0; i<=var[0]; i++) {
        for(int j=0; j<=var[0]; j++) {
            int k = var[0] - i - j;
            if(k < 0) break;
            
            bool fi = var[1]*i + var[2]*j + var[3]*k == var[4];
            bool se = var[5]*i + var[6]*j + var[7]*k == var[8];
            if(fi && se) {
                if(ans[0] >= 0) {
                    cout << 1;
                    exit(0);
                } else {
                    ans = {i,j,k};
                }
            }
        }
    }

    if(ans[0] < 0) cout << 2;
    else cout << 0 << "\n" << ans[0] << " " << ans[1] << " " << ans[2];
    exit(0);
}