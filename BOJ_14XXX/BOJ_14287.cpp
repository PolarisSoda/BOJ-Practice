#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

constexpr int LEN = 100001;
vector<int> ST,A,edge[LEN];
pii range[LEN];
int cnt,len;

void ETT(int now) {
    range[now].first = ++cnt;
    for(int next : edge[now]) ETT(next);
	range[now].second = cnt;
}

void Init() {
    for(int i=len-1; i>0; i--) {
        ST[i] = ST[i<<1] + ST[i<<1|1];
    }
}

void Update_Add(int x,int val,int sz) {
    A[x] += val;
    for(x>>=1; x; x>>=1) ST[x] += val*sz;
}

void Update(int left,int right,int val) {
    int sz = 1;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1,sz<<=1) {
        if(left&1) Update_Add(left++, val, sz); 
		if(right&1) Update_Add(--right, val, sz);
    }
}

int Get(int x,int sz) {
	int ret = ST[x];
    for(x; x; x>>=1) ret += A[x]*sz;
	return ret;
}

int Query(int left,int right) {
    int ret = 0;
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

    int N,M;
    cin >> N >> M;

    len = N;
    ST = vector<int>(len<<1|1,0);
    A = vector<int>(len<<1|1,0);
    Init();

    for(int i=1; i<=N; i++) {
        int A;
        cin >> A;
        if(i == 1) continue;
        edge[A].push_back(i);
    }
    ETT(1);
    for(int i=0; i<M; i++) {
        int Q,A,B;
        cin >> Q;
        if(Q == 1) {
            cin >> A >> B;
            Update(range[A].first,range[A].first+1,B);
        } else {
            cin >> A;
            cout << Query(range[A].first,range[A].second+1) << "\n";
        }
    }
    exit(0);
}