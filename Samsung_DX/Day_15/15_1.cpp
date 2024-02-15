#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

constexpr int LEN = 20001;
unordered_map<int,int> hs;
vector<pii> edge[LEN];
int cnt = 0;

void init(int N) {
    hs.clear();
    for(int i=0; i<=cnt; i++) edge[i].clear();
    cnt = 0;

    hs[N] = ++cnt;
}

int DFS(int P,int N,int O,int D) {
    if(N == O) return D;
    for(pii tt : edge[N]) {
        int next = tt.first;
        int d = tt.second;
        if(next != P) {
            int ret = DFS(N,next,O,D+d);
            if(ret != 0) return ret;
        }
    }
    return 0;
}

void connect(int O,int N,int D) {
    int idx_old = hs[O];
    int idx_new = hs[N] = ++cnt;

    edge[idx_old].push_back({idx_new,D});
    edge[idx_new].push_back({idx_old,D});
}

int measure(int mDevice1, int mDevice2) {
    int a = hs[mDevice1];
    int b = hs[mDevice2];
    return DFS(a,a,b,0);
}

int DFS2(int P,int N) {
    int ret = 0;
    for(pii tt : edge[N]) {
        int next = tt.first;
        int w = tt.second;
        if(next != P) ret = max(ret,DFS2(N,next)+w);
    }
    return ret;
}

int test(int mDevice) {
    int idx = hs[mDevice];
    int f = 0, s = 0;
    for(pii tt : edge[idx]) {
        int next = tt.first;
        int w = tt.second;
        int temp = DFS2(idx,next) + w;
        if(f < temp) s = f, f = temp;
        else if(s < temp) s = temp;
    }
    return f + s;
}
