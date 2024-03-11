#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int len;
vector<ll> ST;

void R_Init() {
    for(int i=len-1; i>0; i--)
        ST[i] = ST[i<<1] + ST[i<<1|1];
}
void R_Update(int left,int right,ll value) {
    int ans = 0;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1) {
        if(left&1) ST[left++] += value;
        if(right&1) ST[--right] += value;
    }
}
ll R_Query(int lo) {
    ll ans = 0;
    for(lo+=len; lo>0; lo>>=1) ans += ST[lo];
    return ans;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N,M;
    cin >> N;
    
    len = N;
    ST = vector<ll>(len<<1|1,0);
    
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        ST[len+i] = temp;
    }
    cin >> M;
    for(int i=0; i<M; i++) {
        int command;
        cin >> command;
        if(command == 1) {
            int a,b,c;
            cin >> a >> b >> c;
            R_Update(a-1,b,c);
        } else {
            int x;
            cin >> x;
            cout << R_Query(x-1) << "\n";
        }
    }
    return 0;
}

