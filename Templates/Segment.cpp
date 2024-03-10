#include <bits/stdc++.h>

using namespace std;

int len;
vector<int> ST;

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
    for(ST[lo+=len] = value; lo>1; lo>>=1)
        ST[lo>>1] = ST[lo] + ST[lo^1];
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    len = 1111;
    ST = vector<int>(len<<1|1,0);
}