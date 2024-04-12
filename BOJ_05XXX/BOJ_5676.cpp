#include <bits/stdc++.h>

using namespace std;

int len;
int ST[2000001];

void Init() {
    for(int i=len-1; i>0; i--)
        ST[i] = ST[i<<1] * ST[i<<1|1];
}
int Query(int left,int right) {
    int ans = 1;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1) {
        if(left&1) ans *= ST[left++];
        if(right&1) ans *= ST[--right];
    }
    return ans;
}
void Update(int lo,int value) {
    for(ST[lo+=len] = value; lo>1; lo>>=1)
        ST[lo>>1] = ST[lo] * ST[lo^1];
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N,K;
    while(cin >> N >> K) {
        len = N;
        for(int i=0; i<=2000000; i++) ST[i] = 1;
        for(int i=0; i<N; i++) {
            int temp;
            cin >> temp;
            if(temp > 0) temp = 1;
            else if(temp < 0) temp = -1;
            else temp = 0;
            Update(i,temp);
        }
        for(int i=0; i<K; i++) {
            char C;
            cin >> C;
            if(C == 'C') {
                int A,B;
                cin >> A >> B;
                if(B > 0) B = 1;
                else if(B < 0) B = -1;
                Update(A-1,B);
            } else {
                int A,B;
                cin >> A >> B;
                int ans = Query(A-1,B);
                if(ans > 0) cout << '+';
                else if(ans < 0) cout << '-';
                else cout << '0';
            }
        }
        cout << "\n";
    }
}