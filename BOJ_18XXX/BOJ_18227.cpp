#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

constexpr int LEN = 300001;
ll D[LEN],cnt,len;
vector<ll> ST,A;
vector<int> edge[LEN];
bool visited[LEN];
pii range[LEN];

void ETT(int now,int depth) {
    range[now].first = ++cnt;
    D[now] = depth;
    visited[now] = true;
    for(int next : edge[now]) if(!visited[next]) ETT(next,depth+1);
	range[now].second = cnt;
}

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

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,C,Q;
    cin >> N >> C;

    len = N;
    ST = vector<ll>(len<<1|1,0);
    A = vector<ll>(len<<1|1,0);

    for(int i=0; i<N-1; i++) {
        int X,Y;
        cin >> X >> Y;
        edge[X].push_back(Y);
        edge[Y].push_back(X);
    }
    ETT(C,1);
    
    cin >> Q;
    for(int i=0; i<Q; i++) {
        int A,B;
        cin >> A >> B;
        if(A == 1) Update(range[B].first,range[B].first+1,1);
        else cout << Query(range[B].first,range[B].second+1)*D[B] << "\n";
    }
    exit(0);
}