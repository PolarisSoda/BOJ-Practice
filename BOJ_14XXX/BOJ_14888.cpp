#include <bits/stdc++.h>

using namespace std;

// + - * /
struct info {
    int cnt[4];
};

int N;
int maxv = INT_MIN, minv = INT_MAX;
vector<int> V;

int calc(int A,int B,int type) {
    int ret = 0;
    switch(type) {
        case 0:
            ret = A + B;
            break;
        case 1:
            ret = A - B;
            break;
        case 2:
            ret = A * B;
            break;
        case 3:
            ret = A / B;
            break;
    }
    return ret;
}

void DFS(int idx,int now,info infos) {
    //idx와 idx+1간의 연산을 할 차례입니다.
    if(idx >= N) {
        maxv = max(maxv,now);
        minv = min(minv,now);
        return ;
    } else {
        for(int i=0; i<4; i++) {
            if(infos.cnt[i] > 0) {
                info next = infos;
                next.cnt[i]--;
                int ret = calc(now,V[idx],i);
                DFS(idx+1,ret,next);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    info init;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        V.push_back(temp);
    }
    for(int i=0; i<4; i++) cin >> init.cnt[i];

    DFS(1,V[0],init);

    cout << maxv << "\n" << minv;
    exit(0);
}