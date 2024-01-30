#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int len;
vector<ll> ST,A; //ST = Segment Tree, A = Add

void Init() {
    for(int i=len-1; i>0; i--) {
        ST[i] = ST[i<<1] + ST[i<<1|1];
    }
}

void Update_Add(int x,ll val,int sz) {
    A[x] += val;
    for(x>>=1; x; x>>=1) ST[x] += val*sz;
}

void Update(int left,int right,ll val) {
    int sz = 1;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1,sz<<=1) {
        if(left&1) Update_Add(left++, val, sz); 
		if(right&1) Update_Add(--right, val, sz);
    }
}

ll Get(int x,int sz) {
	ll ret = ST[x];
    for(x; x; x>>=1) ret += A[x]*sz;
	return ret;
}

ll Query(int left,int right) {
    ll ret = 0;
    int sz = 1;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1,sz<<=1) {
        if(left&1) ret += Get(left++,sz);
        if(right&1) ret += Get(--right,sz);
    }
    return ret;
}

//REMINDER : A~B의 구간처리하고 싶다면, A~B+1로 해라.
//REMINDER : 백준 10999번이 Sample입니다.

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M,K;
    cin >> N >> M >> K;

    len = N;
    ST = vector<ll>(len<<1|1,0);
    A = vector<ll>(len<<1|1,0);
    for(int i=0; i<len; i++) cin >> ST[len+i];
    Init();

    for(int i=0; i<M+K; i++) {
        ll a,b,c,d;
        cin >> a;
        if(a == 1) {
            cin >> b >> c >> d;
            Update(b-1,c,d);
        } else {
            cin >> b >> c;
            cout << Query(b-1,c) << "\n";
        }
    }
}