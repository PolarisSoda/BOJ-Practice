#include <bits/stdc++.h>

using namespace std;

constexpr int LEN = 100001;
int pt[LEN],score[LEN],lazy[LEN];
vector<int> edge[LEN];

int root(int num) {
    if(pt[num] == num) return num;
    return pt[num] = root(pt[num]);
}

void init(int N) {
    for(int i=1; i<=N; i++) pt[i] = i, score[i] = 0, lazy[i] = 0, edge[i].clear(), edge[i].push_back(i);
}

void updateScore(int mWinnerID, int mLoserID, int mScore) {
    lazy[root(mWinnerID)] += mScore;
    lazy[root(mLoserID)] -= mScore;
}

void unionTeam(int mPlayerA, int mPlayerB) {
    int pa = root(mPlayerA);
    int pb = root(mPlayerB);
    if(edge[pa].size() < edge[pb].size()) swap(pa,pb);
    if(pa != pb) {
        int bias = lazy[pb] - lazy[pa];
        for(int p : edge[pb]) {
            score[p] += bias;
            edge[pa].push_back(p);
        }
    }
    pt[pb] = pa;
}

int getScore(int mID) {
    int parent = root(mID);
	return score[mID] + lazy[parent];
}