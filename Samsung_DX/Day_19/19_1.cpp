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

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N, int mPopulation[]);
extern int expand(int M);
extern int calculate(int mFrom, int mTo);
extern int divide(int mFrom, int mTo, int K);

/////////////////////////////////////////////////////////////////////////

#define MAX_N				10000

#define CMD_INIT			100
#define CMD_EXPAND			200
#define CMD_CALCULATE		300
#define CMD_DIVIDE			400

static bool run()
{
	int population[MAX_N];
	int cmd, ans, ret;
	int Q = 0;
	int N, from, to, num;
	bool okay = false;

	scanf("%d", &Q);

	for (int q = 0; q < Q; ++q)
	{
		scanf("%d", &cmd);

		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d", &N);

			for (int i = 0; i < N; i++)
				scanf("%d", &population[i]);

			init(N, population);
			okay = true;
			break;

		case CMD_EXPAND:
			scanf("%d", &num);
			ret = expand(num);
			scanf("%d", &ans);
			if (ret != ans) {
                //cout << "EXPAND: " << ret << " " << ans << "\n";
                okay = false;
            }
				
			break;

		case CMD_CALCULATE:
			scanf("%d %d", &from, &to);
			ret = calculate(from, to);
			scanf("%d", &ans);
			if (ret != ans) {
                //cout << "CALC: " << ret << " " << ans << "\n";
                okay = false;
            }
				
			break;

		case CMD_DIVIDE:
			scanf("%d %d %d", &from, &to, &num);
			ret = divide(from, to, num);
			scanf("%d", &ans);
			if (ret != ans){
                //cout << "DIV: " << ret << " " << ans << "\n";
                okay = false;
            }
			break;

		default:
			okay = false;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}