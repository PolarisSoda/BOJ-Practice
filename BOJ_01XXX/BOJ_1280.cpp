#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll DIV = 1'000'000'007;
int len = 200001;
vector<ll> MST,CST;

void Init(vector<ll>& ST) {
    for(int i=len-1; i>0; i--)
        ST[i] = ST[i<<1] + ST[i<<1|1];
}
ll Query(vector<ll>& ST,int left,int right) {
    ll ans = 0;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1) {
        if(left&1) ans += ST[left++];
        if(right&1) ans += ST[--right];
    }
    return ans;
}
void Update(vector<ll>& ST,int lo,ll value) {
    for(ST[lo+=len] += value; lo>1; lo>>=1)
        ST[lo>>1] = ST[lo] + ST[lo^1];
}

int main() {
    int N;
    cin >> N;
    MST.resize(len<<1,0), CST.resize(len<<1,0);
    
    int fi;
    cin >> fi;
    Update(MST,fi,fi);
    Update(CST,fi,1);
    
    ll ans = 1;
    for(int i=1; i<N; i++) {
        int temp;
        cin >> temp;    
        ll left = Query(MST,temp+1,200000) - Query(CST,temp+1,200000)*temp;
        ll right = Query(CST,0,temp)*temp - Query(MST,0,temp);
        ans = (ans*((left+right)%DIV))%DIV;
        Update(MST,temp,temp);
        Update(CST,temp,1);
    }
    cout << ans;
    exit(0);
}