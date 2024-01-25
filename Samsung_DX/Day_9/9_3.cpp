#include <bits/stdc++.h>

using namespace std;

int len;
vector<int> ST,road[1001];

void Init() {
    for(int i=len-1; i>0; i--) {
        ST[i] = ST[i<<1] + ST[i<<1|1];
    }
}
int Query(int left,int right) {
    int ans = 0;
    for(left+=len,right+=len; left<right; left>>=1,right>>=1) {
        if(left&1)
            ans += ST[left++];
        if(right&1)
            ans += ST[--right];
    }
    return ans;
}

void Update(int lo,int value) {
    for(ST[lo+=len] = value; lo>1; lo>>=1) {
        ST[lo>>1] = ST[lo] + ST[lo^1];
    }
}

void init(int N,int M,int mType[],int mTime[]) {
    len = N-1;
    ST = vector<int>(len<<1|1,0);
    for(int i=0; i<=1000; i++) road[i] = vector<int>();

    for(int i=0; i<len; i++) {
        ST[len+i] = mTime[i];
        road[mType[i]].push_back(i);
    }
    Init();
}

void destroy() {

}

void update(int mID,int mNewTime) {
    Update(mID,mNewTime);
}

int updateByType(int mTypeID,int mRatio256) {
    int ret = 0;
    for(int idx : road[mTypeID]) {
        int ori = ST[len+idx];
        int new_value = ori * mRatio256 / 256;
        ret += new_value;
        Update(idx,new_value);
    }
    return ret;
}

int calculate(int mA,int mB) {
    if(mA > mB) swap(mA,mB);
    return Query(mA,mB);
}