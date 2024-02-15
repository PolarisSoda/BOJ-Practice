#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

struct compare {
    bool operator()(pii a,pii b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

constexpr int LEN = 10001;
int people[LEN]; //도시마다 사람 수.
int r_cnt[LEN];
vector<int> ST;
int len;
priority_queue<pii,vector<pii>,compare> pq;

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

void init(int N, int mPopulation[]) {
    memset(people,0,sizeof(people));
    memset(r_cnt,0,sizeof(r_cnt));
    len = N+1;
    ST = vector<int>(len<<1|1,0);
    pq = priority_queue<pii,vector<pii>,compare>();

    for(int i=0; i<N-1; i++) {
        people[i] = mPopulation[i];
        int sum = people[i] + mPopulation[i+1];
        pq.push({sum,i});
        Update(i,sum);
        r_cnt[i] = 1;
    }
    people[N-1] = mPopulation[N-1];
}

int expand(int M) {
    int sum = -1;
    for(int i=0; i<M; i++) {
        int idx = pq.top().second;
        pq.pop();
        r_cnt[idx]++;
        sum = (people[idx]+people[idx+1])/r_cnt[idx];
        pq.push({sum,idx});
        Update(idx,sum);
    }
    return sum;
}

int calculate(int mFrom, int mTo) {
    if(mFrom > mTo) swap(mFrom,mTo);
    return Query(mFrom,mTo);
}

bool check(int num,int L,int R,int K) {
    int cnt = 1;
    int sum = 0;
    for(int i=L; i<=R; i++) {
        if(sum + people[i] > num) cnt++, sum = 0;
        sum += people[i];
    }
    if(cnt <= K) return true;
    return false;
}

int divide(int mFrom, int mTo, int K) {
    int left = 0;
    int right = 10000001;
    int ans = 0;
    while(left+1<right) {
        int mid = (left+right)/2;
        if(check(mid,mFrom,mTo,K)) ans = right = mid;
        else left = mid;
    }
    return ans;
}