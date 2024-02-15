#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
struct Result {
    int top,count;
};

constexpr int LEN = 1000001;
vector<ll> ST,lazy,ST2;
int A[LEN],len;
ll cnt;

void Update_lazy(int node,int S,int E) {
    if(lazy[node] != 0) {
        ST[node] += lazy[node];
        ST2[node] += lazy[node];
        if(S != E) {
            lazy[node<<1] += lazy[node];
            lazy[node<<1|1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void Update_range(int node, int S,int E,int L,int R,ll val) {
    Update_lazy(node,S,E);
	if(L>E || R<S) return;
	if(L<=S && E<=R){
        ST[node] += val;
        ST2[node] += val;
		if(S != E){
			lazy[node<<1] += val;
            lazy[node<<1|1] += val;
		}
		return;
	}
	int M = (S+E)>>1;
    Update_range(node<<1,S,M,L,R,val);
    Update_range(node<<1|1,M+1,E,L,R,val);
    ST[node] = max(ST[node<<1],ST[node<<1|1]);
    ST2[node] = min(ST2[node<<1],ST2[node<<1|1]);
}

ll Sum(int node,int S,int E,int L,int R) {
	Update_lazy(node,S,E);
	if(L>E || R<S) return LONG_LONG_MIN;
	if(L<=S && E<=R) return ST[node];
    
    ll M = (S+E)>>1;
	return max(Sum(node<<1,S,M,L,R),Sum(node<<1|1,M+1,E,L,R));
}

ll Sum2(int node,int S,int E,int L,int R) {
	Update_lazy(node,S,E);
	if(L>E || R<S) return LONG_LONG_MAX;
	if(L<=S && E<=R) return ST2[node];
    
    ll M = (S+E)>>1;
	return min(Sum2(node<<1,S,M,L,R),Sum2(node<<1|1,M+1,E,L,R));
}

void init(int C) {
    len = C;
    ST = vector<ll>(len<<2,0);
    ST2 = vector<ll>(len<<2,0);
    lazy = vector<ll>(len<<2,0);
    cnt = 0;
}

Result dropBlocks(int mCol, int H, int W) {
    Result ret;
    cnt += H*W;
    Update_range(1,1,len,mCol+1,mCol+W,H);
    ll maxv = Sum(1,1,len,1,len);
    ll minv = Sum2(1,1,len,1,len);
    return {maxv-minv,(cnt-minv*len)%1000000};
}
