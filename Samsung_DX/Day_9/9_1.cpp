#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 0x7FFFFFFF;
int len = 2000001;
vector<int> Min_ST,Max_ST;

void Min_Init() {
    for(int i=len-1; i>0; i--) {
        Min_ST[i] = min(Min_ST[i<<1],Min_ST[i<<1|1]);
    }
}
int Min_Query(int left,int right) {
    int ans = INF;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1) {
        if(left&1)
            ans = min(ans,Min_ST[left++]);
        if(right&1)
            ans = min(ans,Min_ST[--right]);
    }
    return ans;
}

void Min_Update(int lo,int value) {
    for(Min_ST[lo+=len] = value; lo>1; lo>>=1) {
        Min_ST[lo>>1] = min(Min_ST[lo],Min_ST[lo^1]);
    }
}

void Max_Init() {
    for(int i=len-1; i>0; i--) {
        Max_ST[i] = max(Max_ST[i<<1],Max_ST[i<<1|1]);
    }
}
int Max_Query(int left,int right) {
    int ans = -1;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1) {
        if(left&1)
            ans = max(ans,Max_ST[left++]);
        if(right&1)
            ans = max(ans,Max_ST[--right]);
    }
    return ans;
}
void Max_Update(int lo,int value) {
    for(Max_ST[lo+=len] = value; lo>1; lo>>=1) {
        Max_ST[lo>>1] = max(Max_ST[lo],Max_ST[lo^1]);
    }
}

void solve() {
    int N,Q;
    cin >> N >> Q;

    len = N;
    Min_ST = vector<int>(len<<1|1,0x7FFFFFFF);
    Max_ST = vector<int>(len<<1|1,0);
    for(int i=0; i<N; i++) {
        int A;
        cin >> A;
        Min_ST[len+i] = A;
        Max_ST[len+i] = A;
    }
    Min_Init();
    Max_Init();

    for(int i=0; i<Q; i++) {
        int A,B,C;
        cin >> A >> B >> C;
        if(A == 0) {
            Min_Update(B,C);
            Max_Update(B,C);
        } else {
            cout << Max_Query(B,C) - Min_Query(B,C) << " ";
        }
    }
    cout << "\n";
}



int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    for(int i=1; i<=T; i++) cout << "#" << i << " ", solve();
    return 0;
}