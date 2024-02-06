#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 20001;
unordered_map<int,int> nti;
int pt[LEN]; //내 위의 부모 idx
int w[LEN]; //하위까지 합
int c_cnt[LEN]; //자식 개수
bool dead[LEN];
int cnt; 
int G;
void init(int N,int ID[],int W[]) {
    memset(dead,0,sizeof(dead));
    memset(c_cnt,0,sizeof(c_cnt));
    memset(w,0,sizeof(w));
    for(int i=0; i<LEN; i++) pt[i] = i;
    nti.clear();
    cnt = 0;
    G = N;

    for(int i=0; i<N; i++) {
        nti.insert({ID[i],++cnt});
        w[cnt] = W[i];
    }
}

int add(int ID,int N,int P) {
    int idx_p = nti[P];
    if(c_cnt[idx_p] == 3) return -1;

    nti.insert({ID,++cnt});
    int idx_c = nti[ID];
    pt[idx_c] = idx_p;
    c_cnt[idx_p]++;
    
    int i;
    for(i=idx_c; pt[i]!=i; i=pt[i]) w[i] += N;
    w[i] += N;

    return w[idx_p];
}

int remove(int ID) {
    if(nti.count(ID) == 0) return -1;
    
    int idx = nti[ID];
    for(int i=idx; pt[i]!=i; i=pt[i]) if(dead[i]) return -1;
    dead[idx] = true;
    c_cnt[pt[idx]]--;

    int ret = w[idx];

    int i;
    for(i=idx; pt[i]!=i; i=pt[i]) w[i] -= ret;
    w[i] -= ret;
    return ret;
}

bool check(int num,int K) {
    int sum = 0;
    for(int i=1; i<=G; i++) {
        sum += min(w[i],num);
    }
    if(sum <= K) return true;
    return false;
}

int distribute(int K) {
    int sum = 0;
    int maxv = 0;
    for(int i=1; i<=G; i++) sum += w[i], maxv = max(maxv,w[i]);
    if(sum <= K) return maxv;

    int left = 0;
    int right = K+1;
    int ans = 0;
    while(left+1<right) {
        int mid = (left+right)/2;
        if(check(mid,K)) {
            ans = mid;
            left = mid;
        } else right = mid;
    }
    return ans;
}