#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int len;
vector<pii> ST;

pii max(pii a,pii b) {
    if(a.first >= b.first) return a;
    return b;
}

void Init() {
    for(int i=len-1; i>0; i--)
        ST[i] = max(ST[i<<1],ST[i<<1|1]);
}
pii Query(int left,int right) {
    pii ans = {0,0};
    for(left+=len,right+=len; left<right; left>>=1,right>>=1) {
        if(left&1) ans = max(ans,ST[left++]);
        if(right&1) ans = max(ans,ST[--right]);
    }
    return ans;
}
void Update(int lo,pii value) {
    for(ST[lo+=len] = value; lo>1; lo>>=1)
        ST[lo>>1] = max(ST[lo],ST[lo^1]);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N,M;
    cin >> N;

    len = N;
    ST = vector<pii>(len<<1|1,{0,0});
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        ST[len+i] = {temp,i};
    }
    Init();

    cin >> M;
    for(int i=0; i<M; i++) {
        int C,A,B;
        cin >> C >> A >> B;
        if(C == 1) Update(A-1,{B,A-1});
        else {
            pii max_p = Query(A-1,B);
            pii left_p = Query(A-1,max_p.second);
            pii right_p = Query(max_p.second+1,B);
            cout << max_p.first + max(left_p.first,right_p.first) << "\n";
        }
    }
    exit(0);
}