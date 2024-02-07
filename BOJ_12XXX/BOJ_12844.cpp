#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int LEN = 500001;
vector<ll> ST,lazy;
int A[LEN];

ll Init(int node,int S,int E) {
    if(S == E) return ST[node] = A[S];
    ll M = (S+E)>>1;
	return ST[node] = Init(node<<1,S,M) ^ Init(node<<1|1,M+1,E);
}

void Update_lazy(int node,int S,int E) {
    if(lazy[node] != 0) {
        if((E-S+1)&1) ST[node] ^= lazy[node];
        if(S != E) {
            lazy[node<<1] ^= lazy[node];
            lazy[node<<1|1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

void Update_range(int node, int S,int E,int L,int R,ll val) {
    Update_lazy(node,S,E);
	if(L>E || R<S) return;
	if(L<=S && E<=R) {
        if((E-S+1)&1) ST[node] ^= val;
		if(S != E){
			lazy[node<<1] ^= val;
            lazy[node<<1|1] ^= val;
		}
		return;
	}
	int M = (S+E)>>1;
    Update_range(node<<1,S,M,L,R,val);
    Update_range(node<<1|1,M+1,E,L,R,val);
    ST[node] = ST[node<<1] ^ ST[node<<1|1];
}

ll Sum(int node,int S,int E,int L,int R) {
	Update_lazy(node,S,E);
	if(L>E || R<S) return 0;
	if(L<=S && E<=R) return ST[node];
    
    ll M = (S+E)>>1;
	return Sum(node<<1,S,M,L,R) ^ Sum(node<<1|1,M+1,E,L,R);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,M;
    cin >> N;
    ST = vector<ll>(N<<2,0);
    lazy = vector<ll>(N<<2,0);
    for(int i=1; i<=N; i++) cin >> A[i];
    Init(1,1,N);

    cin >> M;
    for(int i=0; i<M; i++) {
        int C,I,J,K;
        cin >> C;
        if(C == 1) {
            cin >> I >> J >> K;
            Update_range(1,1,N,I+1,J+1,K);
        } else {
            cin >> I >> J;
            cout << Sum(1,1,N,I+1,J+1) << "\n";
        }
    }
    exit(0);
}