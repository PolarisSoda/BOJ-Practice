#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<int,int,int,int> info;

constexpr int LEN = 100000;
int len;
vector<ll> ST;
vector<pair<int,int>> UD;
vector<info> OQ;
ll PR[LEN];

bool compare(info a,info b){
    return get<0>(a) < get<0>(b);
}

void Init() {
    for(int i=len-1; i>0; i--) {
        ST[i] = ST[i<<1] + ST[i<<1|1];
    }
}
ll Query(int left,int right) {
    ll ans = 0;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1) {
        if(left&1)
            ans += ST[left++];
        if(right&1)
            ans += ST[--right];
    }
    return ans;
}
void Update(int lo,ll value) {
    for(ST[lo+=len] = value; lo>1; lo>>=1) {
        ST[lo>>1] = ST[lo] + ST[lo^1];
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> len;
    ST.resize(len<<1|1);
    for(int i=0; i<len; i++) cin >> ST[len+i];
    Init();

    int M;
    cin >> M;
    for(int i=0; i<M; i++) {
        int Q,A,B,C;
        cin >> Q;
        if(Q == 1) {
            cin >> A >> B;
            UD.push_back({A,B});
        } else {
            cin >> A >> B >> C;
            OQ.push_back({A,B,C,i});
        }
    }
    sort(OQ.begin(),OQ.end(),compare);

    int prev = 0;
    for(info now : OQ) {
        int K,I,J,idx;
        tie(K,I,J,idx) = now;
        if(K != prev) {
            while(prev != K) {
                Update(UD[prev].first-1,UD[prev++].second);
                prev++;
            }
        }
        PR[idx] = Query(I-1,J);
    }
    for(int i=0; i<LEN; i++) if(PR[i] != 0) cout << PR[i] << "\n";
    exit(0);
}